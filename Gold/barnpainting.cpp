/*
ID:azh248
LANG:C++
TASK:barnpainting 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, k;

vector<int> adjLists[100000];

int colors[100000]{};

int dp[100000][4];

ll numWays(int node, int color, int parent) {
	if (colors[node] != 0) {
		if (colors[node] != color) {
			return 0;
		}
	} else if (dp[node][color] != -1) {
		return dp[node][color];
	}
	ll ways = 1;
	for (int i : adjLists[node]) {
		if (i != parent) {
			ways *= (numWays(i, color % 3 + 1, node) + numWays(i, (color + 1) % 3 + 1, node));
			ways %= MOD;
		}
	}
	dp[node][color] = ways;
	return ways;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("barnpainting.in", "r", stdin);
	freopen("barnpainting.out", "w", stdout);
    cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adjLists[a].pb(b);
		adjLists[b].pb(a);
	}
	for (int i = 0; i < k; i++) {
		int barn, color;
		cin >> barn >> color;
		barn--;
		colors[barn] = color;
	}
	memset(dp, -1, sizeof(dp));
	// just normally 3 color except if the barn is already painted then 
	// make it so that the barn has that color and make sure the parent has a different color
	cout << (numWays(0, 1, -1) + numWays(0, 2, -1) + numWays(0, 3, -1)) % MOD << nl;
}
