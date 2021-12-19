/*
ID:azh248
LANG:C++
TASK:cowmbat 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define F0R1(i, a) for (int i = 1; i <= (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i = a; i > 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())
#define S0RT(arr, n) sort(arr, arr + n)

#define pA first
#define pB second
#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m, k;
string s;
int arr[10000];
int dist[30][30];
void floydWarshall() { // O(nodes^3)
	for (int k = 0; k < m; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int dp[100005][30];
ll costPsums[100005][30];

int minDays(int press, int button) {
	if (press >= n) {
		return 0;
	} else if (dp[press][button] != -1) {
		return dp[press][button];
	}
	int days = minDays(press + 1, button) + dist[arr[press]][button];
	if (press + k - 1 < n) {
		for (int i = 0; i < m; i++) {
			days = min(days, (int)(minDays(press + k, i) + costPsums[press + k - 1][i] - costPsums[press - 1][i]));
		}
	}
	dp[press][button] = days;
	return days;
}

int main() {
	freopen("cowmbat.in", "r", stdin);
	freopen("cowmbat.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k >> s;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> dist[i][j];
		}
	}
	floydWarshall();
	for (int i = 0; i < n; i++) {
		arr[i] = s[i] - 'a';
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < m; i++) {
		costPsums[0][i] = dist[arr[0]][i];
		for (int j = 1; j < n; j++) {
			costPsums[j][i] = dist[arr[j]][i] + costPsums[j - 1][i];
		}
	}
	int days = 1e9;
	for (int i = 0; i < m; i++) {
		int cost = costPsums[k - 1][i];
		days = min(days, minDays(k, i) + cost);
	}
	cout << days << nl;
}
