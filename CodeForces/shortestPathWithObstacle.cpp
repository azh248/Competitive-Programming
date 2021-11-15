#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		ll a1, a2, b1, b2, f1, f2;
		cin >> a1 >> a2 >> b1 >> b2 >> f1 >> f2;
		if (a2 == b2 && f2 == a2 && ((f1 > a1 && f1 < b1) || (f1 > b1 && f1 < a1))) {
			cout << abs(b2 - a2) + abs(b1 - a1) + 2 << nl;
		} else if (a1 == b1 && f1 == a1 && ((f2 > a2 && f2 < b2) || (f2 > b2 && f2 < a2))) {
			cout << abs(b2 - a2) + abs(b1 - a1) + 2 << nl;
		} else {
			cout << abs(b2 - a2) + abs(b1 - a1) << nl;
		}
	}
}
