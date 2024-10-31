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
        ll arr[n];
        ll sum = 0;
        FOR(i, 0, n) {
            cin >> arr[i];
            sum += arr[i];
        }
        // do one round of MAD; after this the array will always be sorted
        unordered_set<ll> s;
        ll maxDup = 0;
        vector<ll> a;
        F0R(i, n) {
            if (s.find(arr[i]) != s.end()) {
                maxDup = max(maxDup, arr[i]);
            } else {
                s.insert(arr[i]);
            }
            a.pb(maxDup);
            sum += maxDup;
        }
        // do another round of MAD; after this everything except (maybe) the first and last elements will have duplicates
        s.clear();
        maxDup = 0;
        vector<ll> b;
        for (int i = 0; i < a.size(); i++) {
            if (s.find(a[i]) != s.end()) {
                maxDup = max(maxDup, a[i]);
            } else {
                s.insert(a[i]);
            }
            b.pb(maxDup);
            // sum += maxDup;
        }
        ll sz = b.size();
        for (int i = 0; i < sz; i++) {
            sum += (ll) b[i] * (ll) (sz - i);
        }
        cout << sum << nl;
	}	
}
