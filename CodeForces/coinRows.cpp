#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int m; cin >> m;
		vector<ll> coins[2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < m; j++) {
				ll num; cin >> num; coins[i].pb(num);
			}
		}
		vector<ll> coinsSum0;
		vector<ll> coinsSum1;
		coinsSum0.pb(coins[0][0]);
		coinsSum1.pb(coins[1][m - 1]);
		for (int j = 1; j < m; j++) {
			coinsSum0.pb(coinsSum0[j - 1] + coins[0][j]);
			coinsSum1.pb(coinsSum1[j - 1] + coins[1][m - j - 1]);
		}
		ll minMax = 1e18; // alice can move down at any of the m columns; for each of these m columns, bob either wants to move down immediately or move down at the end
		// then, our result is the minimum max of bob's possible moves among all of alice's possible moves
		for (int i = 0; i < m; i++) {
			minMax = min(minMax, max(coinsSum1[m - 1] - coinsSum1[m - i - 1], coinsSum0[m - 1] - coinsSum0[i]));
		}
		cout << minMax << nl;
	}
}