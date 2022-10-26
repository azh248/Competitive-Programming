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
		string x;
		cin >> x;
		// reduction will always make x smaller, so we want the reduction that's as late as possible
		// while still keeping the same number of digits
		bool works = false;
		FORd(i, 1, x.length()) {
			if ((x[i] - '0') + (x[i - 1] - '0') >= 10) {
				works = true;
				FOR(j, 0, i - 1) { cout << string(1, x[j]); }
				cout << to_string((x[i] - '0') + (x[i - 1] - '0'));
				FOR(j, i + 1, x.length()) { cout << string(1, x[j]); }
				cout << nl;
				break;
			}
		}
		if (!works) {
			cout << to_string((x[0] - '0') + (x[1] - '0'));
			FOR(i, 2, x.length()) { cout << string(1, x[i]); }
			cout << nl;
		}
	}
}
