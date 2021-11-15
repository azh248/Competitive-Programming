#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;
int arr[100000];

bool works(int num) {
	int days = 1;
	int currDay = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > num) {
			return false;
		}
		if (arr[i] + currDay > num) {
			days++;
			currDay = arr[i];
		} else {
			currDay += arr[i];
		}
	}
	return (days <= m);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];		
	}	
	int l = 0;
	int r = 1e9;
	int ans = l - 1;
	while (l <= r) {
		ll mid = (r + l)/2;
		if (works(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << nl;
}
