/*
ID:azh248
LANG:C++
TASK:skidesign 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);
    cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}	
	int minCost = 1e9;
	for (int i = 0; i < 100; i++) {
		int cost = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j] >= i && arr[j] <= i + 17) {
				continue;
			}
			cost += min((arr[j] - i) * (arr[j] - i), (arr[j] - i - 17) * (arr[j] - i - 17));
		}
		minCost = min(cost, minCost);
	}
	cout << minCost << nl;
}
