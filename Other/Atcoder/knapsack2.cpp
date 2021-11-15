#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back
#define long long long

int n, w;
int dp[101][100001]; // dp[i][j] = minimum weight using all except the first i items to get a value of j
int items[101][2];

int minWeight(int num, int value) {
	if (value == 0) {
		return 0;
	} else if (num >= n || value < 0) {
		return 1e9 + 1;
	} else if (dp[num][value] != -1) {
		return dp[num][value];
	}
	int weight = min(minWeight(num + 1, value), minWeight(num + 1, value - items[num][1]) + items[num][0]);
	dp[num][value] = weight;
	return weight;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> items[i][0] >> items[i][1];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 100000; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i <= 100000; i++) {
		minWeight(0, i);
	}
	int maxValue = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 100000; j++) {
			if (dp[i][j] <= w) {
				maxValue = max(maxValue, j);
			}
		}
	}
	cout << maxValue << nl;
}
