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
		ll arr[n + 2];
		for (int i = 0; i < n + 2; i++) {
			cin >> arr[i];
		}	
		sort(arr, arr + n + 2);
		ll arrSum = arr[n + 1];
		ll sumWithX = 0;
		for (int i = 0; i < n + 1; i++) {
			sumWithX += arr[i];
		}
		if (sumWithX > arrSum) {
			vector<int> printNums;
			for (int i = 0; i < n + 1; i++) {
				if (arr[i] == sumWithX - arrSum) {
					sumWithX = 1e18;
					continue;
				} else {
					printNums.pb(arr[i]);
				}
			}
			if (sumWithX == 1e18) {
				for (int i = 0; i < n; i++) {
					cout << printNums[i] << " ";
				}
				cout << nl;
				continue;
			}
		}

		ll x = arr[n + 1];
		arrSum = arr[n];
		ll correctSum = 0;
		for (int i = 0; i < n; i++) {
			correctSum += arr[i];
		}
		if (correctSum == arrSum) {
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
			} 
			cout << nl;
			continue;
		} else {
			cout << -1 << nl;
			continue;
		}
	}	
}
