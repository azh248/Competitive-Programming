/*
ID: azh248
LANG: C++
TASK:moocast 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back
#define long long long

int n;
vector<pii> coords;

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

int dist(pii a, pii b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool connected(int x) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			pii coords1 = coords[i];
			pii coords2 = coords[j];
			if (dist(coords1, coords2) <= x) {
				dsu.unite(i, j);
			}
		}
	}
	return (dsu.size(0) == n);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		coords.pb({a, b});
	}
	int l = 0;
	int r = 725000000;
	int ans = -1;
	int mid = (r + l) / 2;
	while (l <= r) {
		mid = (r + l) / 2;
		dsu.init(n);
		if (connected(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << nl;
}
