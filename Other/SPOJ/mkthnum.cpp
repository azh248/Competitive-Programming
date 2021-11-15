#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;

struct MergeSortTree {
	vector<vector<int> > tree;
	vector<int> arr = vector<int>(n);
	void init() {
		tree = vector<vector<int> >(4 * n);
		build(1, 0, n - 1);
	}
	void build(int v, int tl, int tr) {
		if (tl == tr) {
			tree[v].pb(arr[tl]);
			return;
		}
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		tree[v] = vector<int>(tr - tl + 1);
		merge(tree[v * 2].begin(), tree[v * 2].end(), tree[v * 2 + 1].begin(), tree[v * 2 + 1].end(), tree[v].begin());
	}
	int query1(int l1, int r1, int val) {
		int l = 0;
		int r = n - 1;
		int ans = -1;
		while (l <= r) {
			int mid = (r + l) / 2;
			int num = queryUtil(1, 0, n - 1, l1, r1, tree[1][mid]);
			if (num == val) {
				ans = mid;
				break;
			} else if (num > val) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return query(1, 0, n - 1, l1, r1, tree[1][ans]);
	}
	int query(int v, int tl, int tr, int l1, int r1, int val) { // compares elements in the range [l, r] to val
		if (l1 > r1) {
			return -1e9;
		} else if (l1 <= tl && r1 >= tr) {
			auto it = upper_bound(tree[v].begin(), tree[v].end(), val);
			if (it == tree[v].begin()) {
				return -1e9;
			}
			return *--it;
		}
		int tm = (tl + tr) / 2;
		return max(query(v * 2, tl, tm, l1, min(r1, tm), val), query(v * 2 + 1, tm + 1, tr, max(l1, tm + 1), r1, val));
	}
	int queryUtil(int v, int tl, int tr, int l, int r, int val) {
		if (l > r) {
			return 0;
		} else if (l <= tl && r >= tr) {
			auto it = upper_bound(tree[v].begin(), tree[v].end(), val);
			if (it == tree[v].begin()) {
				return 0;
			}
			int ret = distance(tree[v].begin(), --it) + 1;
			return ret;
		}
		int tm = (tl + tr) / 2;
		return queryUtil(v * 2, tl, tm, l, min(r, tm), val) + queryUtil(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
	}
};


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	MergeSortTree segTree;
	for (int i = 0; i < n; i++) {
		cin >> segTree.arr[i];
	}
	segTree.init();
	for (int i = 0; i < m; i++) {
		int l, r, k; cin >> l >> r >> k; l--; r--;
		cout << segTree.query1(l, r, k) << nl;
	}
}