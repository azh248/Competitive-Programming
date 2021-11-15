/*
ID:azh248
LANG:C++
TASK:fencedin 
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

ll a, b, n, m;
vector<ll> verticalFences, horizontalFences;
vector<pii> overallFences;

int main() {
	freopen("fencedin.in", "r", stdin);
	freopen("fencedin.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> n >> m;
	verticalFences.pb(0);
	for (int i = 0; i < n; i++) {
		ll fence; cin >> fence; verticalFences.pb(fence);
	}
	verticalFences.pb(a);
	horizontalFences.pb(0);
	for (int i = 0; i < m; i++) {
		ll fence; cin >> fence; horizontalFences.pb(fence);
	}
	horizontalFences.pb(b);
	sort(verticalFences.begin(), verticalFences.end());
	sort(horizontalFences.begin(), horizontalFences.end());
	for (int i = 0; i < n + 1; i++) {
		verticalFences[i] = verticalFences[i + 1] - verticalFences[i];
	}
	for (int i = 0; i < m + 1; i++) {
		horizontalFences[i] = horizontalFences[i + 1] - horizontalFences[i];
	}
	sort(verticalFences.begin(), verticalFences.end());
	sort(horizontalFences.begin(), horizontalFences.end());
	ll cost = 0;
	cost += (ll) (verticalFences[0]) * m;
	cost += (ll) (horizontalFences[0]) * n;
	int pointer1 = 1;
	int pointer2 = 1;
	n++;
	m++;
	while (pointer1 < n && pointer2 < m) {
		if (verticalFences[pointer1] < horizontalFences[pointer2]) {
			cost += (ll) (verticalFences[pointer1]) * (m - pointer2);
			pointer1++;
		} else {
			cost += (ll) (horizontalFences[pointer2]) * (n - pointer1);
			pointer2++;
		}
	}
	cout << cost << nl;
}