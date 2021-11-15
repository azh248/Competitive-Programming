/*
ID: azh248
LANG: C++
TASK:fencedin
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back
#define long long long

int a, b, n, m;

vector<pair<pair<pii, pii>, int>>
	edges; // list of edges in the form pair<point1, point2>, length of wall
		   // between them

bool cmp(pair<pair<pii, pii>, int> a, pair<pair<pii, pii>, int> b) {
	return a.second < b.second;
}

vector<vector<pii>> p; // parent/size of set according to index in the grid

struct DSU {
	void init(int n, int m) {
		for (int i = 0; i < n; i++) {
			p.pb(vector<pii>(m, {-1, -1}));
		}
	}
	pii get(pii x) {
		return p[x.first][x.second].first < 0
				   ? x
				   : p[x.first][x.second] = get(p[x.first][x.second]);
	}
	bool sameSet(pii x, pii y) { return get(x) == get(y); }
	bool unite(pii x, pii y) {
		x = get(x);
		y = get(y);
		if (x == y) {
			return false;
		}
		if (p[x.first][x.second].first > p[y.first][y.second].first)
			swap(x, y);
		p[x.first][x.second].first += p[y.first][y.second].first;
		p[y.first][y.second] = x;
		return true;
	}
};

ll kruskals() { // O(mlogn)
	sort(edges.begin(), edges.end(), cmp);
	DSU dsu;
	dsu.init(m + 1, n + 1);
	ll weight = 0;
	for (int i = 0; i < edges.size(); i++) {
		pair<pair<pii, pii>, int> edge = edges[i];
		if (dsu.sameSet(edge.first.first, edge.first.second)) {
			continue;
		}
		dsu.unite(edge.first.first, edge.first.second);
		weight += edge.second;
	}
	return weight;
}

int verticalFences[2002];
int horizontalFences[2002];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> n >> m;

	verticalFences[0] = 0;
	verticalFences[n + 1] = a;
	horizontalFences[0] = 0;
	horizontalFences[m + 1] = b;
	for (int i = 1; i <= n; i++) {
		cin >> verticalFences[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> horizontalFences[i];
	}
	sort(verticalFences, verticalFences + n + 2);
	sort(horizontalFences, horizontalFences + m + 2);
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n;
			 j++) { // add right-left neighbors' fences as edges
			edges.pb({{{i, j}, {i, j + 1}},
					  horizontalFences[i + 1] - horizontalFences[i]});
		}
	}
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m; j++) { // add top-down neighbors' fences as edges
			edges.pb({{{j, i}, {j + 1, i}},
					  verticalFences[i + 1] - verticalFences[i]});
		}
	}
	cout << kruskals() << nl;
}