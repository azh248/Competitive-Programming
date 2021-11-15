/*
ID: azh248
LANG: C++
TASK: hopscotch
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back
#define long long long

int r, c, k;
int grid[100][100]{};
int dp[100][100]{};

int numJumps(int i, int j) {
	if (i >= r || j >= c) {
		return 0;
	} else if (i == r - 1 && j == c - 1) {
		return 1;
	} else if (dp[i][j] != 0) {
		return dp[i][j];
	} 
	int sum = 0;
	for (int a = i + 1; a < r; a++) {
		for (int b = j + 1; b < c; b++) {
			if (grid[a][b] != grid[i][j]) {
				sum += numJumps(a, b);
				sum %= MOD;
			}
		}
	}
	dp[i][j] = sum;
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}
	cout << numJumps(0, 0) << nl;
}
