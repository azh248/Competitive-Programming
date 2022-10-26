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
		int r, c;
		cin >> r >> c;
		string arr[2 * r + 1][2 * c + 1];
		FOR(i, 0, 2) {
			FOR(j, 0, 2) {
				arr[i][j] = ".";
			}
		}
		for (int i = 0; i <= r; i++) {
			for (int j = 0; j <= c; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				arr[2 * i][2 * j] = "+";
			}
			for (int j = 0; j < c; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				arr[2 * i][2 * j + 1] = "-";
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j <= c; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				arr[2 * i + 1][2 * j] = "|";
			}
			for (int j = 0; j < c; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				arr[2 * i + 1][2 * j + 1] = ".";
			}
		}
		cout << "Case #" << t1 << ": " << nl;
		for (int i = 0; i <= 2 * r; i++) {
			for (int j = 0; j <= 2 * c; j++) {
				cout << arr[i][j];
			}
			cout << nl;
		}
	}
}
