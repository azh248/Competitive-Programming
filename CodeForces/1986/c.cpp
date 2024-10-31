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
        string s; cin >> s;
        int ind[m];
        F0R(i, m) {
            cin >> ind[i];
            ind[i]--;
        }
        string c; cin >> c;
        sort(ind, ind + m);
        sort(c.begin(), c.end());
        vector<int> duplicates;
        vector<int> newInd;
        newInd.pb(ind[0]);
        FOR(i, 1, m) {
            if (ind[i] == ind[i - 1]) {
                duplicates.pb(ind[i]);
            } else {
                newInd.pb(ind[i]);
            }
        }
        string s1 = s;
        F0R(i, newInd.size()) {
            s1[newInd[i]] = c[i];
        }
        cout << s1 << nl;
	}	
}
