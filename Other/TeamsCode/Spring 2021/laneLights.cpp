#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m, r;
int arr[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}	
	sort(arr, arr + n);
	int regions = 0;
	if (arr[0] > r) {
		regions++;
	}
	for (int i = 0; i < n - 1; i++) {
		if (arr[i + 1] - arr[i] - 1 > 2*r) {
			regions++;
		}
	}
	if (m - arr[n - 1] - 1 > r) {
		regions++;
	}
	cout << regions << nl;
}
