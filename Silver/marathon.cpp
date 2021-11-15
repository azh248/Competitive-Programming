/*
ID: azh248
LANG: C++
TASK: marathon
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back
#define long long long

int n, k;
int dp[500][500]{}; // dp[i][j] = min distance given bessie is at checkpoint i and j skipped checkpoints already
vector<pii> checkpoints;

int minDist(int checkpoint, int skipped) {
	if (skipped > k) {
		return 1000000000;
	} else if (checkpoint == n - 1) {
		return 0;
	} else if (dp[checkpoint][skipped] != 0) {
		return dp[checkpoint][skipped];
	}
	int minimum = 1000000000;
	for (int i = checkpoint + 1; i < checkpoints.size(); i++) {
		minimum = min(minimum, (int) abs(checkpoints[i].first - checkpoints[checkpoint].first) + abs(checkpoints[i].second - checkpoints[checkpoint].second) + minDist(i, skipped + i - checkpoint - 1));
	}
	dp[checkpoint][skipped] = minimum;
	return minimum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		checkpoints.pb({x, y});
	}
	cout << minDist(0, 0) << nl;
}
