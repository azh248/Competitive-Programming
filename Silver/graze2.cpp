#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, s;
int exactNum;

int cows[1501];

int dp[1501][1501]; // dp[i][j] = min total dist from cow i onwards if we've had j exact (s - 1)/(n - 1) distances so far

int minDist(int cow, int exactDistances) {
	if (cow == n) {
		int location = exactDistances * (int)((s - 1)/(n - 1)) + (cow - exactDistances - 1) * (int)((s - 1)/(n - 1) + 1) + 1;
		return (exactDistances == exactNum) ? abs(location - cows[cow]) : 1e9;
	} else if (dp[cow][exactDistances] != -1) {
		return dp[cow][exactDistances];
	}
	int location = exactDistances * (int)((s - 1)/(n - 1)) + (cow - exactDistances - 1) * (int)((s - 1)/(n - 1) + 1) + 1;
	int dist = min(minDist(cow + 1, exactDistances + 1), minDist(cow + 1, exactDistances)) + abs(location - cows[cow]);
	dp[cow][exactDistances] = dist;
	return dist;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("a.in", "r", stdin);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> cows[i];		
	}	
	sort(cows, cows + n + 1);
	for (int i = 0; i < n; i++) {
		if ((int)((s - 1)/(n - 1) + 1) * (n - 1 - i) + (int)((s - 1)/(n - 1)) * (i) == s - 1) {
			exactNum = i;
			break;
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << minDist(1, 0) << nl;
}
