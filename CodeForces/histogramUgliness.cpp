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
		int n;
		cin >> n;
		ll arr[400000];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		ll cost = 0;
		for (int i = 0; i < n - 1; i++) {
			cost += abs(arr[i] - arr[i + 1]);
		}
		cost += arr[0];
		cost += arr[n - 1];
		if (n == 1) {
			cout << arr[0] << nl;
			continue;
		}
		if (arr[0] > arr[1]) {
			cost -= arr[0] - arr[1];
		}
		if (arr[n - 1] > arr[n - 2]) {
			cost -= arr[n - 1] - arr[n - 2];
		}
		for (int i = 1; i < n - 1; i++) {
			if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
				cost -= min(arr[i] - arr[i - 1], arr[i] - arr[i + 1]);
			}
		}
		cout << cost << nl;
	}
}