/*
ID:azh248
LANG:C++
TASK:haybales 
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

int n, q;

struct LazySegTree {
	vector<ll> tree; // 1-indexed
	vector<ll> treeSum;
	vector<ll> lazy;
	void init(int arr[]) {
		tree = vector<ll>(4 * n, 0);
		treeSum = vector<ll>(4 * n, 0);
		lazy = vector<ll>(4 * n, 0);
		build(arr, 1, 0, n - 1);
	}
	void build(int arr[], int v, int tl, int tr) {
		if (tl == tr) {
			tree[v] = arr[tl];
			treeSum[v] = arr[tl];
		} else {
			int tm = (tl + tr) / 2;
			build(arr, v * 2, tl, tm);
			build(arr, v * 2 + 1, tm + 1, tr);
			tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
			treeSum[v] = treeSum[v * 2] + treeSum[v * 2 + 1];
		}
	}
	void push(int v, int l, int r, int tm) {
		tree[v * 2] = tree[v * 2] + lazy[v];
		treeSum[v * 2] = treeSum[v * 2] + (ll) (min(r, tm) - l + 1) * lazy[v];
		lazy[v * 2] += lazy[v];
		tree[v * 2 + 1] = tree[v * 2 + 1] + lazy[v];
		treeSum[v * 2 + 1] = treeSum[v * 2 + 1] + (ll) (r - max(l, tm + 1) + 1) * lazy[v];
		lazy[v * 2 + 1] += lazy[v];
		lazy[v] = 0;
	}
	void update(int l, int r, int val) { updateUtil(1, 0, n - 1, l, r, val); }
	void updateUtil(int v, int tl, int tr, int l, int r, int val) {
		if (l > r) {
			return;
		} else if (l == tl && r == tr) {
			tree[v] = tree[v] + val;
			treeSum[v] = treeSum[v] + (ll) (r - l + 1) * val;
			lazy[v] += val;
		} else {
			int tm = (tl + tr) / 2;
			push(v, tl, tr, tm);

			updateUtil(v * 2, tl, tm, l, min(r, tm), val);
			updateUtil(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
			tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
			treeSum[v] = treeSum[v * 2] + treeSum[v * 2 + 1];
		}
	}
	int query(int l, int r) { return queryUtil(1, 0, n - 1, l, r); }
	int queryUtil(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return 1e9;
		} else if (l <= tl && r >= tr) {
			return tree[v];
		}
		int tm = (tl + tr) / 2;
		push(v, tl, tr, tm);
		return min(queryUtil(v * 2, tl, tm, l, min(r, tm)), queryUtil(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
	}
	ll querySum(int l, int r) { return querySumUtil(1, 0, n - 1, l, r); }
	ll querySumUtil(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return 0;
		} else if (l <= tl && r >= tr) {
			return treeSum[v];
		}
		int tm = (tl + tr) / 2; 
		push(v, tl, tr, tm);
		return querySumUtil(v * 2, tl, tm, l, min(r, tm)) + querySumUtil(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	}
};
int arr[200000];

int main() {
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	LazySegTree segTree;
	segTree.init(arr);
	for (int i = 0; i < q; i++) {
		char ch;
		cin >> ch;
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if (ch == 'M') {
			cout << segTree.query(a, b) << nl;
		} else if (ch == 'S') {
			cout << segTree.querySum(a, b) << nl;
		} else {
			int c;
			cin >> c;
			segTree.update(a, b, c);
		}
	}
}
