#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m, k;

ll dp[1000000][2]; // dp[i][j] = # of ways from location i onwards and if we've had a k long segment or not

ll numWays(int location, int hasKLong) { // we can basically just find how many ways we can form sequences of segments as long as one of them is at least length k
										 // because we can always have some series of stamps to get any sequence that we count
	if (location > n - k + 1 && hasKLong == 0) { // cannot have k long segment at any point
		return 0;
	} else if (location > n) { // overjumped
		return 0;
	} else if (location == n) { // working sequence
		return 1;
	} else if (dp[location][hasKLong] != -1) {
		return dp[location][hasKLong];
	}
	ll ways = 0;
	for (int i = 1; i < k; i++) { // segment of length under k; we can just move on with our location
		if (location == 0) {
			ways += (m) * numWays(location + i, hasKLong);	
		} else {
			ways += (m - 1) * numWays(location + i, hasKLong);
		}
		ways %= MOD;
	}
	for (int i = k; location + i - 1 <= n; i++) { // segment of length >= k; this sequence is therefore valid
		if (location == 0) {
			ways += (m) * numWays(location + i, 1);
		} else {
			ways += (m - 1) * numWays(location + i, 1);
		}
		ways %= MOD; 
	}
	dp[location][hasKLong] = ways;
	return ways;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("spainting.in", "r", stdin);
	freopen("spainting.out", "w", stdout);
	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));
	cout << numWays(0, 0) << nl; 
}
