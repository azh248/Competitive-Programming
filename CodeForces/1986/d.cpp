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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        bool zero = false;
        if (n == 2) {
            cout << stoi(s) << nl;
            continue;
        } else if (n == 3) {
            int minRes = 1e9;
            int dig1 = s[0] - '0';
            int dig2 = s[1] - '0';
            int dig3 = s[2] - '0';
            minRes = min(minRes, dig1*10 + dig2 + dig3);
            minRes = min(minRes, dig1 + dig2*10 + dig3);
            minRes = min(minRes, (dig1 * 10 + dig2) * dig3);
            minRes = min(minRes, dig1 * (dig2 * 10 + dig3));
            cout << minRes << nl;
            continue;
        }
        FOR(i, 0, n) {
            if (s[i] == '0' && (i > 1 || i < n - 2)) {
                zero = true;
                break;
            }
        }
        if (zero) {
            cout << 0 << nl;
            continue;
        }
        int doubleInd = -1;
        int minDig = 10;
        int secondMinDig = 10;
        FOR(i, 0, n - 1) {
            if ((s[i] - '0') < minDig) {
                minDig = s[i] - '0';
                secondMinDig = s[i + 1] - '0';
                doubleInd = i;
            } else if ((s[i] - '0') == minDig && (s[i + 1] - '0') > secondMinDig) {
                secondMinDig = s[i + 1] - '0';
                doubleInd = i;
            }
        }
        ll resSum = 0;
        FOR(i, 0, n) {
            if (i == doubleInd) {
                resSum += (s[i] - '0') * 10;
            } else if (s[i] == '1' && i != doubleInd + 1) {
                continue;
            } else {
                resSum += s[i] - '0';
            }
        }
        cout << resSum << nl;
	}	
}
