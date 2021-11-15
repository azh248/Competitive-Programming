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
		ll arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}	
		sort(arr, arr + n);
		ll possibleWinners = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[j] >= arr[i]) {
					break;
				} else {
					possibleWinners++;
					break;
				}
			}
		}
		cout << possibleWinners << nl;
	}	
}