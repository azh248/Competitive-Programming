#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back
#define long long long

int dp[1000000]{}; // steps to end

int minSteps(int num) {
	if (num < 0) {
		return 1000000000;
	} else if (num == 0) {
		return 0;
	} else if (dp[num] != 0) {
		return dp[num];
	}
	string str = to_string(num);
	int minNum = 1000000000;
	for (int i = 0; i < str.length(); i++) {
		if (stoi(string(1, str[i])) == 0) {
			continue;
		}
		minNum = min(minNum, minSteps(num - stoi(string(1, str[i]))) + 1);
	}
	dp[num] = minNum;
	return minNum;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << minSteps(n) << nl;
}
