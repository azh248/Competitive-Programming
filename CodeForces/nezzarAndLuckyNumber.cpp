#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back
#define long long long

int t;

vector<int> dp;

bool canSum(vector<int> luckyNumbers, int num) {
	if (num < 0) {
		return false;
	} else if (num == 0) {
		return true;
	} else if (dp[num] != -1) {
		return (dp[num] == 1) ? true : false;
	}
	for (int i : luckyNumbers) {
		if (canSum(luckyNumbers, num - i)) {
			dp[num] = 1;
			return true;
		}
	}
	dp[num] = 0;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 0; t1 < t; t1++) {
		int q, d;
		cin >> q >> d;
		dp = vector<int>(200, -1);
		for (int i = 0; i < 200; i++) {
			dp[i] = -1;
		}
		vector<int> luckyNumbers;
		for (int i = 0; i < 20; i++) {
			luckyNumbers.pb(10*i + d);
		}
		for (int i = 0; i < 10; i++) {
			luckyNumbers.pb(10*d + i);
		}
		for (int i = 0; i < q; i++) {
			ll num;
			cin >> num;
			if (num >= 144) {
				cout << "YES" << nl;
			} else {
				cout << (canSum(luckyNumbers, num) ? "YES" : "NO") << nl;
			}
		}
	}	
}