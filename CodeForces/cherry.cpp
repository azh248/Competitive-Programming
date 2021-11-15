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
		int n; cin >> n;
		vector<ll> arr(n);
		// vector<pii> arr1(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			// arr1[i] = pii(arr[i], i);
		}
		ll maxVal = 0;
		for (int i = 0; i < n - 1; i++) {
			maxVal = max(maxVal, max(arr[i], arr[i + 1]) * min(arr[i], arr[i + 1]));
		}
		cout << maxVal << nl;
		// int maxVal = 0;
		// int prevMax = arr[0];
		// int prevMin = arr[0];
		// for (int i = 1; i < n; i++) {
		// 	prevMax = max(prevMax, arr[i]);
		// 	prevMin = min(prevMin, )
		// }
		// prevMax = arr[n - 1];
		// prevMin = arr[n - 1];
	}
}