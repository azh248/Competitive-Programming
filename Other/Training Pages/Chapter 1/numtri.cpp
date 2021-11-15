/*
ID:azh248
LANG:C++
TASK:numtri 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int r;

int triangle[1000][1000];

int dp[1000][1000];

int maxSum(int a, int b) {
	if (a < 0 || a >= r || b < 0 || b > a) {
		return 0;
	} else if (dp[a][b] != -1) {
		return dp[a][b];
	}
	int sum = max(maxSum(a + 1, b) + triangle[a][b], maxSum(a + 1, b + 1) + triangle[a][b]);
	dp[a][b] = sum;
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
    cin >> r;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}	
	memset(dp, -1, sizeof(dp));
	cout << maxSum(0, 0) << nl;
}
