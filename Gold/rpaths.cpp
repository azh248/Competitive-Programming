#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int f, r;
vector<pii> edges;

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
		if (p[x] > p[y]) {
			swap(x, y);
		}
		p[x] += p[y];
		p[y] = x;
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> f >> r;
	for (int i = 0; i < r; i++) {
		int a, b; cin >> a >> b; a--; b--;
		edges.pb({a, b});
	}
	unordered_set<int> bridges;
	for (int i = 0; i < r; i++) {
		DSU dsu;
		dsu.init(f);
		for (int j = 0; j < r; j++) {
			if (j != i) {
				dsu.unite(edges[j].first, edges[j].second);
			}
		}
		if (dsu.size(0) < f) {
			bridges.insert(i);
		}
	}
	DSU dsu;
	dsu.init(f);
	for (int i = 0; i < r; i++) {
		if (bridges.count(i) == 0) {
			dsu.unite(edges[i].first, edges[i].second);
		}
	}
	vector<int> adjLists[5000];
	for (int i = 0; i < r; i++) {
		if (bridges.count(i) == 1) {
			adjLists[dsu.get(edges[i].first)].pb(dsu.get(edges[i].second));
			adjLists[dsu.get(edges[i].second)].pb(dsu.get(edges[i].first));
		}
	}
	int leaves = 0;
	for (int i = 0; i < f; i++) {
		if (adjLists[i].size() == 1) {
			leaves++;
		}
	}
	cout << ceil((double)leaves/2) << nl;
}
