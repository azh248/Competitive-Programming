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
		ll n; cin >> n;
		ll time = 0;
		if (n < 120) {
			time = 1e9;
			for (int i = 0; i <= 20; i++) {
				for (int j = 0; j <= 20; j++) {
					for (int k = 0; k <= 12; k++) {
						if (6 * i + 8 * j + 10 * k >= n) {
							time = min(time, (ll)(15 * i + 20 * j + 25 * k));
						}
					}
				}
			}
			cout << time << nl;
			continue;
		}
		time += 300 * (n / 120 - 1);
		n -= 120 * (n / 120 - 1);
		ll minTime = 1e9;
		for (int i = 0; i <= 40; i++) {
			for (int j = 0; j <= 30; j++) {
				for (int k = 0; k <= 24; k++) {
					if (6*i + 8*j + 10*k >= n) {
						minTime = min(minTime, (ll)(15*i + 20*j + 25*k));
					}
				}
			}
		}
		cout << time + minTime << nl;
	}
}