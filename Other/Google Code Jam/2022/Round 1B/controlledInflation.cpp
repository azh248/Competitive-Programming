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

int n, p;
ll pressures[1000][100];
ll cost[1000];
ll dp[1005][2]; // dp[i][j] = min presses from customer i onwards if j represents if we ended the last customer at the highest (1) or lowest (0) pressure

ll minPresses(int i, bool prevOrder) {
	if (i == n) return 0;
	if (dp[i][prevOrder] != -1) return dp[i][prevOrder];
	ll res = 1e18;
	if (i == 0) {
		res = min(res, minPresses(i + 1, 0) + pressures[i][p - 1] + cost[i]);
		res = min(res, minPresses(i + 1, 1) + pressures[i][0] + cost[i]);
		dp[i][prevOrder] = res;
		return res;	
	}
	if (prevOrder) {
		res = min(res, minPresses(i + 1, 0) + abs(pressures[i - 1][p - 1] - pressures[i][p - 1]) + cost[i]);
		res = min(res, minPresses(i + 1, 1) + abs(pressures[i - 1][p - 1] - pressures[i][0]) + cost[i]);
	} else {
		res = min(res, minPresses(i + 1, 0) + abs(pressures[i - 1][0] - pressures[i][p - 1]) + cost[i]);
		res = min(res, minPresses(i + 1, 1) + abs(pressures[i - 1][0] - pressures[i][0]) + cost[i]);
	} 
	dp[i][prevOrder] = res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		cin >> n >> p;
		memset(dp, -1, sizeof(dp));
		FOR(i, 0, n) {
			FOR(j, 0, p) {
				cin >> pressures[i][j];
			}
			S0RT(pressures[i], p);
			ll currCost = 0;
			FOR(j, 0, p - 1) {
				currCost += abs(pressures[i][j + 1] - pressures[i][j]);
			}
			cost[i] = currCost;
		}
		ll presses = minPresses(0, 0);
		cout << "Case #" << t1 << ": " << presses << nl;		
	}	
}