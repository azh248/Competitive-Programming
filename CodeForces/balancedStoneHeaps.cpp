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
ll arr[200000];
ll newArr[200000];

int main() {
	// freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll maxNum = 0;
		FOR(i, 0, n) { 
			cin >> arr[i];
			maxNum = max(maxNum, arr[i]);
		}
		FOR(i, 0, n) { newArr[i] = arr[i]; }
		int l = 1;
		int r = maxNum;
		int ans = l - 1;
		while (l <= r) {
			int mid = (r + l) / 2;
			bool works = true;
			for (int i = n - 1; i >= 2; i--) {
				if (newArr[i] < mid) {
					works = false;
					break;
				}
				int d = min(arr[i] / 3, (newArr[i] - mid) / 3);
				newArr[i - 1] += d;
				newArr[i - 2] += 2 * d;
				newArr[i] -= 3 * d;
			}
			if (newArr[0] < mid || newArr[1] < mid) {
				works = false;
			}
			if (works) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
			FOR(i, 0, n) { newArr[i] = arr[i]; }
		}
		cout << ans << nl;
	}
}
