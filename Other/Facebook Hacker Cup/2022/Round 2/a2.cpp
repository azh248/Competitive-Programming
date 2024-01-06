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

int t;

struct SegTree {
	vector<int> tree;
	int n;
	void initStruct() {
		tree = vector<int>(4 * (1e6 + 1));
	}
	void init(vector<int> arr, int n) {
		this->n = n;
		build(arr, 1, 0, n - 1);
	}
	void build(vector<int> arr, int v, int tl, int tr) {
		if (tl == tr) {
			tree[v] = arr[tl];
		} else {
			int tm = (tl + tr) / 2;
			build(arr, v * 2, tl, tm);
			build(arr, v * 2 + 1, tm + 1, tr);
			tree[v] = tree[v * 2] + tree[v * 2 + 1];
		}
	}
	int query(int l, int r) {
		return queryUtil(1, 0, n - 1, l, r);
	}
	int queryUtil(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return 0;
		} else if (l == tl && r == tr) {
			return tree[v];
		}
		int tm = (tl + tr) / 2;
		return queryUtil(v * 2, tl, tm, l, min(r, tm)) + queryUtil(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	}
	void update(int pos, int val) {
		updateUtil(1, 0, n - 1, pos, val);
	}
	void updateUtil(int v, int tl, int tr, int pos, int val) {
		if (tl == tr) {
			tree[v] = val;
		} else {
			int tm = (tl + tr) / 2;
			if (pos <= tm) {
				updateUtil(v * 2, tl, tm, pos, val);
			} else {
				updateUtil(v * 2 + 1, tm + 1, tr, pos, val);
			}
			tree[v] = tree[v * 2] + tree[v * 2 + 1];
		}
	}
};
vector<int> prefixChars[26];
SegTree segs[26];

int main() {
    freopen("a2.in", "r", stdin);
    freopen("a2.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	FOR(i, 0, 26) {
		prefixChars[i] = vector<int>();
		segs[i].initStruct();
	}
	for (int t1 = 1; t1 <= t; t1++) {
		int n; cin >> n;
		string s;
		cin >> s;
		if (prefixChars[0].size() < s.size()) {
			F0R(i, 26) {
				while (prefixChars[i].size() < s.size()) {
					prefixChars[i].pb(0);
				}
			}
		}
		for (int j = 0; j < 26; j++) {
			prefixChars[0][j] = 0;
		}
		for (int i = 1; i <= s.length(); i++) {
			for (int j = 0; j < 26; j++) {
				prefixChars[i][j] = prefixChars[i - 1][j];
			}
			prefixChars[i][s[i - 1] - 'a']++;
		}
		F0R(i, 26) {
			segs[i].init(prefixChars[i], s.length() + 1);
		}
		int q; cin >> q;
		int cnt = 0;
		FOR(i, 0, q) {
			int l, r; cin >> l >> r;
			if ((r - l + 1) % 2 == 0) {
				continue;
			} else if ((r - l + 1) == 1) {
				cnt++;
				continue;
			}
			int half = l + (r - l) / 2;
			int extraChars1 = 0;
			int extraChars2 = 0;
			for (int j = 0; j < 26; j++) {
				// minimize the differences in characters between first half and second half
				int val1 = abs((segs[j].query(half, r) - segs[j].query(l, half - 1)));
				int val2 = abs((segs[j].query(half + 1, r) - segs[j].query(l, half)));
				extraChars1 += val1;
				extraChars2 += val2;
			}
			// cout << (to_string(extraChars1) + to_string(extraChars2)) << nl;
			if (min(extraChars1, extraChars2) <= 1) {
				cnt++;
			}
		}
		cout << "Case #" << t1 << ": " << cnt << nl;		
	}	
}