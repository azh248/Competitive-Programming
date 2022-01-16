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
		int n, k;
		cin >> n >> k;
		if (k > (n + 1) / 2) {
			cout << -1 << nl;
		} else {
			string arr[40][40];
			FOR(i, 0, n){
				FOR(j, 0, n) {
					arr[i][j] = ".";
				}
			}
			int ptr = 0;
			for (int i = 0; i < k; i++) {
				if (ptr >= n) {
					assert(false);
				}
				arr[ptr][ptr] = "R";
				ptr += 2;
			}
			FOR(i, 0, n) {
				FOR(j, 0, n) { cout << arr[i][j]; }
				cout << nl;
			}
		}
	}
}
