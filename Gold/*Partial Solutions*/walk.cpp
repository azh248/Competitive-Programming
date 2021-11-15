/*
ID: azh248
LANG: C++
TASK:walk 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back
#define long long long

int n, k;

vector<vector<ll> > edges;

bool cmp(vector<ll> a, vector<ll> b) {
	return a[2] > b[2];
}

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

DSU dsu;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
    cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			edges.pb({i, j, ((ll)2019201913 * (ll)(i + 1) + (ll)2019201949 * (ll)(j + 1)) % 2019201997});
		}
	}	
	sort(edges.begin(), edges.end(), cmp);
	int groups = n;
	dsu.init(n);
	while (groups > k) {
		vector<ll> edge = edges[edges.size() - 1];
		// while we have less than k groups, look at the two cows with the shortest distance: if they're already united, remove the edge,
		// otherwise unite them and remove the edge. 
		edges.pop_back();
		if (dsu.sameSet(edge[0], edge[1])) {
			continue;
		}
		groups--;
		dsu.unite(edge[0], edge[1]);
	}
	while (dsu.sameSet(edges[edges.size() - 1][0], edges[edges.size() - 1][1])) {
		edges.pop_back();
	}
	cout << edges[edges.size() - 1][2] << nl;
}
