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
		int h, w; cin >> h >> w;
		int plates1 = 0;
		int arr[20][20]{};
		for (int i = 0; i < h; i += 2) {
			arr[i][0] = 1;
		}
		for (int i = 2; i < w; i += 2) {
			arr[0][i] = 1;
			arr[h - 1][i] = 1;
		}
		for (int i = 2; i < h - 2; i += 2) {
			arr[i][w - 1] = 1;
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << arr[i][j];
			}
			cout << nl;
		}
		cout << nl;
	}
}