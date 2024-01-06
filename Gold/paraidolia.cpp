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

string s;
int n;
int cost[200005];

int dp1[200005][7];

int maxBessies(int ind, int bessieInd) {
    if (dp1[ind][bessieInd] != -1) {
        return dp1[ind][bessieInd];
    }
    if (ind == n) {
        return 0;
    }
    int ans = 0;
    ans = max(ans, maxBessies(ind + 1, bessieInd));
    // ans = max(ans, maxBessies(ind + 1, 0));
    if (s[ind] == "bessie"[bessieInd]) {
        if (bessieInd == 5) {
            ans = max(ans, 1 + maxBessies(ind + 1, 0));
        } else {
            ans = max(ans, maxBessies(ind + 1, bessieInd + 1));
        }
    }
    dp1[ind][bessieInd] = ans;
    return ans;
}


int totBessies;

ll dp[200005][7][2];

ll minCost(int ind, int bessieInd, int started) {
    if (dp[ind][bessieInd][started] != -1) {
        return dp[ind][bessieInd][started];
    }
    if (ind == n) {
        return 0;
    }
    ll ans = 0;
    if (started && bessieInd > 0) {
        ans = min(ans, cost[ind] + minCost(ind + 1, bessieInd, started));
    } else {
        ans = min(ans, minCost(ind + 1, bessieInd, started));
    }
    // ans = min(ans, maxBessies(ind + 1, 0));
    if (s[ind] == "bessie"[bessieInd]) {
        if (bessieInd == 5) {
            ans = min(ans, minCost(ind + 1, 0, true) - (ll)1e9);
        } else {
            ans = min(ans, minCost(ind + 1, bessieInd + 1, true));
        }
    }
    dp[ind][bessieInd][started] = ans;
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
    n = s.length();
	for (int i = 0; i < n; i++) {
        cin >> cost[i];
	}
    for (int i = 0; i < n + 5; i++) {
        for (int j = 0; j < 7; j++) {
            dp1[i][j] = -1;
        }
    }
    // totBessies = maxBessies(0, 0);
    // cout << totBessies << nl;

    for (int i = 0; i < n + 5; i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    ll num = minCost(0, 0, false);
    int totBessies = ceil((double)-num/1e9);
    cout << totBessies << nl;
    int totCost = num + totBessies * 1e9;
    cout << totCost << nl;

    // cout << minCost(0, 0, false) << nl;
}
