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
		char arr[400][400];
		vector<pii> corners;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '*') {
					corners.pb({i, j});
				}
			}
		}
		if (corners[0].first == corners[1].first) {
			if (corners[0].first == 0) {
				arr[1][corners[0].second] = '*';
				arr[1][corners[1].second] = '*';	
			} else {
				arr[0][corners[0].second] = '*';
				arr[0][corners[1].second] = '*';
			}
		} else if (corners[0].second == corners[1].second) {
			if (corners[0].second == 0) {
				arr[corners[0].first][1] = '*';
				arr[corners[1].first][1] = '*';
			} else {
				arr[corners[0].first][0] = '*';
				arr[corners[1].first][0] = '*';	
			}
		} else {
			arr[corners[0].first][corners[1].second] = '*';
			arr[corners[1].first][corners[0].second] = '*';
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j];
			}
			cout << nl;
		}
	}	
}
