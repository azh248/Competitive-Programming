#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, k;
ll arr[300];

ll dp[300][300];

ll minCost(int i, int j) {
	if (i > j) {
		return 0;
	} else if (dp[i][j] != -1) {
		return dp[i][j];
	}
	ll initialCost = 0;
	for (int l = i + 1; l <= j; l++) {
		initialCost += arr[l] - arr[l - 1] - 1;
	}
	if (i > 0) {
		initialCost += arr[i] - arr[i - 1] - 1;
	} else {
		initialCost += arr[i] - 1;
	}
	if (j < k - 1) {
		initialCost += arr[j + 1] - arr[j] - 1;
	} else {
		initialCost += n - arr[k - 1];
	}
	initialCost += j - i + 1;
	ll cost = 1e18;
	for (int l = i; l <= j; l++) {
		ll newCost = minCost(i, l - 1) + minCost(l + 1, j);
		newCost += initialCost;
		cost = min(cost, newCost);
	}
	dp[i][j] = cost;
	return cost;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}	
	sort(arr, arr + k);	
	memset(dp, -1, sizeof(dp));
	cout << minCost(0, k - 1) << nl;
}
