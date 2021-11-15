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
		ll a, b;
		cin >> a >> b;
		if (a < b) {
			swap(a, b);
		}
		ll diff = a - b;
		cout << diff << " ";
		if (diff == 0) {
			cout << 0 << nl;
			continue;
		}
		ll subtractMoves = ((a % diff) + (b % diff))/2;
		ll addMoves = diff - subtractMoves;
		cout << min(subtractMoves, addMoves) << nl;
	}
}
