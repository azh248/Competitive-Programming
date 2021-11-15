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
		int r, b, d; cin >> r >> b >> d;
		int maximum = max(r, b);
		int minimum = min(r, b);
		if ((double)maximum/(double)(1 + d) <= minimum) {
			cout << "YES" << nl;
		} else {
			cout << "NO" << nl;
		}
	}	
}