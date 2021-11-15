#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

ll n, a, b;

ll cows[2000];

ll dp[2000]; // minimum cost to cover all cows from i and above

ll minCost(int cow) {
	if (cow == n) {
		return 0;
	} else if (dp[cow] != -1) {
		return dp[cow];
	}
	ll cost = 1e9;

	for (int i = cow; i < n; i++) {
		cost = min(cost, minCost(i + 1) + a + b*(cows[i] - cows[cow]));
	}
	dp[cow] = cost;
	return cost;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("wifi.in", "r", stdin);
	freopen("wifi.out", "w", stdout);
	cin >> n >> a >> b;
	a *= 2;
	for (int i = 0; i < n; i++) {
		cin >> cows[i];	
	}	
	sort(cows, cows + n);
	memset(dp, -1, sizeof(dp));
	double cost = (double)minCost(0)/2;
	if (cost == floor(cost)) {
		cout << (ll)cost << nl;
	} else {
		cout << fixed << setprecision(1) << cost << nl;
	}
}
