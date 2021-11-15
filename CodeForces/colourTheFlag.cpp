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
		cin >> n >> m;
		char arr[50][50];
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				arr[i][j] = s[j];
			}
		}
		char arr1[50][50];
		char arr2[50][50];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i % 2 == 0) {
					if (j % 2 == 0) {
						arr1[i][j] = 'W';
						arr2[i][j] = 'R';
					} else {
						arr1[i][j] = 'R';
						arr2[i][j] = 'W';
					}
				} else {
					if (j % 2 == 0) {
						arr1[i][j] = 'R';
						arr2[i][j] = 'W';
					} else {
						arr1[i][j] = 'W';
						arr2[i][j] = 'R';
					}
				}
			}
		}
		bool works1 = true;
		bool works2 = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != '.' && arr[i][j] != arr1[i][j]) {
					works1 = false;
				}
				if (arr[i][j] != '.' && arr[i][j] != arr2[i][j]) {
					works2 = false;
				}
			}
		}
		if (works1) {
			cout << "YES" << nl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << string(1, arr1[i][j]);
				}
				cout << nl;
			}
		} else if (works2) {
			cout << "YES" << nl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << string(1, arr2[i][j]);
				}
				cout << nl;
			}
		} else {
			cout << "NO" << nl;
		}
	}
}