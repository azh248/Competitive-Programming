/*
ID:azh248
LANG:C++
TASK:lites 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define F0R1(i, a) for (int i = 1; i <= (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i = a; i > 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())
#define S0RT(arr, n) sort(arr, arr + n)

#define pA first
#define pB second
#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;

struct LazySegTree {
	vector<int> tree; // 1-indexed
	vector<int> lazy;
	void init() {
		tree = vector<int>(4 * n, 0);
		lazy = vector<int>(4 * n, 0);
		build(1, 0, n - 1);
	}
	void build(int v, int tl, int tr) {
		if (tl == tr) {
			tree[v] = 0;
		} else {
			int tm = (tl + tr) / 2;
			build(v * 2, tl, tm);
			build(v * 2 + 1, tm + 1, tr);
			tree[v] = tree[v * 2] + tree[v * 2 + 1];
		}
	}
	void push(int v, int tl, int tr, int tm) {
		lazy[v] %= 2;
		if (lazy[v] == 1) {
			lazy[v * 2] += lazy[v];
			lazy[v * 2] %= 2;
			lazy[v * 2 + 1] += lazy[v];
			lazy[v * 2 + 1] %= 2;
			lazy[v] = 0;
			tree[v * 2] = (min(tr, tm) - tl + 1) - query(tl, min(tr, tm));
			tree[v * 2 + 1] = (tr - max(tl, tm + 1) + 1) - query(max(tl, tm + 1), tr);
		}
	}
	void update(int l, int r) {
		updateUtil(1, 0, n - 1, l, r);
	}
	void updateUtil(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return;
		} else if (l == tl && r == tr) {
			tree[v] = (r - l + 1) - query(l, r);
			lazy[v]++;
			lazy[v] %= 2;
		} else {
			int tm = (tl + tr) / 2;
			push(v, tl, tr, tm); // uses t versions of (l, r, m) because we need the entire range to add val to
			updateUtil(v * 2, tl, tm, l, min(r, tm));
			updateUtil(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
			tree[v] = tree[v * 2] + tree[v * 2 + 1];
		}
	}
	int query(int l, int r) {
		return queryUtil(1, 0, n - 1, l, r);
	}
	int queryUtil(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return 0;
		} else if (l <= tl && r >= tr) {
			return tree[v];
		}
		int tm = (tl + tr) / 2;
		push(v, tl, tr, tm);
		return queryUtil(v * 2, tl, tm, l, min(r, tm)) + queryUtil(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	}
};





int main() {
	freopen("lites.in", "r", stdin);
	freopen("lites.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	LazySegTree segTree;
	segTree.init();
	// toggle makes it so that the sum in a range is (size of range) - query(range)
	// 2 toggles are the equivalent of no toggles, so if you do 2 toggles in the same lazy you can just mod 2
	for (int i = 0; i < m; i++) {
		int cmd, s, e;
		cin >> cmd >> s >> e;
		s--; e--;
		if (cmd) {
			cout << segTree.query(s, e) << nl;
		} else {
			segTree.update(s, e);
		}
	}
}
