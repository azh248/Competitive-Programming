#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 1000000007
#define nl "\n"
#define pub push_back
#define pob pop_back

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int arr[n];
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		} 
		int res[n]{};
		for (int j = n - 1; j >= 0; j--) {
			int next = j + arr[j];
			if (next >= n) {
				res[j] = next;
			} else {
				res[j] = res[next];
			}
		}
		int maxScore = 0;
		for (int j = 0; j < n; j++) {
			maxScore = max(maxScore, res[j] - j - 1);
		}
		cout << maxScore + 1 << nl;
	}
}
