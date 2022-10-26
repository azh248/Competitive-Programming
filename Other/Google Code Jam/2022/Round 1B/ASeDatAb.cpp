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
	for (int t1 = 1; t1 <= t; t1++) {
		cout << "00000000" << nl;
		cout.flush();
		int n;
		cin >> n;
		if (n > 4) {
			cout << "11111111" << nl;
			cout.flush();
			cin >> n;
		}
		while (n > 0) {
			// if (n >= 3) {
			// 	while (n > 2) {
			// 		cout << "10101010" << nl;
			// 		cout.flush();
			// 		cin >> n;
			// 	}
			if (n > 4) {
				cout << "11111111" << nl;
				cout.flush();
				cin >> n;
			} else if (n > 3) {
				cout << "11011000" << nl;
				cout.flush();
				cin >> n;
			} else if (n > 2) {
				cout << "11111000" << nl;
				cout.flush();
				cin >> n;	
			} else {
				cout << "10000000" << nl;
				cout.flush();
				cin >> n;
			}
		}
	}	
}