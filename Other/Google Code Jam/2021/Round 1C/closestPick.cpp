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
	for (int t1 = 1; t1 <= t; t1++) {
		int n, k;
		cin >> n >> k;
		int arr[30];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		int maxRange = 0;
		for (int i = 0; i < n - 1; i++) {
			maxRange = max(maxRange, arr[i + 1] - arr[i] - 1);
		}
		for (int i = -1; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int range = 0;
				if (i == -1) {
					range += arr[0] - 1;
				} else {
					range += (arr[i + 1] - arr[i])/2;
				}
				if (j == n - 1) {
					range += k - arr[n - 1];
				} else {
					range += (arr[j + 1] - arr[j])/2;
				}
				maxRange = max(maxRange, range);
			}
		}
		cout << "Case #" << t1 << ": " << (double)maxRange/(double)k << nl;	
	}	
}