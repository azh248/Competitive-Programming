/*
ID: azh248
LANG: C++
TASK: teamwork
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl endl
#define pub push_back
#define pob pop_back
#define all(x) x.begin(), x.end()

int n, k;
int skills[10000];
int dp[10000][1000];

int maxSumToEnd(int cow, int teamSize) {
	if (dp[cow][teamSize] != 0) {
		return dp[cow][teamSize];
	}
    int topSkill = 0;
    for (int i = cow; i > cow - teamSize; i--) {
        topSkill = max(topSkill, skills[i]);
    }
    int teamSum = topSkill * teamSize;
	if (cow == n - 1) {
		dp[cow][teamSize] = teamSum;
	} else if (teamSize == k) {
		dp[cow][teamSize] = teamSum + maxSumToEnd(cow + 1, 1);
	} else {
		dp[cow][teamSize] = max(teamSum + maxSumToEnd(cow + 1, 1), maxSumToEnd(cow + 1, teamSize + 1));
	}
    return dp[cow][teamSize];
}

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
		cin >> skills[i];
    }
	cout << maxSumToEnd(0, 1) << nl;
}
