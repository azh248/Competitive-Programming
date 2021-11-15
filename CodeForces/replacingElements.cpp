#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back
#define long long long

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, d;
		cin >> n >> d;
		int arr[n];
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		sort(arr, arr + n);
		if (n == 1) {
			if (arr[0] <= d) {
				cout << "YES" << nl;
				continue;
			}
		}
		if (arr[n - 1] <= d) {
			cout << "YES" << nl;
			continue;
		}
		cout << ((arr[0] + arr[1] > d) ? "NO" : "YES") << nl;
	}
}
