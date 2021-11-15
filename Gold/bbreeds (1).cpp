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
#define nl "\n"; 
#define pb push_back

string parentheses;

int dp[1000][101][101]; // dp[i][j][i] = # of ways to assign breeds if we're up to cow i and we have j open left parentheses for holsteins and 
						// k open left parentheses for guernseys --> we can either pick a right parentheses for holsteins, for guernseys, 
						// which closes a left parentheses on each. We can also pick a left parentheses, which just adds 1 to the count 
						// that we're choosing

int breedWays(int cow, int holsteinL, int guernseyL) {
	if (cow == parentheses.length()) {
		return (holsteinL == 0 && guernseyL == 0) ? 1 : 0;
	} else if (holsteinL < 0 || guernseyL < 0 || holsteinL >= 101 || guernseyL >= 101) {
		return 0;	
	} else if (dp[cow][holsteinL][guernseyL] != -1) {
		return dp[cow][holsteinL][guernseyL];
	}
	int add = (parentheses[cow] == '(') ? 1 : -1;
	ll count = breedWays(cow + 1, holsteinL + add, guernseyL) + breedWays(cow + 1, holsteinL, guernseyL + add);
	count %= 2012;
	dp[cow][holsteinL][guernseyL] = count;
	return count; 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("bbreeds.in", "r", stdin);
	freopen("bbreeds.out", "w", stdout);
    cin >> parentheses;
	memset(dp, -1, sizeof(dp));
	cout << breedWays(0, 0, 0) << nl;
}
