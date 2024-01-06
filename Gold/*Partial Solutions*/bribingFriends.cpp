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

int n, a, b;
vector<int> cows[2005];

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int dp[205][205][205];

int maxPopularity(int ind, int money, int cones) {
    if (ind == n) return 0;
    if (money < 0 || cones < 0) return -1e9;
    if (dp[ind][money][cones] != -1) return dp[ind][money][cones];
    int ans = 0;
    ans = max(ans, maxPopularity(ind + 1, money, cones));
    // int discount = (int)(cones / cows[ind][2]);
    // if (discount > cows[ind][1]){
    //     ans = max(ans, maxPopularity(ind + 1, 0, cones - cows[ind][2] * cows[ind][1]) + cows[ind][0]);
    // } else if (money >= cows[ind][1] - discount) {
    //     ans = max(ans, maxPopularity(ind + 1, money - cows[ind][1] + discount, cones % cows[ind][2]) + cows[ind][0]);
    // }
    if (cones == 0) {
        if (money >= cows[ind][1]) {
            ans = max(ans, maxPopularity(ind + 1, money - cows[ind][1], 0) + cows[ind][0]);
        }
    } else {
        for (int discounts = 0; discounts <= (int)(cones/cows[ind][2]); discounts++) {
            if (money >= cows[ind][1] - discounts && cones >= discounts * cows[ind][2] && discounts <= cows[ind][1]) {
                ans = max(ans, maxPopularity(ind + 1, money - cows[ind][1] + discounts, cones - discounts * cows[ind][2]) + cows[ind][0]);
            }
        }
    }
    dp[ind][money][cones] = ans;
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
        int p, c, x; cin >> p >> c >> x;
        cows[i] = {p, c, x};
	}
    sort(cows, cows + n, cmp);
    FOR(i, 0, 205) FOR(j, 0, 205) FOR(k, 0, 205) dp[i][j][k] = -1;
    cout << maxPopularity(0, a, b) << nl;
}
