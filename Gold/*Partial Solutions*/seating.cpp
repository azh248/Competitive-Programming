/*
ID:azh248
LANG:C++
TASK:seating 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

int n, m;

struct LazySegTree {
	vector<vector<int> > tree; // {prefix, suffix, max, left boundary, right boundary}
	vector<int> lazy;
	vector<int> left;
	vector<int> right;
	void init() {
		tree = vector<vector<int> >(4 * n);
		left = vector<int>(4 * n);
		right = vector<int>(4 * n);
		lazy = vector<int> (4 * n, 0);
		build(1, 0, n - 1);
	}
	void build(int v, int tl, int tr) {
		if (tl == tr) {
			tree[v] = {1, 1, 1};
			left[v] = tl;
			right[v] = tr;
		} else {
			int tm = (tl + tr) / 2;
			build(v * 2, tl, tm);
			build(v * 2 + 1, tm + 1, tr);
			tree[v] = {tree[v * 2][0] + tree[v * 2 + 1][0], tree[v * 2][1] + tree[v * 2 + 1][1], tree[v * 2][2] + tree[v * 2 + 1][2]};
			left[v] = left[v * 2];
			right[v] = right[v * 2 + 1];
		}
	}
	void push(int v) {
		if (lazy[v] == 1) {
			tree[v * 2][0] = tree[v * 2][1] = tree[v * 2][2] = 0;
			tree[v * 2 + 1][0] = tree[v * 2 + 1][1] = tree[v * 2 + 1][2] = 0;
			lazy[v * 2] = lazy[v];
			lazy[v * 2 + 1] = lazy[v];
		} else if (lazy[v] == -1) {
			tree[v * 2][0] = right[v * 2] - left[v * 2] + 1;
			tree[v * 2][1] = right[v * 2] - left[v * 2] + 1;
			tree[v * 2][2] = right[v * 2] - left[v * 2] + 1; 
			tree[v * 2 + 1][0] = right[v * 2 + 1] - left[v * 2 + 1] + 1;
			tree[v * 2 + 1][1] = right[v * 2 + 1] - left[v * 2 + 1] + 1;
			tree[v * 2 + 1][2] = right[v * 2 + 1] - left[v * 2 + 1] + 1;
			lazy[v * 2] = lazy[v];
			lazy[v * 2 + 1] = lazy[v];
		} 
		lazy[v] = 0;
	}
	void updateUtil(int v, int tl, int tr, int l, int r, int val) {
		if (l > r) {
			return;
		} else if (l == tl && r == tr) {
			lazy[v] = val;
			if (val == 1) {
				tree[v][0] = 0;
				tree[v][1] = 0;
				tree[v][2] = 0;
			} else {
				int nodeSize = right[v] - left[v] + 1;
				tree[v][0] = nodeSize;
				tree[v][1] = nodeSize;
				tree[v][2] = nodeSize;
			}
		} else {
			if (lazy[v] != 0) {
				push(v);
			}
			int tm = (tl + tr)/2;
			updateUtil(v * 2, tl, tm, l, min(r, tm), val);
			updateUtil(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
			// construct tree[v] based on tree[v * 2] and tree[v * 2] + 1
			if (tree[v * 2][1] == right[v * 2] - left[v * 2] + 1) {
				tree[v][0] = right[v * 2] - left[v * 2] + 1 + tree[v * 2 + 1][0];
			} else {
				tree[v][0] = tree[v * 2][0];
			}
			if (tree[v * 2 + 1][0] == right[v * 2 + 1] - left[v * 2 + 1] + 1) {
				tree[v][1] = right[v * 2 + 1] - left[v * 2 + 1] + 1 + tree[v * 2][1];
			} else {
				tree[v][1] = tree[v * 2 + 1][1];
			}
			tree[v][2] = max(max(tree[v][0], tree[v][1]), max(max(tree[v * 2][2], tree[v * 2 + 1][2]), tree[v * 2][1] + tree[v * 2 + 1][0]));
		}
	}
	void arrival(int v, int tl, int tr, int l, int r, int p) { // problem is the arrival is separated into several intervals; we don't know if the intervals 
		if (tl == tr) {
			updateUtil(1, 0, n - 1, tree[v][3], tree[v][4], 1);
		}
		if (lazy[v] != 0) {
			push(v);
		}
		int tm = (tl + tr)/2;
		if (tree[v * 2][2] >= p) {
			arrival(v * 2, tl, tm, l, min(tm, r), p);
		} else if (tree[v * 2][1] + tree[v * 2 + 1][0] >= p) {
			updateUtil(1, 0, n - 1, right[v * 2] - tree[v * 2][1] + 1, right[v * 2] - tree[v * 2][1] + p, 1);
		} else if (tree[v * 2 + 1][2] >= p) {
			arrival(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, p);
		} 
	}
};

int main() {
	freopen("seating.in", "r", stdin);
	freopen("seating.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	LazySegTree segTree;
	segTree.init();
	int turnedAway = 0;
	for (int i = 0; i < m; i++) {
		char ch; cin >> ch; 
		if (ch == 'A') {
			int partySize; cin >> partySize;
			if (segTree.tree[1][2] < partySize) {
				turnedAway++;
			} else {
				segTree.arrival(1, 0, n - 1, 0, n - 1, partySize);
			}
		} else {
			int a, b; cin >> a >> b; a--; b--;
			segTree.updateUtil(1, 0, n - 1, a, b, -1);
		}
	}
	cout << turnedAway << nl;
}
