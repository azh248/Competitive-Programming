#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int arr[5000];
	int pSum[5000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0) {
			pSum[0] = arr[0];
		} else {
			pSum[i] = pSum[i - 1] + arr[i];
		}
	}	
	int longest = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == 0) {
				if (pSum[j] > 100 * (j - i + 1)) {
					longest = max(longest, j - i + 1);
				}
			} else if (pSum[j] - pSum[i - 1] > 100 * (j - i + 1)) {
				longest = max(longest, j - i + 1);
			}
		}
	}
	cout << longest << nl;
}
