/*
ID:azh248
LANG:C++
TASK:palpath 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;

int square[500][500];

// RIP recursive dp
// int palRoutes(int a, int b, int dist) {
// 	if (dp[a][b][dist] != -1) {
// 		return dp[a][b][dist];
// 	}
// 	// path that started at top left
// 	int x1 = dist - a; 
// 	int y1 = a;
// 	// path that started at bottom right
// 	int y2 = n - 1 - (dist - b);
// 	int x2 = n - 1 - (b);

// 	if (dist == n - 2) {
// 		if (((y1 == y2) && (x2 - x1 == 2)) || ((x1 == x2) && (y2 - y1 == 2))) { // they share a neighboring square
// 			dp[a][b][dist] = 1;
// 			return 1;
// 		} else if ((x2 - x1 == 1) && (y2 - y1 == 1)) { // they share 2 neighboring squares
// 			dp[a][b][dist] = 2;
// 			return 2;
// 		} else { // they don't share a neighboring square
// 			dp[a][b][dist] = 0;
// 			return 0;
// 		}
// 	}
// 	ll routes = 0;
// 	// next step for each path
// 	if (square[x1 + 1][y1] == square[x2][y2 - 1]) {
// 		routes += palRoutes(a, b, dist + 1);
// 		routes %= MOD;
// 	}
// 	if (square[x1][y1 + 1] == square[x2 - 1][y2]) {
// 		routes += palRoutes(a + 1, b + 1, dist + 1);
// 		routes %= MOD;
// 	}
// 	if (square[x1][y1 + 1] == square[x2][y2 - 1]) {
// 		routes += palRoutes(a + 1, b, dist + 1);
// 		routes %= MOD;
// 	}
// 	if (square[x1 + 1][y1] == square[x2 - 1][y2]) {
// 		routes += palRoutes(a, b + 1, dist + 1);
// 		routes %= MOD;
// 	}
// 	dp[a][b][dist] = (int)routes;
// 	return (int)routes;
// }

int main() {
	freopen("palpath.in", "r", stdin);
	freopen("palpath.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			square[i][j] = s[j] - 'A';
		}
	}
	ll prevDP[500][500];
	ll dp[500][500]; // dp[i][j] = the number of ways to make 2 paths meet up; the paths are currently dist away
					  // from (0, 0) and (n - 1, n - 1) respectively, and they're at the ith and jth index squares
					  // of that ddistance (squares are indexed from bottom left square to top right square)
					  // ex: in example input, the square with index 2 at distance 3 would be Z and the square with index 1 
					  // at distance 2 would be X
	for (int i = 0; i < n; i++) {
		prevDP[i][i] = 1;
	}
	for (int a = 0; a <= n - 2; a++) {
		for (int b = 0; b <= n - 2; b++) {
			// path that started at top left
			int x1 = n - 2 - a;
			int y1 = a;
			// path that started at bottom right
			int y2 = n - 1 - (n - 2 - b);
			int x2 = n - 1 - (b);

			if (square[x1][y1] != square[x2][y2]) {
				continue;
			}
			ll routes = 0;
			// next step for each path
			if ((x1 + 1 == x2) && (y1 == y2 - 1)) {
				routes += prevDP[a][b];
				routes %= MOD;
			}
			if ((x1 == x2 - 1) && (y1 + 1 == y2)) {
				routes += prevDP[a + 1][b + 1];
				routes %= MOD;
			}
			if ((x1 == x2) && (y1 + 1 == y2 - 1)) {
				routes += prevDP[a + 1][b];
				routes %= MOD;
			}
			if ((x1 + 1 == x2 - 1) && (y1 == y2)) {
				routes += prevDP[a][b + 1];
				routes %= MOD;
			}
			dp[a][b] = routes;
		}
	}
	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= n - 2; j++) {
			prevDP[i][j] = dp[i][j];
		}
	}
	for (int dist = n - 3; dist >= 0; dist--) {
		for (int a = 0; a <= dist; a++) {
			for (int b = 0; b <= dist; b++) {
				// path that started at top left
				int x1 = dist - a;
				int y1 = a;
				// path that started at bottom right
				int y2 = n - 1 - (dist - b);
				int x2 = n - 1 - (b);

				if (square[x1][y1] != square[x2][y2]) {
					continue;
				}
				ll routes = 0;
				// next step for each path
				if (square[x1 + 1][y1] == square[x2][y2 - 1]) {
					routes += prevDP[a][b];
					routes %= MOD;
				}
				if (square[x1][y1 + 1] == square[x2 - 1][y2]) {
					routes += prevDP[a + 1][b + 1];
					routes %= MOD;
				}
				if (square[x1][y1 + 1] == square[x2][y2 - 1]) {
					routes += prevDP[a + 1][b];
					routes %= MOD;
				}
				if (square[x1 + 1][y1] == square[x2 - 1][y2]) {
					routes += prevDP[a][b + 1];
					routes %= MOD;
				}
				dp[a][b] = routes;
			}
		}
		for (int i = 0; i <= dist; i++) {
			for (int j = 0; j <= dist; j++) {
				prevDP[i][j] = dp[i][j];
			}
		}
	}
	cout << dp[0][0] << nl;
}