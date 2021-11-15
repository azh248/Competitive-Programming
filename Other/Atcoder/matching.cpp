#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
int arr[21][21];

ll dp[21][1 << 21];

ll numWays(int man, int state) {
	if (man >= n) {
		return 1;
	} else if (dp[man][state] != -1) {
		return dp[man][state];
	}
	ll ways = 0;
	for (int i = 0; i < n; i++) {
		if (!(state & (1 << i)) && arr[man][i] == 1) {
			ways += numWays(man + 1, state + (1 << i));
			ways %= MOD;
		}
	}
	dp[man][state] = ways;
	return ways;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}			
	}	
	memset(dp, -1, sizeof(dp));
	cout << numWays(0, 0) << nl;
}
