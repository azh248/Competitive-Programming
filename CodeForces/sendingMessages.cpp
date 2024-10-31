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
		ll n, f, a, b; cin >> n >> f >> a >> b;
        vector<ll> m;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            m.pb(x);
        }
        ll time = 0;
        ll cost = 0;
        for (int i = 0; i < n; i++) {
            if ((m[i] - time) * a <= b) {
                cost += (m[i] - time) * a;
            } else {
                cost += b;
            }
            time = m[i];
        }
        cout << (cost < f ? "YES" : "NO") << nl;
	}	
}
