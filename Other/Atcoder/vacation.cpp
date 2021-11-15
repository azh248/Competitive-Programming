#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl endl
#define pb push_back
#define long long long

int n;
int dp[100000][3];
int happiness[100000][3];

int maxHappy(int day, int activity) {
	if (day == n) {
		return 0;
	} else if (dp[day][activity] != -1) {
		return dp[day][activity];
	}
	int happy = 0;
	for (int i = 1; i < 3; i++) {
		happy = max(happy, maxHappy(day + 1, (activity + i) % 3) + happiness[day][activity]);
	}
	dp[day][activity] = happy;
	return happy;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> happiness[i][0] >> happiness[i][1] >> happiness[i][2];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = -1;
		}
	}
	int ret = max(maxHappy(0, 0), max(maxHappy(0, 1), maxHappy(0, 2)));
	cout << ret << nl;
}
