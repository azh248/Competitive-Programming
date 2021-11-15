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
		int arr[200000];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		int minDiff = 1e9;
		int minDiffIndex = -1; 
		for (int i = n - 2; i >= 0; i--) {
			if (arr[i + 1] - arr[i] < minDiff) {
				minDiff = arr[i + 1] - arr[i];
				minDiffIndex = i;
			}
		}
		vector<int> newArr;
		newArr.pb(arr[minDiffIndex]);
		for (int i = minDiffIndex + 2; i < n; i++) {
			newArr.pb(arr[i]);
		}
		for (int i = 0; i < minDiffIndex; i++) {
			newArr.pb(arr[i]);
		}
		newArr.pb(arr[minDiffIndex + 1]);
		for (int i : newArr) {
			cout << i << " ";
		}
		cout << nl;
	}
}