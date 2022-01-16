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

int findGCD(int a, int b) { // O(logn)
	if (b == 0)
		return a;
	return findGCD(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[70];
		FOR(i, 0, n) { cin >> arr[i]; }
		int minOps = n - 1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int newArr[70];
				FOR(k, 0, n) {
					newArr[k] = arr[k];
				}
				int cost = n;
				int diff = arr[j] - arr[i];
				int jump = j - i;
				if (diff == 0) {
					jump = 1;
				} else {
					int divGcd = findGCD(abs(jump), abs(diff));
					diff /= divGcd;
					jump /= divGcd;
				}
				for (int k = i; k >= 0; k -= jump) {
					if (arr[k] == (arr[i] - diff * (i - k)/jump)) {
						cost--;
					}
				}
				for (int k = j; k < n; k += jump) {
					if (arr[k] == (arr[j] + diff * (k - j)/jump)) {
						cost--;
					}
				}
				minOps = min(minOps, cost);
			}
		}
		cout << minOps << nl;
	}
}
