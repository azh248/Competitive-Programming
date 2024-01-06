#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pli = pair<ll, int>;

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
#define nl "\n"
#define pb push_back

int n;
ll h[2005];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
        cin >> h[i];
	}	
    int q;
    cin >> q;
    FOR(q1, 0, q) {
        int a;
        ll b;
        cin >> a >> b;
        a--;
        h[a] += b;
        ll ans = 0;
        FOR(i, 0, n) {
            ll maxSlope = -1e18;
            FOR(j, i + 1, n) {
                ll newSlope = (ll)(((double)(h[j] - h[i]) / (j - i)) * 1e8);
                if (newSlope >= maxSlope) {
                    maxSlope = newSlope;
                    ans++;
                }
            }
        }
        cout << ans << nl;
    }
}
