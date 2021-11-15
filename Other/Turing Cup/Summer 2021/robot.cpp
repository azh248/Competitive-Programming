#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
int dp[1 << 18];
int d[18], k[18];

int maxScore(int mask) {
	if (dp[mask] != -1) {
		return dp[mask];
	} else if (mask == (1 << n) - 1) {
		return 0;
	}
	int loc = 0;
	for (int i = 0; i < n; i++) {
		if (mask & (1 << i)) {
			loc += d[i];
		}
	}
	int score = 0;
	for (int i = 0; i < n; i++) {
		if (!(mask & (1 << i))) {
			score = max(score, maxScore(mask + (1 << i)) + abs(2 * loc * k[i] + k[i] * d[i]));
		}
	}
	dp[mask] = score;
	return score;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i] >> k[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << maxScore(0) << nl;
}