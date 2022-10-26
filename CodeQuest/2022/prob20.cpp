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

int t;

int n;

int dp[100][100];
vector<int> arr[100];
bool wentLeft[100][100];

int highestVal(int layer, int ind) {
	if (layer == n) {
		return arr[layer][ind];
	}
	if (dp[layer][ind] != -1) {
		return dp[layer][ind];
	}
	int ans = arr[layer][ind];
	if (highestVal(layer + 1, ind) > highestVal(layer + 1, ind + 1)) {
		ans += highestVal(layer + 1, ind);
		wentLeft[layer][ind] = true;
	} else {
		ans += highestVal(layer + 1, ind + 1);
		wentLeft[layer][ind] = false;
	}
	return dp[layer][ind] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		F0R1(i, n + 1) {
			arr[i - 1].clear();
			FOR(j, 0, i) {
				int num; cin >> num;
				arr[i - 1].pb(num);
			}
		}
		string ans = "";
		int ind = 0;
		highestVal(0, 0);
		FOR(i, 0, n) {
			if (wentLeft[i][ind]) {
				ans += "L";
			} else {
				ans += "R";
				ind++;
			}
		}
		cout << ans << " = " << highestVal(0, 0) << nl;
	}	
}
