/*
ID:azh248
LANG:C++
TASK:taming 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n;

int arr[100];

int dp[100][101][101]; // dp[i][j][k] = min tampered from day i onwards if there's supposed to be j more breakouts and the last breakout was on day k

int minTampered(int day, int breakouts, int lastBreakout) {
	if (breakouts < 0) {
		return 1e9;
	} else if (day >= n) {
		return (breakouts == 0) ? 0 : 1e9;
	} else if (dp[day][breakouts][lastBreakout] != -1) {
		return dp[day][breakouts][lastBreakout]; 
	}
	// we can either breakout or not breakout (we can either tamper or not tamper with the current day's logs)
	int tampered = 1e9;
	if (arr[day] == day - lastBreakout) {
		tampered = min(tampered, minTampered(day + 1, breakouts - 1, day) + 1);	
		tampered = min(tampered, minTampered(day + 1, breakouts, lastBreakout));
	} else if (arr[day] == 0) {
		tampered = min(tampered, minTampered(day + 1, breakouts - 1, day));	
		tampered = min(tampered, minTampered(day + 1, breakouts, lastBreakout) + 1);
	} else {
		tampered = min(tampered, minTampered(day + 1, breakouts - 1, day) + 1);	
		tampered = min(tampered, minTampered(day + 1, breakouts, lastBreakout) + 1);
	}
	dp[day][breakouts][lastBreakout] = tampered;
	return tampered;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
    cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];		
	}	
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		cout << (minTampered(1, i - 1, 0) + ((arr[0] == 0) ? 0 : 1)) << nl;
	}
}
