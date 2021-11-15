/*
ID:azh248
LANG:C++
TASK:guard 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, h;

ll cows[20][3];

ll dp[1100000]; // dp[mask] = max safety factor for subset mask
				// try removing each cow from the mask, subtract weight of that cow from dp[new mask] --> take max of 
				// all of these possible removals

ll maxSafety(int mask) {
	if (dp[mask] != -1) {
		return dp[mask];
	}
	// if there's only one cow, we can just return the safety factor of that cow
	vector<int> maskCows;
	for (int i = 0; i < n; i++) {
		if (mask & (1 << i)) {
			maskCows.pb(i);
		}
	}
	if (maskCows.size() == 1) {
		dp[mask] = cows[maskCows[0]][2];
		return cows[maskCows[0]][2];
	} 
	ll safety = -1 * 1e18;
	for (int i = 0; i < n; i++) {
		if (mask & (1 << i)) {
			safety = max(safety, min(maxSafety(mask - (1 << i)) - cows[i][1], cows[i][2]));
		}
	}
	dp[mask] = safety;
	return safety;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
    cin >> n >> h;
	for (int i = 0; i < n; i++) {
		cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
	}
	memset(dp, -1, sizeof(dp));
	ll maxSafetyFactor = -1;	
	for (int i = 0; i < (1 << n); i++) {
		ll height = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				height += cows[j][0];
			}
		}
		if (height < h) {
			continue;
		}
		ll safetyFactor = maxSafety(i);
		if (safetyFactor < 0) {
			continue;
		}
		maxSafetyFactor = max(maxSafetyFactor, safetyFactor);
	}
	if (maxSafetyFactor == -1) {
		cout << "Mark is too tall" << nl;
	} else {
		cout << maxSafetyFactor << nl;
	}
}
