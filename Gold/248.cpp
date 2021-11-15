/*
ID:azh248
LANG:C++
TASK:248 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n;

int arr[248];

int dp[248][248]; // dp[i][j] = greatest element in range(i, j)

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("248.in", "r", stdin);
	freopen("248.out", "w", stdout);
    cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int maxTotal = 0;
	for (int len = 1; len <= n; len++) {
		for (int i = 0; i + len <= n; i++) {
			int j = i + len - 1;
			if (i == j) {
				dp[i][j] = arr[i];
				continue;
			}
			for (int k = i; k < j; k++) {
				if (dp[i][k] == dp[k + 1][j] && dp[i][k] != -1) {
					dp[i][j] = max(dp[i][j], dp[i][k] + 1);
				}
			}
			maxTotal = max(maxTotal, dp[i][j]);
		}
	}
	cout << maxTotal << nl;
}
