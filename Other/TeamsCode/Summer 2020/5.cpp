#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> n;
	int arr[100];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int totalSum = 0;
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		totalSum += arr[i];
		if (totalSum * (i + 1) > v) {
			cout << i << nl;
			break;
		} else if (i == n - 1) {
			cout << n << nl;
		}
	}
}