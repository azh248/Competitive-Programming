#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
int arr[100];
pii dp[100][100][2];

pii points(int a, int b, int turn) {
	if (a > b) {
		return {0, 0};
	} else if (dp[a][b][turn].first != -1) {
		return dp[a][b][turn];
	}
	pii scores;
	if (turn == 0) {
		int takeA = points(a + 1, b, 1).first + arr[a]; 
		int takeB = points(a, b - 1, 1).first + arr[b];
		if (takeA > takeB) {
			scores = points(a + 1, b, 1); 
			scores.first += arr[a];
		} else {
			scores = points(a, b - 1, 1);
			scores.first += arr[b];	
		}
	} else if (turn == 1) {
		int takeA = points(a + 1, b, 0).second + arr[a]; 
		int takeB = points(a, b - 1, 0).second + arr[b];
		if (takeA > takeB) {
			scores = points(a + 1, b, 0); 
			scores.second += arr[a];
		} else {
			scores = points(a, b - 1, 0);
			scores.second += arr[b];	
		}
	}
	dp[a][b][turn] = scores;
	return scores;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}	
	memset(dp, -1, sizeof(dp));
	cout << points(0, n - 1, 0).first << " " << points(0, n - 1, 0).second << nl;
}
