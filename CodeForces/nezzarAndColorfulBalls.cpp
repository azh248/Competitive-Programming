#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back
#define long long long

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 0; t1 < t; t1++) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}	
		int count[n + 1]{};
		for (int i = 0; i < n; i++) {
			count[arr[i]]++;
		}
		int maxCount = 0;
		for (int i = 0; i <= n; i++) {
			maxCount = max(maxCount, count[i]);
		}
		cout << maxCount << nl;
	}	
}