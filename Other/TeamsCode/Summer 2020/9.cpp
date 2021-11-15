#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n = 1e6 + 1;
int m;

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
	void push(int v) {
		tree[v * 2] = tree[v * 2] + lazy[v];
		lazy[v * 2] += lazy[v];
		tree[v * 2 + 1] = tree[v * 2 + 1] + lazy[v];
		lazy[v * 2 + 1] += lazy[v];
		lazy[v] = 0;
	}
	void update(int l, int r, int val) { updateUtil(1, 0, n - 1, l, r, val); }
	void updateUtil(int v, int tl, int tr, int l, int r, int val) {
		if (l > r) {
			return;
		} else if (l == tl && r == tr) {
			tree[v] = tree[v] + val;
			lazy[v] += val;
		} else {
			push(v);
			int tm = (tl + tr) / 2;
			updateUtil(v * 2, tl, tm, l, min(r, tm), val);
			updateUtil(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
			tree[v] = tree[v * 2] + tree[v * 2 + 1];
		}
	}
	int query(int l, int r) { return queryUtil(1, 0, n - 1, l, r); }
	int queryUtil(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return 0;
		} else if (l <= tl && r >= tr) {
			return tree[v];
		}
		push(v);
		int tm = (tl + tr) / 2;
		return queryUtil(v * 2, tl, tm, l, min(r, tm))
			+ queryUtil(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> m;
	LazySegTree segTree;
	segTree.init();
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		segTree.update(a, b, 1);
	}
	int maxNum = 0;
	for (int i = 0; i < n; i++) {
		maxNum = max(maxNum, segTree.query(i, i));
	}
}