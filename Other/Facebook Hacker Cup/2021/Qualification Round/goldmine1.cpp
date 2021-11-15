#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, t;
vector<int> adj[50];
int par[50];
ll gold[50];

void treeDfs(int node) {
	for (int i = 0; i < adj[node].size(); i++) {
		int child = adj[node][i];
		if (child == par[node]) {
			continue;
		}
		par[child] = node;
		treeDfs(child);
	}
}

ll maxPath(int node) {
	if (adj[node].size() == 1) {
		return gold[node];
	}
	ll path = 0;
	for (int i : adj[node]) {
		if (i != par[node]) {
			path = max(path, maxPath(i));
		}
	}
	path += gold[node];
	return path;
}

int main() {
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		// if cave 0 only has 1 neighbor, we take the highest value path and then drill back to 0
		// otherwise we go down the highest value subtree path, then drill to the bottom of the second highest value subtree path and go back to 0
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> gold[i];
			adj[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b; cin >> a >> b; a--; b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		treeDfs(0);
		ll ans;
		if (adj[0].size() == 0) {
			ans = gold[0];
		} else if (adj[0].size() == 1) {
			ans = maxPath(adj[0][0]) + gold[0];
		} else {
			int maxSubtree = 0;
			int secondMaxSubtree = 0;
			for (int i : adj[0]) {
				int path = maxPath(i);
				if (path > maxSubtree) {
					secondMaxSubtree = maxSubtree;
					maxSubtree = path;
				} else if (path > secondMaxSubtree) {
					secondMaxSubtree = path;
				}
			}
			ans = maxSubtree + secondMaxSubtree + gold[0];
		}
		cout << "Case #" << t1 << ": " << ans << nl;
	}
}