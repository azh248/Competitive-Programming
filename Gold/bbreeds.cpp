/*
ID:azh248
LANG:C++
TASK:bbreeds 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
string s;
int opens[1001];
int dp[1001][1000]; // dp[i][j] = # of ways starting from cow i given j current opens for a

int breedAssignments(int pos, int aOpens) {
	if (pos == n && aOpens == 0) {
		return 1;
	} else if (dp[pos][aOpens] != -1) {
		return dp[pos][aOpens];
	}
	int bOpens = (pos == 0 ? 0 : opens[pos - 1]) - aOpens;
	int assignments;
	if (s[pos] == '(') {
		assignments = (breedAssignments(pos + 1, aOpens + 1) + breedAssignments(pos + 1, aOpens)) % 2012;
	} else {
		assignments = (((bOpens > 0) ? breedAssignments(pos + 1, aOpens) : 0) + ((aOpens > 0) ? breedAssignments(pos + 1, aOpens - 1) : 0)) % 2012;
	}
	dp[pos][aOpens] = assignments;
	return assignments;
}

int main() {
	freopen("bbreeds.in", "r", stdin);
	freopen("bbreeds.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	n = s.length();
	opens[0] = ((s[0] == '(') ? 1 : -1);
	if (opens[0] < 0) {
		cout << 0 << nl;
		return 0;
	}
	for (int i = 1; i < n; i++) {
		opens[i] = opens[i - 1] + ((s[i] == '(') ? 1 : -1);
		if (opens[i] < 0) {
			cout << 0 << nl;
			return 0;
		}
	}
	if (opens[n - 1] != 0) {
		cout << 0 << nl;
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	cout << breedAssignments(0, 0) << nl;
}