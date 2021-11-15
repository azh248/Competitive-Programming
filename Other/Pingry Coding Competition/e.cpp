#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;

int arr[100000];

bool workingDist(int dist) {
	int prevDesk = arr[0];
	int teachers = 1;
	for (int i = 0; i < n; i++) {
		if (teachers == m) {
			return true;
		}
		if (arr[i] >= prevDesk + dist) {
			prevDesk = arr[i];
			teachers++;
		}
	}
	return (teachers == m);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}	
	sort(arr, arr + n);
	int l = 0;
	int r = 1e9;
	int ans = l - 1;
	while (l <= r) {
		int mid = (r + l)/2;
		if (workingDist(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << nl;
}
