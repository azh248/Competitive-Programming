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
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		long double sum1 = 0;
		for (int i = 0; i < n; i++) {
			sum1 += arr[i];
		}
		long double maxSumAverage = -1e18;
		long double sum2 = 0;
		for (int i = n; i >= 0; i--) {
			maxSumAverage = max(maxSumAverage, sum1/i + sum2/(n - i));
			if (i > 0) {
				sum1 -= arr[i - 1];
				sum2 += arr[i - 1];
			}
		}
		cout << fixed << setprecision(18) << maxSumAverage << nl;
	}
}