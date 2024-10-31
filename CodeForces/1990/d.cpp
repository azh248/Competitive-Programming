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

int t, n;

int dp[200005][2][2]; // dp[i][j][k] = minimum operations to dye everything from row i onwards white, given that
                      // cells (i, 0) and (i, 1) are dyed white (j) and cells (i, 2) and (i, 3) are dyed white (k)

int arr[200005];

int minOps(int i, int j, int k) {
    if (i == n) {
        return 0;
    }
    if (dp[i][j][k] != -1) {
        return dp[i][j][k];
    }
    if (arr[i] == 0) {
        return dp[i][j][k] = minOps(i + 1, 0, 0);
    }
    if (i == n - 1) {
        if ((arr[i] <= 2 && j == 1) || (j == 1 && k == 1)) {
            return dp[i][j][k] = 0;
        }
        return dp[i][j][k] = 1;
    }
    int ans = minOps(i + 1, 0, 0) + 1;
    if (arr[i] > 4) {
        return dp[i][j][k] = ans;
    } 
    if (arr[i] <= 2) {
        if (j == 1) {
            ans = min(ans, minOps(i + 1, 0, 0));
        } else {
            ans = min(ans, minOps(i + 1, 1, 0) + 1);
        }
        return dp[i][j][k] = ans;
    }
    // assume from here on out that 3 <= arr[i] <= 4
    if (j == 1) {
        if (k == 1) {
            ans = min(ans, minOps(i + 1, 0, 0));
        } else { // place down one square on right side
            ans = min(ans, minOps(i + 1, 0, 1) + 1);
        }
    } else {
        if (k == 1) { // place down one square on left side
            ans = min(ans, minOps(i + 1, 1, 0) + 1);
        } else { // place down 2 squares
            ans = min(ans, minOps(i + 1, 1, 1) + 2);
        }
    }
    return dp[i][j][k] = ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
        cin >> n;
        F0R(i, n) {
            cin >> arr[i];
        }
        if (n == 1) {
            cout << arr[0] << nl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        cout << minOps(0, 0, 0) << nl;
	}	
}
