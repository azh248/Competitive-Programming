#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back
#define long long long

ll dp[1000000]{};
ll arr[] = {1, 2, 3, 4, 5, 6};

ll sumWays(ll num) {
	if (num < 0) {
		return 0;
	} else if (num == 0) {
		return 1;
	} else if (dp[num] != 0) {
		return dp[num];
	}
	ll sum = 0;
	for (ll i : arr) {
		sum += sumWays(num - i);
		sum %= MOD;
	}
	dp[num] = sum;
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	cout << sumWays(n) << nl;
}
