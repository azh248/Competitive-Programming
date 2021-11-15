/*
ID:azh248
LANG:C++
TASK:modernArt3 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

int n;
int arr[300];
vector<int> locations[300];

int dp[300][300][300]; // dp[i][j] = minimum brush strokes in the range (i, j) with base color k

int minStrokes(int i, int j, int k) {
	if (i > j) {
		return 0;
	} else if (arr[i] == k) {
		return minStrokes(i + 1, j, k);
	} else if (i == j) {
		return 1;
	} else if (dp[i][j][k] != -1) {
		return dp[i][j][k];
	}
	int color = arr[i];
	int strokes = minStrokes(i + 1, j, k) + 1;
	for (int l : locations[arr[i]]) {
		if (l > i) {
			strokes = min(strokes, minStrokes(i + 1, l - 1, arr[i]) + minStrokes(l + 1, j, k) + 1);
		}
	}
	dp[i][j][k] = strokes;
	return strokes;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (locations[arr[i]].size() == 0) {
			for (int j = i; j < n; j++) {
				if (arr[j] == arr[i]) {
					locations[arr[i]].pb(j);
				}
			}
		}
	}
	cout << minStrokes(0, n - 1, 0) << nl;
}
