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
    freopen("secondFriend.in", "r", stdin);
    freopen("secondFriend.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
        int r, c; cin >> r >> c;
        bool hasTree = false;
        for (int i = 0; i < r; i++) {
            string s; cin >> s;
            for (int j = 0; j < c; j++) {
                if (s[j] == '^') {
                    hasTree = true;
                    break;
                }
            }
        }
        string sol;
        if (hasTree && (r < 2 || c < 2)) sol = "Impossible";
        else sol = "Possible";
		cout << "Case #" << t1 << ": " << sol << nl;
        if (sol == "Possible") {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (hasTree) {
                        cout << "^";
                    } else {
                        cout << ".";
                    }
                }
                cout << nl;
            }
        }		
	}	
}