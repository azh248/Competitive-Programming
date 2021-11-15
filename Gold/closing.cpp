/*
ID: azh248
LANG: C++
TASK:closing 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back
#define long long long

int n, m;
vector<int> adjLists[200000];

struct DSU {
	vector<int> p;
	void init(int n) { p = vector<int>(n, -1); }
	int get(int x) { return p[x] < 0 ? x : get(p[x]); }
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	cin >> n >> m;
	DSU dsu;
	dsu.init(n);
	unordered_set<int> openFarms;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adjLists[a].pb(b);
		adjLists[b].pb(a);
	}
	int farms[n];
	for (int i = 0; i < n; i++) {
		int farm;
		cin >> farm;
		farm--;
		farms[n - 1 - i] = farm;
	}
	bool ans[n];
	for (int i = 0; i < n; i++) {
		int farm = farms[i];
		openFarms.insert(farm);
		for (int j : adjLists[farm]) {
			if (openFarms.count(j) == 0) continue;
			dsu.unite(j, farm);
		}
		ans[i] = (dsu.size(*openFarms.begin()) == i + 1);
	}
	for (int i = n - 1; i >= 0; i--) {
		string pr = (ans[i]) ? "YES" : "NO";
		cout << pr << nl;
	}
}
