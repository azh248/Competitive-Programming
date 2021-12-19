/*
ID:azh248
LANG:C++
TASK:ceating 
*/

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

int n, d;
ll arr[50000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll l = 0;
	ll r = 1e18l;
	ll ans = l - 1;
	while (l <= r) {
		ll mid = (r + l) / 2;
		int ptr = 0;
		ll prevDay = 0;
		bool works = true;
		for (int i = 0; i < d; i++) {
			if (ptr == n) {
				if (prevDay/(pow(2, d - 1 - i)) < mid) {
					works = false;
				}
				break;
			}
			while (prevDay < mid) {
				prevDay += arr[ptr];
				ptr++;
				if (ptr == n) {
					if (prevDay < mid) {
						works = false;
					}
					break;
				}
			}
			prevDay /= 2;
		}
		if (works) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << nl;
}
