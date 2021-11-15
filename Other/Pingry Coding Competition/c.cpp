#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	int arr[k][n];
	for (int j = 0; j < k; j++) {
		for (int i = 0; i < n; i++) {
			cin >> arr[j][i];
		}
	}	
	int acePairs = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int iWin = 0;
			int jWin = 0;
			for (int a = 0; a < k; a++) {
				if (arr[a][i] > arr[a][j]) {
					iWin++;
				} else if (arr[a][i] < arr[a][j]) {
					jWin++;
				}
			}
			if (iWin >= floor(k/2) + 1 || jWin >= floor(k/2) + 1) {
				acePairs++;
			}
		}
	}
	cout << acePairs << nl;
}
