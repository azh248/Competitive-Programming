#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

ll modpower(ll x, ll pow,
			ll mod) { // x^pow mod (mod) in O(logn) time, recursive
	if (pow == 0) {
		return 1 % mod;
	}
	ll ret = modpower(x, pow / 2, mod);
	ret = (ret * ret) % mod;
	if (pow % 2 == 1) {
		ret = (ret * x) % mod;
	}
	return ret;
}

struct DSU {
	vector<int> p;
	int amt = 0;
	void init(int n) { 
		p = vector<int>(n, -1); 
		amt = 0;
	}
	int get(int x) { 
		return p[x] < 0 ? x : p[x] = get(p[x]);
	}
	bool sameSet(int x, int y) {
		return get(x) == get(y);
	}
	int size(int x) {
		return -1 * p[get(x)]; 
	}
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
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		DSU dsu;
		dsu.init(n);
		int pair[400000];
		pii arr[400000];
		ll numWays = 1;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].first;
			arr[i].first--;
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[i].second;
			arr[i].second--;
		}
		for (int i = 0; i < n; i++) {
			pair[arr[i].first] = arr[i].second;
		}
		for (int i = 0; i < n; i++) {
			if (dsu.p[i] == -1) {
				int num = pair[i];
				dsu.amt++;
				while (num != i) {
					dsu.unite(i, num);
					num = pair[num];
				}	
			}
		}
		cout << modpower(2, (ll)dsu.amt, MOD) << nl;
	}
}