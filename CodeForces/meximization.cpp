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
		sort(arr, arr + n);
		// vector<int> nums;
		// for (int i = 0; i < n; i++) {
		// 	for (int j = i + 1; j < n; j++) {
		// 		if (arr[i] == arr[j] || arr[i] < 0) {
		// 			i++;
		// 			nums.pb(arr[i]);
		// 			break;
		// 		}
		// 	}
		// }
		int elements[101]{};
		int printed[101]{};
		for (int i = 0; i < n; i++) {
			elements[arr[i]]++;
		}
		for (int i : arr) {
			if (i >= 0 && printed[i] == 0) {
				cout << i << " ";
				printed[i]++;
				elements[i]--;
			}
		}
		for (int i : arr) {
			if (elements[i] >= 1 || i < 0) {
				cout << i << " ";
				elements[i]--;
			}
		}
		cout << nl;
		// set<int> bruh;
		// for (int i = 0; i < n; i++) {
		// 	bruh.insert(arr[i]);
		// }
		// for (int i : bruh) {
		// 	if (i >= 0) {
		// 		cout << i << " ";
		// 	}
		// }

		// for (int i : nums) {
		// 	cout << i << " ";
		// }
		// cout << nl;
	}	
}
