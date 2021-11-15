#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int dp[500][125251];



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n, l, r, s;
		cin >> n >> l >> r >> s;
		int maxSum = 0;
		for (int i = n - r + l; i <= n; i++) {
			maxSum += i;
		}
		if (maxSum < s) {
			cout << -1 << nl;
			continue;
		}
		int totalSum = 0;
		vector<int> arr;
		for (int i = 1; i <= r - l + 1; i++) {
			arr.pb(i);
			totalSum += i;
		}
		if (totalSum > s) {
			cout << -1 << nl;
			continue;
		}
		for (int i = arr.size() - 1; i >= 0; i--) {
			arr[i] = n - arr.size() + 1 + i;
			totalSum += (n - arr.size() + 1 + i - (i + 1));
			if (totalSum > s) {
				totalSum -= (n - arr.size() + 1 + i - (i + 1));	
				arr[i] = i + 1;
				while (totalSum < s) {
					arr[i]++;
					totalSum++;
				}
			}
		}

		// for (int i = arr.size() - 1; i >= 0; i--) {
		// 	while (totalSum < s && arr[i] <= n - arr.size() + 1 + i) {
		// 		arr[i]++;
		// 		totalSum++;
		// 	}
		// 	if (totalSum == s) {
		// 		break;
		// 	}
		// }
		int endArr[500];
		unordered_set<int> usedElements;
		for (int i = l - 1; i <= r - 1; i++) {
			endArr[i] = arr[i - l + 1];
			usedElements.insert(endArr[i]);
		}
		vector<int> unusedElements;
		for (int i = 1; i <= n; i++) {
			if (usedElements.count(i) == 0) {
				unusedElements.pb(i);
			}
		}
		for (int i = 0; i < l - 1; i++) {
			endArr[i] = unusedElements[unusedElements.size() - 1];
			unusedElements.pop_back();
		}
		for (int i = r; i < n; i++) {
			endArr[i] = unusedElements[unusedElements.size() - 1];
			unusedElements.pop_back();
		}
		for (int i = 0; i < n; i++) {
			cout << endArr[i] << " ";
		}
		cout << nl;
	}	
}
