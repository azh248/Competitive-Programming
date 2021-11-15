#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int candyOptions[50];
bool addCandy[400000]{};

int n, options, f, m;

int dp[400000];

int maxCandy(int candies) {
	if (candies < 0) {
		return -1 * 1e9;
	} else if (dp[candies] != -1) {
		return dp[candies];
	}
	int origCandies = candies;
	int maxCandyEaten = 0;	
	for (int i = 0; i < options; i++) {
		maxCandyEaten = max(maxCandyEaten, maxCandy(candies - candyOptions[i]) + candyOptions[i]);
	}
	while (addCandy[candies]) {
		candies += m;
		for (int i = 0; i < options; i++) {
			maxCandyEaten = max(maxCandyEaten, maxCandy(candies - candyOptions[i]) + candyOptions[i]);	
		}
	}
	dp[origCandies] = maxCandyEaten;
	dp[candies] = maxCandyEaten;
	return maxCandyEaten;
}

int dp1[40000];

bool sumM(int sum) {
	if (sum > m) {
		return false;
	} else if (sum == m) {
		return true;
	} else if (dp1[sum] != -1) {
		return (dp1[sum] == 1) ? true : false;
	}
	for (int i = 0; i < options; i++) {
		if (sumM(sum + candyOptions[i])) {
			dp1[sum] = 1;
			return true;
		}
	}
	dp1[sum] = 0;
	return false;
}

int dp2[2000000];
bool canGetBonus(int num) {
	if (num < 0) {
		return false;
	} else if (addCandy[num]) {
		return true;
	} else if (dp2[num] != -1) {
		return (dp2[num] == 1) ? true : false;
	}
	for (int i = 0; i < options; i++) {
		if (canGetBonus(num - candyOptions[i])) {
			dp2[num] = 1;
			return true;
		}
	}
	dp2[num] = 0;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> options >> f >> m;
	for (int i = 0; i < options; i++) {
		cin >> candyOptions[i];		
	}
	sort(candyOptions, candyOptions + options);	
	for (int i = 0; i < f; i++) {
		int a;
		cin >> a;
		addCandy[a] = true;
	}
	memset(dp, -1, sizeof(dp));
	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));
	if (sumM(0) && canGetBonus(n)) {
		cout << -1 << nl;
	} else {
		cout << maxCandy(n) << nl;
	}
}
