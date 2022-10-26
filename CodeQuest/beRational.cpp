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
        string s;
        cin >> s;
        vector<ll> ints;
		int n = s.size();
		int startingNumber = 0;
		int finalI = 0;
		int nextN = n;
		for (int i = 0; i < n; i++) {
			if (s[i] == '.') {
				nextN--;
				finalI = i;
				break;
			} else {
				startingNumber *= 10;
				startingNumber += s[i] - '0';
				nextN--;
			}
		}
		n = nextN;

		ints.pb(startingNumber);
		
		if (finalI == 0) {
			cout << startingNumber << nl;
			continue;
		}

		ll initFrac = stoll(s.substr(finalI + 1, n), nullptr, 10);
		ints.pb((ll)pow(10, n) / initFrac);
		ll remainder = ((ll)pow(10, n)) % initFrac;

		if (remainder != 0) {
			// next fraction is remainder / initFrac
			for (int i = 2; i < 10; i++) {
				ll newRemainder = initFrac % remainder;
				ints.pb(initFrac / remainder);
				if (newRemainder == 0) break;
				initFrac = remainder;
				remainder = newRemainder;
			}
		}
		FOR(i, 0, ints.size() - 1) {
			cout << ints[i] << " ";
		}
		cout << ints[ints.size() - 1] << nl;
    }
}
