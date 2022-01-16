#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define pA first
#define pB second
#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
ll dp[265];
ll fish(int days) {
	if (days <= 0) {
		return 0;
	} else if (dp[days] != -1) {
		return dp[days];
	}
	if (days - 7 <= 0) {
		return 1;
	} else if (days - 9 <= 0) {
		return 2;
	}
	ll num = fish(days - 7) + fish(days - 9);
	dp[days] = num;
	return num;
}

int main() {
	freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int n = (s.length() + 1) / 2;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		nums.pb(s[2 * i] - '0');
	}
	memset(dp, -1, sizeof(dp));
	ll fishNum = 0;
	for (int i : nums) {
		fishNum += fish(256 + (7 - i));
	}
	cout << fishNum << nl;
}