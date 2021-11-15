#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

string s;

int sieveResult[10000000]{};

void sieve(int n) { // find all prime numbers up to n by marking the composite
					// numbers with their least prime factor
	for (int i = 2; i <= n; i++) {
		if (sieveResult[i] != 0)
			continue;
		for (int multiple = 2 * i; multiple <= n; multiple += i) {
			sieveResult[multiple] = i;
		}
	}
}

int dp[100000];

int minSplits(int pos) {
	if (pos > s.length()) {
		return 1e9;
	} else if (pos == s.length()) {
		return 0;
	} else if (dp[pos] != -1) {
		return dp[pos];
	}
	int splits = 1e9;
	int num = 0;
	for (int i = 1; i <= 7; i++) {
		num += s[pos + i - 1] - '0';
		if (sieveResult[num] == 0) {
			splits = min(splits, minSplits(pos + i));
		}
		num *= 10;
	}
	dp[pos] = splits;
	return splits;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	sieve(1e7);
	memset(dp, -1, sizeof(dp));
	cout << ((minSplits(0) >= 1e9) ? -1 : minSplits(0)) << nl;
}