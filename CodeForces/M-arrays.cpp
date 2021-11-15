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
		int n, m;
		ll arr[100001];
		ll modM[100001]{};
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			modM[(arr[i] % m)]++;
		}
		ll arrays = 0;
		if (modM[0] > 0) {
			arrays++;
		}
		for (int i = 1; i + i < m; i++) {
			if (modM[i] == 0 && modM[m - i] == 0) {
				continue;
			}
			if (modM[i] > modM[m - i]) {
				arrays += (modM[i] - modM[m - i] - 1) + 1;
			} else if (modM[m - i] > modM[i]) {
				arrays += (modM[m - i] - modM[i] - 1) + 1;
			} else {
				arrays++;
			} 
		}
		if (m % 2 == 0 && modM[m/2] > 0) {
			arrays++;
		}
		cout << arrays << nl;
	}	
}
