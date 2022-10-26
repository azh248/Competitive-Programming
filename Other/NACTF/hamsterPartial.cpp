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
int n, k, d;

vector<int> adj[100000];
int par[100000];

vector<int> subtreeInfo(int node) { // returns {subtree size, subtree depth,
									// number of cuts made}
	vector<vector<int> > children;
	int cuts = 0;
	int subtreeSize = 1;
	for (int i : adj[node]) {
		if (i == par[node]) {
			continue;
		}
		par[i] = node;
		vector<int> child = subtreeInfo(i);
		cuts += child[2];
		if (child[1] > d) { // subtree too deep, forced to cut
			cuts++;
			continue;
		}
		children.pb(child);
		subtreeSize += child[0];
	}
	sort(children.begin(), children.end());
	int currDepth = 0;
	for (int i = children.size() - 1; i >= 0; i--) {
		if (subtreeSize > k) {
			cuts++;
			subtreeSize -= children[i][0];
			children.pop_back();
		} else {
			currDepth = max(currDepth, children[i][1]);
		}
	}
	return vector<int>({subtreeSize, currDepth + 1, cuts});
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> k >> d;
		for (int i = 0; i < n; i++) {
			adj[i].clear();
			par[i] = -1;
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		cout << subtreeInfo(0)[2] << nl;
	}
}
