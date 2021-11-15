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
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		ll sum = arr[0];
		bool worked = true;
		for (int i = 1; i < n; i++) {
			sum += arr[i];
			if (sum < (i * (i + 1)) / 2) {
				cout << "NO" << nl;
				worked = false;
				break;
			}
		}	
		if (worked) {
			cout << "YES" << nl;
		}
	}	
}
