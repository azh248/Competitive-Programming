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
	// freopen("a.in", "r", stdin);
	cin >> t;
	for (int t1 = 0; t1 < t; t1++) {
		int n, k;
		cin >> n >> k;
		int heights[n];
		for (int i = 0; i < n; i++) {
			cin >> heights[i];
		}
		// int maxAfterEachPoint[n];
		// int currentMax = 0;
		// for (int i = n - 1; i >= 0; i--) {
		// 	currentMax = max(currentMax, heights[i]);
		// 	maxAfterEachPoint[i] = currentMax;
		// }
		// int boulderNumber = 0;
		// for (int i = 0; i < n; i++) {

		// }
		ll boulderNumber = 0;
		bool stop = false;
		for (int j = 1; j < n; j++) {
			if (heights[j] > heights[j - 1]) {
				boulderNumber += 1;
				heights[j - 1]++;
				if (boulderNumber >= k) {
					cout << j << nl;
					stop = true;
					break;
				}
				j = max(0, j - 2);
			}
		}
		if (!stop) {
			cout << -1 << nl;
		}
	}	
}
