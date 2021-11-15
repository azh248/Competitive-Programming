#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 1000000007
#define nl endl
#define pub push_back
#define pob pop_back

struct DSU {
	vector<int> p;
	void init(int n) { p = vector<int>(n, -1); }
	int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
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
	int n, m;
	cin >> n >> m;
	DSU dsu;
	dsu.init(n);
	int largest = 1;
	int number = n;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if (!dsu.sameSet(a, b)) {
			number--;
			int size1 = dsu.size(a);
			int size2 = dsu.size(b);
			dsu.unite(a, b);
			largest = max(largest, size1 + size2);
		}
		cout << number << " " << largest << nl;
	}
}
