#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, x;
int weight[20];

pii dp[1100000];

pii elevatorSubset(int subset) {
	if (subset == 0) {
		return {0, 0};
	} else if (dp[subset].first != -1) {
		return dp[subset];
	}
	pii optimalResult = {1e9, 1e9};
	for (int i = 0; i < n; i++) {
		if (subset & (1 << i)) {
			pii result = elevatorSubset(subset - (1 << i));
			if (weight[i] + result.second > x) {
				result.first++;
				result.second = weight[i];
			} else {
				result.second += weight[i];
			}
			if (result < optimalResult) {
				optimalResult = result;
			}
		}
	}
	dp[subset] = optimalResult;
	return optimalResult;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}	
	for (int i = 0; i < 1 << 20; i++) {
		dp[i] = {-1, -1};
	}
	cout << elevatorSubset((1 << n) - 1).first + 1 << nl;
}
