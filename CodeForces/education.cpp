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
	while (t--) {
		ll n, c;
		cin >> n >> c;
		ll salary[200000];
		for (int i = 0; i < n; i++) {
			cin >> salary[i];
		}
		ll cost[200000];
		for (int i = 0; i < n - 1; i++) {
			cin >> cost[i];
		}
		pii position[200000]; // position[i] = {min days to get to position i, remaining tugrik afterwards};
		position[0] = {0, 0};
		for (int i = 1; i < n; i++) {
			ll tugriks = position[i - 1].second;
			ll days = ceil((double)(cost[i - 1] - tugriks)/(double)salary[i - 1]);
			ll remaining = tugriks + days * salary[i - 1] - cost[i - 1];
			position[i] = {days + position[i - 1].first + 1, remaining};
		}
		ll minDays = 1e18;
		for (int i = 0; i < n; i++) {
			ll tugriks = position[i].second;
			ll days = position[i].first;
			minDays = min(minDays, days + (ll)ceil((double)(c - tugriks)/(double)salary[i]));
		}
		cout << minDays << nl;
	}	
}
