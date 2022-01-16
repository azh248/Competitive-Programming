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
int arr[200000];
int cnt[26];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		// count all the letters that have an odd count, then go through all k strings and bsearch on maximum shortest length
		int n, k;
		cin >> n >> k;
		FOR(i, 0, 26) { cnt[i] = 0; }
		string s;
		cin >> s;
		multiset<int, greater<int>> odds;
		multiset<int, greater<int>> evens;
		int pairs = 0;
		int unpaired = 0;
		FOR(i, 0, n) { cnt[s[i] - 'a']++; }
		FOR(i, 0, 26) {
			if (cnt[i] % 2 == 1) {
				unpaired++;
			}
			pairs += cnt[i] / 2;
		}
		// SORT(odds);
		// SORT(evens);
		// reverse(odds.begin(), odds.end());
		// reverse(evens.begin(), evens.end());
		int l = 0;
		int r = n;
		int ans = l - 1;
		while (l <= r) {
			ll mid = (r + l) / 2;
			int currStrings = 0;
			int pairs1 = pairs;
			int unpaired1 = unpaired;
			bool works = true;
			while (currStrings < k) {
				if ((pairs1 == 0 && mid > 1) || (pairs1 == 0 && unpaired1 == 0)) {
					works = false;
					break;
				} else {
					if (mid % 2 == 1) {
						if (unpaired1 > 0) {
							unpaired1--;
							pairs1 -= (mid / 2);
							if (pairs1 < 0) {
								works = false;
								break;
							}
						} else {
							pairs1--;
							unpaired1 += 2;
							unpaired1--;
							pairs1 -= (mid / 2);
							if (pairs1 < 0) {
								works = false;
								break;
							}
						}
					} else {
						pairs1 -= mid / 2;
						if (pairs1 < 0) {
							works = false;
							break;
						}
					}
				}
				currStrings++;
			}
			if ((mid * k <= n) && works) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		cout << max(ans, 1) << nl;
	}
}
