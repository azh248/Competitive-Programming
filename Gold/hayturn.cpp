/*
ID:azh248
LANG:C++
TASK:hayturn 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
int bales[700000];

int main() {
	freopen("hayturn.in", "r", stdin);
	freopen("hayturn.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> bales[i];
	}
	ll maxB = 0;
	ll maxD = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (bales[i] + maxD >= maxB) {
			maxD += bales[i];
			swap(maxB, maxD);
		}
	}
	cout << maxB << " " << maxD << nl;
}