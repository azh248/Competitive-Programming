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
vector<int> adj[100000];
int topo[100000];
int curr;
bool topovis[100000];

void topodfs(int node) {
	topovis[node] = true;
	for (int i = 0; i < adj[node].size(); i++) {
		if (!topovis[adj[node][i]]) {
			topodfs(adj[node][i]);
		}
	}
	topo[--curr] = node;
}

void toposort() {
	curr = n;
	for (int i = 0; i < n; i++) {
		if (!topovis[i]) {
			topodfs(i);
		}
	}
}

ll dp[100000]{};

int completeWays(int level) {
	if (level == n - 1) {
		return 1;
	} else if (dp[level] != -1) {
		return dp[level];
	}
	ll ways = 0;
	for (int i : adj[level]) {
		ways += completeWays(i);
		ways %= MOD;
	}
	dp[level] = ways;
	return ways;
}

vector<int> adj1[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
		adj1[b].pb(a);
	}
	// memset(dp, -1, sizeof(dp));
	// cout << completeWays(0) << nl;
	toposort();
	dp[n - 1] = 1;
	for (int i = n - 1; i >= 0; i--) {
		int node = topo[i];
		dp[node] %= MOD;
		for (int j : adj1[node]) {
			dp[j] += dp[node];
			dp[j] %= MOD;
		}
	}
	cout << dp[0] << nl;
}
