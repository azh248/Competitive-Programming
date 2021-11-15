/*
ID:azh248
LANG:C++
TASK:cave 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

int n, m;

bool wall[1000][1000];
bool vis[1000][1000];
vector<pii> currVisited;
vector<pii> dsuAdj[1000][1000];

void ff(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m)
		return; // if outside grid
	if (wall[i][j])
		return; // wrong color
	if (vis[i][j])
		return;			  // already vis this square
	vis[i][j] = true; // mark current square asvis 
	currVisited.pb(pii(i, j));
	// recursively call floodfill for neighboring squares
	ff(i, j + 1);
	ff(i, j - 1);
	ff(i - 1, j);
	ff(i + 1, j);
}

bool cmp(pii a, pii b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

bool cmp1(pii a, pii b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

struct DSU {
	vector<vector<pii> > p;
	void init(int n, int m) { p = vector<vector<pii>>(n, vector<pii>(m, {-1, -1})); }
	pii get(int x1, int x2) { return p[x1][x2].first < 0 ? pii(x1, x2) : p[x1][x2] = get(p[x1][x2].first, p[x1][x2].second); }
	bool sameSet(int x1, int x2, int y1, int y2) { return get(x1, x2) == get(y1, y2); }
	int size(int x1, int x2) { return -1 * (p[get(x1, x2).first][get(x1, x2).second]).first; }
	bool unite(int x1, int x2, int y1, int y2) {
		pii x = pii(x1, x2);
		pii y = pii(y1, y2);
		if (x == y) {
			return false;
		}
		x = get(x.first, x.second);
		y = get(y.first, y.second);
		if (x == y) {
			return false;
		}
		if (p[x.first][x.second] > p[y.first][y.second]) {
			swap(x, y);
		}
		p[x.first][x.second].first += p[y.first][y.second].first;
		p[y.first][y.second] = x;
		return true;
	}
} dsu;

bool vis1[1000][1000];

ll colorWays(pii node) {
	vis1[node.first][node.second] = true;
	ll totalWays = 1;
	for (pii i : dsuAdj[node.first][node.second]) {
		if (!vis1[i.first][i.second]) {
			totalWays *= colorWays(i);
			totalWays %= MOD;
		}
	}
	totalWays++;
	totalWays %= MOD;
	return totalWays;
}

bool vis2[1000][1000];
vector<pii> parents[1000][1000];

void dfs1(pii node) {
	vis2[node.first][node.second] = true;
	for (pii i : dsuAdj[node.first][node.second]) {
		if (!vis2[i.first][i.second]) {
			if (i.first > node.first) {
				parents[i.first][i.second].pb(node);
			}
			dfs1(i);
			if (i.first < node.first) {
				parents[node.first][node.second].pb(i);
			}
		}
	}
}

int main() {
	freopen("cave.in", "r", stdin);
	freopen("cave.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '#') {
				wall[i][j] = true;
			}
		}
	}
	dsu.init(n, m);
	ll paintWays = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && !wall[i][j]) {
				ff(i, j);
				sort(currVisited.begin(), currVisited.end(), cmp);
				pii treeRoot = pii(1e9, 1e9);
				for (int k = 0; k < currVisited.size(); k++) {
					if (currVisited[k].first < treeRoot.first) {
						treeRoot = currVisited[k];
					}
					for (int l = k + 1; l < currVisited.size(); l++) {
						if (currVisited[k].first == currVisited[l].first && currVisited[l].second - currVisited[l - 1].second == 1) {
							dsu.unite(currVisited[k].first, currVisited[k].second, currVisited[l].first, currVisited[l].second);
						} else {
							k = l - 1;
							break;
						}
					}
				}
				sort(currVisited.begin(), currVisited.end(), cmp1);
				// ascend by depth; start from the bottom layer and move up
				// at each depth add the nodes to connected components; this ensures that 
				// any parents united previously would unite to the same nodes
				for (pii k : currVisited) {
					pii par1 = dsu.get(k.first, k.second);
					if (k.first > 0 && !wall[k.first - 1][k.second]) {
						pii par2 = dsu.get(k.first - 1, k.second);
						if (par1 != par2) {
							dsuAdj[par1.first][par1.second].pb(par2);
						}
					}
					if (k.first < n - 1 && !wall[k.first + 1][k.second]) {
						pii par2 = dsu.get(k.first + 1, k.second);
						if (par1 != par2) {
							dsuAdj[par1.first][par1.second].pb(par2);
						}
					}
					if (k.second > 0 && !wall[k.first][k.second - 1]) {
						pii par2 = dsu.get(k.first, k.second - 1);
						if (par1 != par2) {
							dsuAdj[par1.first][par1.second].pb(par2);
						}
					}
					if (k.second < m - 1 && !wall[k.first][k.second + 1]) {
						pii par2 = dsu.get(k.first, k.second + 1);
						if (par1 != par2) {
							dsuAdj[par1.first][par1.second].pb(par2);
						}
					}
				}
				// perform a dfs using the dsu adjacency list; for each node if it has > 1 parent unite them
				dfs1(treeRoot);
				for (int k = 0; k < currVisited.size(); k++) {
					int start = k;
					unordered_map<int, vector<int>> components;
					for (int l = k; l < currVisited.size(); l++) {
						if (currVisited[l].first == currVisited[k].first) {
							pii par = dsu.get(currVisited[l].first, currVisited[l].second);
							if (components.find(par.second) == components.end()) {
								components.insert(pair<int, vector<int>>(par.second, {currVisited[l].second}));
							} else {
								components[par.second].pb(currVisited[l].second);
							}
						} else {
							k = l - 1;
							break;
						}
					}
					for (auto l : components) {
						pii startPar = {-1, -1};
						for (int m : l.second) {
							if (parents[currVisited[start].first][m].size() > 0) {
								startPar = parents[currVisited[start].first][m][0];
								break;
							}
						}
						if (startPar == pii(-1, -1)) {
							continue;
						}
						for (int m : l.second) {
							for (pii n : parents[currVisited[start].first][m]) {
								dsu.unite(startPar.first, startPar.second, n.first, n.second);
							}
						}
					}
				}
				for (pii k : currVisited) {
					dsuAdj[k.first][k.second].clear();
				}
				
				for (pii k : currVisited) {
					pii par1 = dsu.get(k.first, k.second);
					if (k.first > 0 && !wall[k.first - 1][k.second]) {
						pii par2 = dsu.get(k.first - 1, k.second);
						if (par1 != par2) {
							dsuAdj[par1.first][par1.second].pb(par2);
						}
					}
					if (k.first < n - 1 && !wall[k.first + 1][k.second]) {
						pii par2 = dsu.get(k.first + 1, k.second);
						if (par1 != par2) {
							dsuAdj[par1.first][par1.second].pb(par2);
						}
					}
					if (k.second > 0 && !wall[k.first][k.second - 1]) {
						pii par2 = dsu.get(k.first, k.second - 1);
						if (par1 != par2) {
							dsuAdj[par1.first][par1.second].pb(par2);
						}
					}
					if (k.second < m - 1 && !wall[k.first][k.second + 1]) {
						pii par2 = dsu.get(k.first, k.second + 1);
						if (par1 != par2) {
							dsuAdj[par1.first][par1.second].pb(par2);
						}
					}
				}

				treeRoot = dsu.get(treeRoot.first, treeRoot.second);
				ll ways = colorWays(treeRoot);
				ways %= MOD;
				paintWays *= ways;
				paintWays %= MOD;
				currVisited = vector<pii>();
			}
		}
	}
	cout << paintWays << nl;
}
