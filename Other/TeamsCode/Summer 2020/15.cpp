#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, s;
int amt[15];
int volume[15];

ll dp[15][300];

ll numWays(int boxNum, int remPitcherSize) {
	if (boxNum == n) {
		if (remPitcherSize == 0) {
			return 1;
		} else {
			return 0;
		}
	} else if (dp[boxNum][remPitcherSize] != -1) {
		return dp[boxNum][remPitcherSize];
	}
	ll totalWays = 0;
	for (int i = 1; i <= amt[boxNum]; i++) {
		totalWays += numWays(boxNum + 1, remPitcherSize - volume[boxNum] * i);
	}
	dp[boxNum][remPitcherSize] = totalWays;
	return totalWays;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> amt[i] >> volume[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << numWays(0, s) << nl;
}