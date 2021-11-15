/*
ID:azh248
LANG:C++
TASK:fuel 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, g, b, d;
pii station[50002];

int main() {
	freopen("fuel.in", "r", stdin);
	freopen("fuel.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> g >> b >> d;
	station[0] = {0, 1e9};
	station[n + 1] = {d, -1};
	for (int i = 1; i <= n; i++) {
		cin >> station[i].first >> station[i].second;
	}	
	sort(station, station + n + 2);
	int nextStation[50002];
	stack<vector<ll> > next;
	for (int i = n + 1; i >= 0; i--) {
		if (i != 0 && (station[i].first - station[i - 1].first > g)) {
			cout << -1 << nl;
			return 0;
		}
		while (!next.empty() && ((next.top()[1] > station[i].second) || (next.top()[0] - station[i].first > g))) {
			next.pop();
		}
		if (next.empty()) {
			nextStation[i] = -1;
		} else {
			nextStation[i] = next.top()[2];
		}
		next.push({station[i].first, station[i].second, i});
	}
	int gasLeft = b;
	int curr = 0;
	ll moneyPaid = 0;
	while (curr != n + 1) {
		if (nextStation[curr] != -1) {
			if (station[nextStation[curr]].first - station[curr].first <= gasLeft) {
				gasLeft -= (station[nextStation[curr]].first - station[curr].first); 
				curr = nextStation[curr];
			} else {
				moneyPaid += station[curr].second * ((station[nextStation[curr]].first - station[curr].first) - gasLeft);
				gasLeft = 0;
				curr = nextStation[curr];
			}
		} else {
			moneyPaid += station[curr].second * (g - gasLeft);
			gasLeft = (g - (station[curr + 1].first - station[curr].first));
			curr++;
		}
	}
	cout << moneyPaid << nl;
}
