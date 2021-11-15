#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 0; t1 < t; t1++) {
		ll a, b, n;
		cin >> a >> b >> n;
		ll totalDamage = 0;
		pii arr[n];
		ll maxAttack = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].first;
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[i].second;
		}
		for (int i = 0; i < n; i++) {
			totalDamage += ceil((double) arr[i].second / (double) a) * arr[i].first;
			maxAttack = max(maxAttack, arr[i].first);
		}
		if (totalDamage - maxAttack >= b) {
			cout << "NO" << nl;
		} else {
			cout << "YES" << nl;
		}
	}	
}
