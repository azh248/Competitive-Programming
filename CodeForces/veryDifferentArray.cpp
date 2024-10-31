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
		int n, m; cin >> n >> m;
        vector<ll> a;
        FOR(i, 0, n) {
            ll x; cin >> x;
            a.pb(x);
        }
        vector<ll> b;
        FOR(i, 0, m) {
            ll x; cin >> x;
            b.pb(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<ll>());
        if (a[n - 1] < b[m - 1]) {
            ll ans = 0;
            for (int i = 0; i < n; i++) {
                ans += b[i] - a[i];
            }
            cout << ans << nl;
        } else if (a[0] > b[0]) {
            ll ans = 0;
            for (int i = 0; i < n; i++) {
                ans += a[i] - b[m - i - 1];
            }
            cout << ans << nl;
        } else {
            ll ans = 0;
            int ap1 = 0;
            int ap2 = n - 1;
            int bp1 = 0;
            int bp2 = m - 1;
            while (ap1 <= ap2) {
                if (b[bp1] - a[ap1] > a[ap2] - b[bp2]) {
                    ans += b[bp1] - a[ap1];
                    bp1++;
                    ap1++;
                } else {
                    ans += a[ap2] - b[bp2];
                    ap2--;
                    bp2--;
                }
            }
            cout << ans << nl;
        }
	}	
}
