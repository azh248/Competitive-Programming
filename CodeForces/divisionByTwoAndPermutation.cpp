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
		int n;
		cin >> n;
		int arr[51];
		int cnt[51]{};
		FOR(i, 0, n) { cin >> arr[i]; }
		FOR(i, 0, n) {
			while (arr[i] > n) {
				arr[i] /= 2;
			}
			cnt[arr[i]]++;
		}
		bool works = true;
		for (int i = n; i >= 1; i--) {
			if (cnt[i] > 0) {
				if (i == 1) {
					if (cnt[i] > 1) {
						works = false;
						break;
					}
				}
				cnt[i / 2] += cnt[i] - 1;
				cnt[i] = 1;
			} else {
				works = false;
				break;
			}
		}
		if (!works) {
			cout << "NO" << nl;
		} else {
			cout << "YES" << nl;
		}
	}
}
