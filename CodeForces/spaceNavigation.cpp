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
	for (int t1 = 0; t1 < t; t1++) {
		int x, y;
		cin >> x >> y;
		string s;
		cin >> s;
		int U = 0;
		int D = 0;
		int L = 0;
		int R = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'U') {
				U++;
			} else if (s[i] == 'D') {
				D++;
			} else if (s[i] == 'L') {
				L++;
			} else {
				R++;
			}
		}	
		if (x < 0) {
			if (L < abs(x)) {
				cout << "NO" << nl;
				continue;
			}
		} else {
			if (R < x) {
				cout << "NO" << nl;
				continue;
			}
		}
		if (y < 0) {
			if (D < abs(y)) {
				cout << "NO" << nl;
				continue;
			}
		} else {
			if (U < y) {
				cout << "NO" << nl;
				continue;
			}
		}
		cout << "YES" << nl;
	}	
}
