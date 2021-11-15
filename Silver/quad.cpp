#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;

int dp[2500][4];

int numWays(int prevCut, int cuts) {
	if (cuts == 3) {
		if (prevCut == n) {
			return 0;
		} else if (n - prevCut >= ceil((double)(n)/2)) {
			return 0;
		}
		return 1;
	} else if (dp[prevCut][cuts] != -1) {
		return dp[prevCut][cuts];
	}
	int ways = 0;
	for (int i = prevCut + 1; i <= n; i++) {
		if (i - prevCut >= ceil((double)(n)/2)) {
			break;
		}
		ways += numWays(i, cuts + 1);
	}	
	dp[prevCut][cuts] = ways;
	return ways;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << numWays(0, 0) << nl;
}
