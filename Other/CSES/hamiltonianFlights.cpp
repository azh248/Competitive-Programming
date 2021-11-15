#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;

vector<int> adjLists[20];

ll dp[1 << 20][20];

ll numWays(int citiesPassed, int city) {
	if (citiesPassed == (1 << n) - 1) {
		return (city == n - 1);
	} else if (citiesPassed & (1 << n - 1)) {
		return 0;
	} else if (dp[citiesPassed][city] != -1) {
		return dp[citiesPassed][city];
	}
	ll ways = 0;
	for (int i : adjLists[city]) {
		if (!(citiesPassed & (1 << i))) {
			ways += numWays(citiesPassed + (1 << i), i);
			ways %= MOD;
		}
	}
	dp[citiesPassed][city] = ways;
	return ways;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adjLists[a].pb(b);
	}	
	memset(dp, -1, sizeof(dp));
	cout << numWays(0 + (1 << 0), 0) << nl;
}
