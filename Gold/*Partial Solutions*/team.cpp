/*
ID:azh248
LANG:C++
TASK:team 
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

int n, m, k;
ll dp[1000][1000][10][2][2];

int cows1[1000];
int cows2[1000];

int winWays(int a, int b, int cow, int useA, int useB) {
	if (cow >= k) {
		return 1;
	} else if ((a < 0) || (b < 0)) {
		return 0;
	} else if (dp[a][b][cow][useA][useB] != -1) {
		return dp[a][b][cow][useA][useB];
	}
	ll ways = 0;
	if (cows1[a] > cows2[b]) {
		// cases:
		// 1. we use this pair in our teams
		// 2. we don't use either cow in this pair in either team
		// 3. we use fj's cow in the team, but not fj's
		// 4. we use fp's cow in the team, but not fp's
		ways += winWays(a - 1, b - 1, cow + 1, 0, 0);
		ways %= MOD;
		if (!useA && !useB) {
			ways += winWays(a - 1, b - 1, cow, 0, 0);
			ways %= MOD;
		}
		// forcing use of fj's or fp's cows so we don't overcount by doing a - 1 and then b - 1 which is equal to the above
		if (!useB) {
			ways += winWays(a, b - 1, cow, 1, 0);
			ways %= MOD;
		}
		if (!useA) {
			ways += winWays(a - 1, b, cow, 0, 1);
			ways %= MOD;
		}
	} else {
		if (useB) {
			return 0;
		}
		ways += winWays(a, b - 1, cow, 0, 0);
		ways %= MOD;
	}
	ways %= MOD;
	dp[a][b][cow][useA][useB] = ways;
	return ways;
}

int main() {
	freopen("team.in", "r", stdin);
	freopen("team.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> cows1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> cows2[i];
	}
	memset(dp, -1, sizeof(dp));
	ll ways = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (cows1[i] > cows2[j]) {
				ways += winWays(i - 1, j - 1, 1, 0, 0);
				ways %= MOD;
			}
		}
	}
	cout << ways << nl;
}
