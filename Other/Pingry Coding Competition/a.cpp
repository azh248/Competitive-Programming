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
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int minNum = 1e9;
	int maxNum = 0;
	for (int i = 0; i <= n/2; i++) {
		minNum = min(minNum, arr[i]);
	}	
	for (int i = n/2 + 1; i < n; i++) {
		maxNum = max(maxNum, arr[i]);
	}
	cout << minNum + maxNum << nl;
}
