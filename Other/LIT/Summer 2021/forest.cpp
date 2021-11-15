#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	pii arr[100];
	for (int i = 0; i < n; i++) {
		ll x, y; cin >> x >> y;
		arr[i] = pii(x, y);
	}
	int maximum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int count = 2;
			for (int k = j + 1; k < n; k++) {
				if ((arr[i].second - arr[j].second) * (arr[i].first - arr[k].first) == (arr[i].first - arr[j].first) * (arr[i].second - arr[k].second)) {
					count++;
				}
			}
			maximum = max(maximum, count);
		}
	}
	cout << maximum << nl;
}