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
	while (t--) {
		ll n, m, i, j; cin >> n >> m >> i >> j;
		ll num1 = sqrt((i - 1) * (i - 1) + (j - 1) * (j - 1)) + sqrt((n - i) * (n - i) + (m - j) * (m - j)) + m + n - 2;
		ll num2 = sqrt((i - 1) * (i - 1) + (m - j) * (m - j)) + sqrt((n - i) * (n - i) + (j - 1) * (j - 1)) + m + n - 2;
		if (num1 > num2) {
			cout << 1 << " " << 1 << " " << n << " " << m << nl;
		} else {
			cout << n << " " << 1 << " " << 1 << " " << m << nl;
		}
	}
}