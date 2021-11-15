#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll arr[100];
		for (int j = 0; j < m; j++) {
			cin >> arr[j];
		}
		sort(arr, arr + m);
		cout << arr[m - 1] * arr[m - 2] << nl;
	}	
}
