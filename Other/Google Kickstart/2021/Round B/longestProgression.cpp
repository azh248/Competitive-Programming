#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<pair<int, int>, pair<int, int>>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// freopen("a.in", "r", stdin);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		int n;
		cin >> n;
		int arr[300000];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int differences[300000];
		for (int i = 0; i < n - 1; i++) {
			differences[i] = arr[i + 1] - arr[i];
		}

		int longestContiguous[300000]; // longest same difference starting with i

		longestContiguous[n - 2] = 1;

		for (int i = n - 3; i >= 0; i--) {
			if (differences[i] == differences[i + 1]) {
				longestContiguous[i] = longestContiguous[i + 1] + 1;
			} else {
				longestContiguous[i] = 1;
			}
		}

		// a, a, a, ..... b, -b, a, a, a, ....

		int maxLength = 1;		

		for (int i = 0; i < n - 2; i++) {
			maxLength = max(maxLength, 1 + longestContiguous[i + 1]);
		}

		int num = differences[0];
		int aRange = 1;
		for (int i = 1; i < n - 1; i++) {
			if (differences[i] == num) {
				aRange++;
				maxLength = max(maxLength, aRange);
			} else {
				aRange++;
				if (i < n - 2) {
					if (differences[i + 1] + differences[i] == 2 * differences[i - 1]) {
						aRange++;
						if (i < n - 3 && differences[i + 2] == num) {
							aRange += longestContiguous[i + 2];
						}
					} else {
						if (i < n - 2 && differences[i - 1] + differences[i] == 2 * differences[i + 1]) {
							if (i < 2 || differences[i - 2] == differences[i + 1]) {
								aRange += longestContiguous[i + 1];
							} else if (i >= 2) {
								maxLength = max(maxLength, aRange);
								aRange = 2 + longestContiguous[i + 1];
							}
						} 
					}
				}
				maxLength = max(maxLength, aRange);
				num = differences[i];
				aRange = 1;
			}
		}
		cout << "Case #" << t1 << ": " << maxLength + 1 << nl;
	}	
}