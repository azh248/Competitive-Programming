#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
int arr[100000];
int sortedArr[100000];

int placement(int arr[], int l, int r, int score) {
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if ((mid == 0 || score > arr[mid - 1]) && arr[mid] == score) {
			return mid;
		} else if (score > arr[mid]) {
			return placement(arr, (mid + 1), r, score);
		} else {
			return placement(arr, l, (mid - 1), score);
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sortedArr[i] = 10000 - arr[i];			
	}	
	sort(sortedArr, sortedArr + n);
	for (int i = 0; i < n; i++) {
		cout << placement(sortedArr, 0, n - 1, 10000 - arr[i]) + 1 << " ";
	}
	cout << nl;
}
