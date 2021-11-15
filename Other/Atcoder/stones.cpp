#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, k;

int stones[101];

int dp[100001][2];

bool canWin(int pile, int player) {
	if (pile < 0) {
		return true;
	} else if (pile == 0) {
		return false;
	} else if (dp[pile][player] != -1) {
		return (dp[pile][player] == 1);
	}
	bool playerWin = false;
	for (int i = 0; i < n; i++) {
		if (!canWin(pile - stones[i], (player + 1) % 2)) {
			playerWin = true;
			break;
		}
	}
	dp[pile][player] = (playerWin ? 1 : 0);
	return playerWin;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> stones[i];
	}	
	for (int i = 0; i <= 100000; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = -1;
		}
	}
	cout << (canWin(k, 0) ? "First" : "Second") << nl;
}
