#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;

int cost[10000];

vector<vector<int> > edges;

bool cmp(vector<int> a, vector<int> b) { return 2 * a[2] - cost[a[1]] - cost[a[0]] < 2 * b[2] - cost[b[0]] - cost[b[1]]; }

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

ll solve(int n) { // O(mlogn)
	sort(edges.begin(), edges.end(), cmp);
	DSU dsu;
	dsu.init(n);
	ll weight = 0;
	int minStart = 1e9;
	for (int i = 0; i < edges.size(); i++) {
		vector<int> edge = edges[i];
		if (dsu.sameSet(edge[0], edge[1])) {
			continue;
		}
		dsu.unite(edge[0], edge[1]);
		minStart = min(minStart, min(cost[edge[0]], cost[edge[1]]));
		weight += 2 * edge[2] - cost[edge[0]] - cost[edge[1]];
	}
	return weight + minStart;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b, L; cin >> a >> b >> L; a--; b--;
		edges.pb({a, b, L + cost[a] + cost[b]});
	}	
	cout << solve(n) << nl;
}
