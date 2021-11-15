#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m, k, q;

int type[200000];
vector<vector<int>> initialEdges;

bool cmp(vector<int> a, vector<int> b) { return a[2] < b[2]; }

struct DSU {
	vector<int> p;
	void init(int n) { p = vector<int>(n, -1); }
	int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); }
	bool sameSet(int x, int y) { return get(x) == get(y); }
	int size(int x) { return -1 * p[get(x)]; }
	bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) {
			return false;
		}
		if (p[x] > p[y])
			swap(x, y);
		p[x] += p[y];
		p[y] = x;
		return true;
	}
};

vector<pii> mstAdj[200000];

void kruskals(int n) { // O(mlogn)
	sort(initialEdges.begin(), initialEdges.end(), cmp);
	DSU dsu;
	dsu.init(n);
	for (int i = 0; i < initialEdges.size(); i++) {
		vector<int> edge = initialEdges[i];
		if (dsu.sameSet(edge[0], edge[1])) {
			continue;
		}
		mstAdj[edge[0]].pb(pii(edge[1], edge[2]));
		mstAdj[edge[1]].pb(pii(edge[0], edge[2]));
		dsu.unite(edge[0], edge[1]);
	}
}

int par[200000];
int parLen[200000];

void treeDfs(int node) {
	for (int i = 0; i < mstAdj[node].size(); i++) {
		int child = mstAdj[node][i].first;
		if (child == par[node]) {
			continue;
		}
		par[child] = node;
		parLen[child] = mstAdj[node][i].second;
		treeDfs(child);
	}
}

multiset<int> minEdges;
multiset<int> localMinEdges[200000];
unordered_map<int, multiset<int>> colorKeys[200000];

int main() {
	freopen("grass.in", "r", stdin);
	freopen("grass.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k >> q;
	for (int i = 0; i < m; i++) {
		int a, b, l;
		cin >> a >> b >> l; a--; b--;
		initialEdges.pb({a, b, l});
	}
	for (int i = 0; i < n; i++) {
		cin >> type[i];
		type[i]--;
	}
	kruskals(n);
	par[0] = -1;
	treeDfs(0);
	for (int i = 0; i < n; i++) {
		int minEdge = 1e9;
		for (pii j : mstAdj[i]) {
			if (j.first == par[i]) {
				continue;
			}
			if (colorKeys[i].find(type[j.first]) != colorKeys[i].end()) {
				colorKeys[i][type[j.first]].insert(j.second);
				if (type[i] != type[j.first]) {
					minEdge = min(minEdge, j.second);
				}
			} else {
				colorKeys[i].insert(pair<int, multiset<int>>(type[j.first], {j.second}));
				if (type[i] != type[j.first]) {
					minEdge = min(minEdge, j.second);
				}
			}
		}
		minEdges.insert(minEdge);
		for (auto j : colorKeys[i]) {
			if (type[i] != j.first) {
				localMinEdges[i].insert(*j.second.begin());
			}
		}
	}
	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b; a--; b--;

		if (mstAdj[a].size() != 1 || a == 0) { 
			if (localMinEdges[a].size() > 0) {
				minEdges.erase(minEdges.find((*localMinEdges[a].begin())));
			}
			if (colorKeys[a].find(type[a]) != colorKeys[a].end() && colorKeys[a][type[a]].size() > 0) {
				localMinEdges[a].insert(*colorKeys[a][type[a]].begin());
			}
			if (colorKeys[a].find(b) != colorKeys[a].end() && colorKeys[a][b].size() > 0) {
				localMinEdges[a].erase(localMinEdges[a].find(*colorKeys[a][b].begin()));
			}
			if (localMinEdges[a].size() > 0) {
				minEdges.insert((*localMinEdges[a].begin()));
			}
		}

		if (a != 0) { // modifying the parent
			if (type[par[a]] == type[a]) {
				if (minEdges.find((*localMinEdges[par[a]].begin())) != minEdges.end()) {
					minEdges.erase(minEdges.find((*localMinEdges[par[a]].begin())));
				}
				
				// remove a from its origional color
				colorKeys[par[a]][type[a]].erase(colorKeys[par[a]][type[a]].find(parLen[a])); // we don't have to update localminedges since type[a] wasn't in it in the first place	

				// add a into its new color
				if (colorKeys[par[a]].find(b) != colorKeys[par[a]].end()) {
					localMinEdges[par[a]].erase(localMinEdges[par[a]].find(*colorKeys[par[a]][b].begin()));
					colorKeys[par[a]][b].insert(parLen[a]);
					localMinEdges[par[a]].insert(*colorKeys[par[a]][b].begin());				
				} else {
					colorKeys[par[a]].insert(pair<int, multiset<int>>(b, {parLen[a]}));
					localMinEdges[par[a]].insert(*colorKeys[par[a]][b].begin());
				}

				if (localMinEdges[par[a]].size() > 0) {
					minEdges.insert((*localMinEdges[par[a]].begin()));
				}
			} else if (type[par[a]] == b) {
				if (minEdges.find((*localMinEdges[par[a]].begin())) != minEdges.end()) {
					minEdges.erase(minEdges.find((*localMinEdges[par[a]].begin())));
				}

				// remove a from its original color
				localMinEdges[par[a]].erase(localMinEdges[par[a]].find(*colorKeys[par[a]][type[a]].begin()));
				colorKeys[par[a]][type[a]].erase(colorKeys[par[a]][type[a]].find(parLen[a]));
				if (colorKeys[par[a]][type[a]].size() > 0) {
					localMinEdges[par[a]].insert(*colorKeys[par[a]][type[a]].begin());
				}

				// add a into its new color
				colorKeys[par[a]][b].insert(parLen[a]); // we don't have to update localminedges since color b wasn't in it in the first place

				if (localMinEdges[par[a]].size() > 0) {
					minEdges.insert((*localMinEdges[par[a]].begin()));
				}
			} else {
				if (minEdges.find((*localMinEdges[par[a]].begin())) != minEdges.end()) {
					minEdges.erase(minEdges.find((*localMinEdges[par[a]].begin())));
				}

				// remove a from its origional color
				localMinEdges[par[a]].erase(localMinEdges[par[a]].find(*colorKeys[par[a]][type[a]].begin()));
				colorKeys[par[a]][type[a]].erase(colorKeys[par[a]][type[a]].find(parLen[a]));
				if (colorKeys[par[a]][type[a]].size() > 0) {
					localMinEdges[par[a]].insert(*colorKeys[par[a]][type[a]].begin());
				}

				// add a into its new color
				if (colorKeys[par[a]].find(b) != colorKeys[par[a]].end()) {
					localMinEdges[par[a]].erase(localMinEdges[par[a]].find(*colorKeys[par[a]][b].begin()));
					colorKeys[par[a]][b].insert(parLen[a]);
					localMinEdges[par[a]].insert(*colorKeys[par[a]][b].begin());				
				} else {
					colorKeys[par[a]].insert(pair<int, multiset<int>>(b, {parLen[a]}));
					localMinEdges[par[a]].insert(*colorKeys[par[a]][b].begin());
				}

				if (localMinEdges[par[a]].size() > 0) {
					minEdges.insert((*localMinEdges[par[a]].begin()));
				}
			}
		}

		type[a] = b;
		cout << *minEdges.begin() << nl;
	}
}