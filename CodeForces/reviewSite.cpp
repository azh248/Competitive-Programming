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
		int arr[50];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int up = 0;
		int down = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] == 1) {
				up++;
			} else if (arr[i] == 2) {
				down++;
			} else {
				up++;
			}
		}
		cout << up << nl;
	}	
}
