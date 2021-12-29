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
		int l, r;
		cin >> l >> r;
		ll currSum = 0;
		int minDeletions = 1e9;
		for (int i = ceil(log(r) / log(2)); i >= 1; i--) {
			// the sequence with bitwise AND containing this bit starts at 2^i + (2^(i + 1)) * k, for all k 
			// and it's of length 2^i
			int exp = pow(2, i);
			int beginNum = (2 * exp) * floor((double)l / (2 * exp));
			int endNum = (2 * exp) * floor((double)r / (2 * exp));
			if (beginNum > l) {
				beginNum -= exp;
			} else if (beginNum + exp > l - exp) {
				beginNum += exp;
			} else {
				beginNum -= exp;
			}
			if (endNum > r) {
				endNum -= exp;
			} else if (endNum + exp > r - exp) {
				endNum += exp;
			} else {
				endNum += exp;
			}
			endNum -= 2 * exp;
			beginNum += 2 * exp;
			int between = 0;
			if (endNum >= beginNum) {
				between = exp * ((endNum - beginNum) / (2 * exp) + 1);
			}
			endNum += 2 * exp;
			beginNum -= 2 * exp;
			if (beginNum > 0 && (l - beginNum) < exp && (r - beginNum) >= exp) {
				if (l >= beginNum) {
					between += exp - (l - beginNum);
				} else {
					between += exp;
				}
			} 
			if (endNum > 0 && r >= endNum && (r - endNum + 1) <= exp) {
				if (endNum >= l) {
					between += (r - endNum + 1);
				} else {
					between += (r - l + 1);
				}
			}
			minDeletions = min(minDeletions, r - l + 1 - between);
		}
		int oneBetween;
		int sz = r - l + 1;
		if (sz % 2 == 0) {
			oneBetween = sz / 2;
		} else {
			if ((l % 2) == 0 || (r % 2) == 0) {
				oneBetween = sz / 2 + 1;
			} else {
				oneBetween = sz / 2;
			}
		}
		minDeletions = min(minDeletions, oneBetween);
		cout << minDeletions << nl;
	}
}
