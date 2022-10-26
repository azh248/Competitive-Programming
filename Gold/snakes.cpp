/*
ID:azh248
LANG:C++
TASK:snakes 
*/

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

int n, k;

int height[401];
int dp[400][400]; // dp[i][j] = // min wasted space starting with group i and j net
			 // changes; go through all possible sizes(i to n) and see how far
			 // you can catch snakes assuming you switch the size every time you
			 // run the dp(which is optimal)

int minWasted(int group, int changes) {
	if (group >= n) {
		return 0;
	} else if (changes > k) {
		return 1e9;
	} else if (dp[group][changes] != -1) {
		return dp[group][changes];
	}
	priority_queue<int, vector<int>, greater<int>> netSz;
	// see which net size is required to catch all snake groups from group to n, and add cost accordingly
	FOR(i, group, n) {
		netSz.push(height[i]);
	}
	int cost = 0;
	int minCost = 1e9;
	FOR(i, group, n) {
		cost += netSz.top() - height[i];
		while (netSz.top() < height[i]) {
			int prevBegin = netSz.top();
			netSz.pop();
			cost += (i - group + 1) * (netSz.top() - prevBegin);
		}
		minCost = min(minCost, cost + minWasted(i + 1, changes + 1));
	}
	minCost = min(minCost, cost);
	dp[group][changes] = minCost;
	return minCost;
}

int main() {
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}
	cout << minWasted(0, 0) << nl;
}
