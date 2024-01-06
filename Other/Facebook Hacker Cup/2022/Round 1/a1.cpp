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
    freopen("a1_test.in", "r", stdin);
    freopen("a1_test.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        F0R(i, n) cin >> a[i];
        vector<int> b(n);
        F0R(i, n) cin >> b[i];
        if (n == 2) {
            if (a == b && k % 2 == 0) cout << "Case #" << t1 << ": " << "YES" << nl;
            else if (a == b && k % 2 == 1) cout << "Case #" << t1 << ": " << "NO" << nl;
            else if (a != b && k % 2 == 0) cout << "Case #" << t1 << ": " << "NO" << nl;
            else if (a != b && k % 2 == 1) cout << "Case #" << t1 << ": " << "YES" << nl;
            continue;
        } else if (k == 0) {
            if (a == b) cout << "Case #" << t1 << ": " << "YES" << nl;
            else cout << "Case #" << t1 << ": " << "NO" << nl;
            continue;
        } else if (k == 1) {
            if (a == b) cout << "Case #" << t1 << ": " << "NO" << nl;
            else {
                F0R(i, n) a.pb(a[i]);
                for (int i = 0; i < n; i++) {
                    bool works = true;
                    for (int j = 0; j < n; j++) {
                        if (a[i + j] != b[j]) {
                            works = false;
                            break;
                        }
                    }
                    if (works) {
                        cout << "Case #" << t1 << ": " << "YES" << nl;
                        break;
                    } else if (i == n - 1) {
                        cout << "Case #" << t1 << ": " << "NO" << nl;
                    }
                }
            }
            continue;
        }
        F0R(i, n) a.pb(a[i]);
        for (int i = 0; i < n; i++) {
            bool works = true;
            for (int j = 0; j < n; j++) {
                if (a[i + j] != b[j]) {
                    works = false;
                    break;
                }
            }
            if (works) {
                cout << "Case #" << t1 << ": " << "YES" << nl;
                break;
            } else if (i == n - 1) {
                cout << "Case #" << t1 << ": " << "NO" << nl;
            }
        }
	}	
}