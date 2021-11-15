#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, s;
vector<int> adj[100000];
int par[100000];
int maxLength;

pii dfs(int node) {
	if (adj[node].size() == 1 && node != 0) {
		return pii(1, 0);
	}
	vector<int> subtrees;
	int blockades = 0;
	for (int i : adj[node]) {
		if (i != par[node]) {
			par[i] = node;
			pii child = dfs(i);
			blockades += child.second;
			subtrees.pb(child.first);
		}
	}
	sort(subtrees.begin(), subtrees.end());
	int blockedSubtrees = 0;
	for (int i = 0; i < subtrees.size()/2; i++) {
		if (distance(upper_bound(subtrees.begin(), subtrees.end(), maxLength - subtrees[i]), subtrees.end()) > i) {
			blockedSubtrees = max(blockedSubtrees, (int) distance(lower_bound(subtrees.begin(), subtrees.end(), maxLength - subtrees[i]), subtrees.end()) - i);
		}
	}
	while (blockedSubtrees--) {
		blockades++;
		subtrees.pop_back();
	}
	if (subtrees.size() == 0) {
		return pii(1, blockades);
	}
	if (subtrees[subtrees.size() - 1] == maxLength && node != 0) {
		return pii(0, blockades + 1);
	}
	return pii(subtrees[subtrees.size() - 1] + 1, blockades);
}

int main() {
	freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	par[0] = -1;

	int l = 1;
	int r = n - 1;
	int ans = l - 1;
	while (l <= r) {
		int mid = (r + l) / 2;
		maxLength = mid;
		if (dfs(0).second <= s) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << nl;
}
