#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, q;

struct segTree { 
	vector<int> tree; // 1-indexed
	int len;
	void init(int initValue, vector<int> arr) { 
		while (arr.size() < ceil(log(arr.size())/log(2))) {
			arr.pb(initValue);
		}
		tree = vector<int>(2 * arr.size() - 2, -1); 
		len = arr.size() - 1;
		for (int i = len; i <= 2 * len - 1; i++) {
			tree[i] = arr[i - len + 1];
		}
		for (int i = len; i >= 1; i /= 2) {
			for (int j = i / 2; j < i; j++) {
				tree[j] = min(tree[2 * j], tree[2 * j + 1]);
			}
		}
	}
	int query(int a, int b) {
		a += len; 
		b += len; 
		int res = 1e9;
		while (a <= b) {
			if (a % 2 == 1) {
				res = min(res, tree[a++]); 
			}
			if (b % 2 == 0) {
				res = min(res, tree[b--]); 
			}
			a /= 2;
			b /= 2;
		}
		return res;
	}
	void update(int a, int b) {
		a += len;
		tree[a] = b;
		for (int i = a / 2; i >= 1; i /= 2) {
			tree[i] = min(tree[2 * i], tree[2 * i + 1]);
		}
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	vector<int> arr(n + 1, -1);
	segTree segtree;
	for (int i = 0; i < n; i++) {
		cin >> arr[i + 1];
	}	
	segtree.init(1e9, arr);
	for (int i = 0; i < q; i++) {
		int num;
		cin >> num;
		if (num == 1) {
			int a, b;
			cin >> a >> b;
			a--;
			segtree.update(a, b);
		} else {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			cout << segtree.query(a, b) << nl;
		}
	}
}