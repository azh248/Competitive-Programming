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
	for (int t1 = 0; t1 < t; t1++) {
		ll a, b;
		cin >> a >> b;
		ll moves = 0;
		while (floor(log(a)/log(b + 1)) + 1 <= floor(log(a)/log(b)) || a == b) {
			b++;
			moves++;
		}
		while (a > 0) {
			a = floor((double)a/(double)b);
			moves++;
		}
		cout << moves << nl;
	}	
}
