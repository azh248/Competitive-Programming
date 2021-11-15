/*
ID: azh248
LANG: C++
TASK: feast
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

int t, a, b;
int dp[5000000][2]; // dp[i][j] = max fullness possible with i fullness accumulated and j waters drank (j == 0 or 1)

int maxFullAchieved(int fullness, int waterDrank) { // bottom up dp
	if (fullness > t) {
		return 0;
	}
    if (dp[fullness][waterDrank] != 0) {
        return dp[fullness][waterDrank];
    }
	int origFullness = fullness;
    fullness = max(fullness, maxFullAchieved(origFullness + a, waterDrank));
    fullness = max(fullness, maxFullAchieved(origFullness + b, waterDrank));
    if (waterDrank == 0) {
        fullness = max(fullness, maxFullAchieved(origFullness / 2, 1));
    }
    dp[origFullness][waterDrank] = fullness;
    return fullness;
}
int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    cin >> t >> a >> b;
    cout << maxFullAchieved(0, 0) << nl;
}