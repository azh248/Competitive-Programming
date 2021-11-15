#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back
#define long long long

bool hasTrap[1000][1000]{};
ll dp[1000][1000]{}; // dp[i][j] = number of paths to bottom right from (i, j)
ll n;

ll pathNumber(ll i, ll j) {
	if (i < 0|| j < 0 || hasTrap[i][j]) {
		return 0;
	} else if (dp[i][j] != 0) {
		return dp[i][j];
	}
	ll paths = pathNumber(i - 1, j) % MOD + pathNumber(i, j - 1) % MOD;
	dp[i][j] = paths;
	return paths;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			if (str[j] == '*') {
				hasTrap[i][j] = true;
			}
		}
	}
	dp[0][0] = 1;
	cout << pathNumber(n - 1, n - 1) << nl;
}
