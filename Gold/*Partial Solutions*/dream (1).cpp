/*
ID:azh248
LANG:C++
TASK:dream 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, m;

int dp[1000][1000][2][5]; // dp[i][j][k][l] = shortesst path to bottom right such that Bessie's at (i, j), Bessie 
						  // smells like oranges (k, 0 for false 1 for true), and the previous direction was l (0 
						  // for top, 1 for left, 2 for bottom, 3 for right)

bool visited[1000][1000][5]; // visited[i][j][k] = if (i, j) has been visited from direction k (same correspondence as above)

int arr[1000][1000];

int leastMoves(int i, int j, int oranges, int prevDirec) {
	if (i >= n || i < 0 || j >= m || j < 0) {
		return 1e9;
	} else if (arr[i][j] == 0 || (arr[i][j] == 3 && oranges == 0)) {
		return 1e9;
	} else if (i == n - 1 && j == m - 1) {
		return 0;
	} else if (visited[i][j][prevDirec]) {
		return 1e9;
	} else if (dp[i][j][oranges][prevDirec] != -1) {
		return dp[i][j][oranges][prevDirec];
	}
	// set a square to visited when you visit it, set it to false when you're done processing the neighbors
	visited[i][j][prevDirec] = true;
	int moves = 1e9;
	if (arr[i][j] == 1 || arr[i][j] == 3) { // for some reason the incorrect downwards thing still marks the thing as visited
		moves = min(moves, leastMoves(i + 1, j, oranges, 2) + 1);
		moves = min(moves, leastMoves(i - 1, j, oranges, 0) + 1);
		moves = min(moves, leastMoves(i, j + 1, oranges, 3) + 1);
		moves = min(moves, leastMoves(i, j - 1, oranges, 1) + 1);	
	} else if (arr[i][j] == 2) {
		moves = min(moves, leastMoves(i + 1, j, 1, 2) + 1);
		moves = min(moves, leastMoves(i - 1, j, 1, 0) + 1);
		moves = min(moves, leastMoves(i, j + 1, 1, 3) + 1);
		moves = min(moves, leastMoves(i, j - 1, 1, 1) + 1);		
	} else if (arr[i][j] == 4) {
		if (prevDirec == 0) {
			if (i - 1 < 0 || arr[i - 1][j] == 0 || arr[i - 1][j] == 3) {
				moves = min(moves, leastMoves(i + 1, j, 0, 2) + 1);
				moves = min(moves, leastMoves(i - 1, j, 0, 0) + 1);
				moves = min(moves, leastMoves(i, j + 1, 0, 3) + 1);
				moves = min(moves, leastMoves(i, j - 1, 0, 1) + 1);		
			} else {
				moves = min(moves, leastMoves(i - 1, j, 0, 0) + 1);
			}
		} else if (prevDirec == 1) {
			if (j - 1 < 0 || arr[i][j - 1] == 0 || arr[i][j - 1] == 3) {
				moves = min(moves, leastMoves(i + 1, j, 0, 2) + 1);
				moves = min(moves, leastMoves(i - 1, j, 0, 0) + 1);
				moves = min(moves, leastMoves(i, j + 1, 0, 3) + 1);
				moves = min(moves, leastMoves(i, j - 1, 0, 1) + 1);		
			} else {
				moves = min(moves, leastMoves(i, j - 1, 0, 1) + 1);
			}
		} else if (prevDirec == 2) {
			if (i + 1 >= n || arr[i + 1][j] == 0 || arr[i + 1][j] == 3) {
				moves = min(moves, leastMoves(i + 1, j, 0, 2) + 1);
				moves = min(moves, leastMoves(i - 1, j, 0, 0) + 1);
				moves = min(moves, leastMoves(i, j + 1, 0, 3) + 1);
				moves = min(moves, leastMoves(i, j - 1, 0, 1) + 1);		
			} else {
				moves = min(moves, leastMoves(i + 1, j, 0, 2) + 1);
			}	
		} else {
			if (j + 1 >= m || arr[i][j + 1] == 0 || arr[i][j + 1] == 3) {
				moves = min(moves, leastMoves(i + 1, j, 0, 2) + 1);
				moves = min(moves, leastMoves(i - 1, j, 0, 0) + 1);
				moves = min(moves, leastMoves(i, j + 1, 0, 3) + 1);
				moves = min(moves, leastMoves(i, j - 1, 0, 1) + 1);		
			} else {
				moves = min(moves, leastMoves(i, j + 1, 0, 3) + 1);
			}	
		}
	}
	visited[i][j][prevDirec] = false;
	dp[i][j][oranges][prevDirec] = moves;
	return moves;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
    cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}	
	memset(dp, -1, sizeof(dp));
	memset(visited, false, sizeof(visited));
	cout << (leastMoves(0, 0, 0, 4) >= 1e9 ? -1 : leastMoves(0, 0, 0, 4)) << nl;
}
