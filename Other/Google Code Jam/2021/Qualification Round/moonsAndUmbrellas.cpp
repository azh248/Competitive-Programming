#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t, x, y;

int dp[1000][2]; // dp[i][j] = min cost from index i onwards if the previous character was j (0 for C, 1 for J) 

string mural;

int minCost(int index, int prev) {
	if (index >= mural.length()) {
		return 0;
	} else if (mural[index] != '?') {
		int symbol = ((mural[index] == 'C') ? 0 : 1);
		if (index == 0) {
			return minCost(index + 1, symbol);
		}
		if (symbol == 0) {
			return minCost(index + 1, symbol) + ((prev == 1) ? y : 0);
		} else {
			return minCost(index + 1, symbol) + ((prev == 0) ? x : 0);
		}
	} else if (index == 0) {
		return min(minCost(index + 1, 0), minCost(index + 1, 1));
	} else if (dp[index][prev] != -1) {
		return dp[index][prev];
	}
	int cost;
	if (prev == 0) {
		cost = min(minCost(index + 1, 0), minCost(index + 1, 1) + x);
	} else {
		cost = min(minCost(index + 1, 0) + y, minCost(index + 1, 1));
	}
	dp[index][prev] = cost;
	return cost;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		cin >> mural;
		memset(dp, -1, sizeof(dp));
		cout << "Case #" << i + 1 << ": " << minCost(0, -1) << nl;
	}	
}
