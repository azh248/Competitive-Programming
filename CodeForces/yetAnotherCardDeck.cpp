#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	int highest[51];
	for (int i = 1; i <= 50; i++) {
		highest[i] = 1e9;
	}
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (highest[a] == 1e9) {
			highest[a] = i;
		}
	}
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		cout << highest[t] << " ";
		for (int i = 1; i <= 50; i++) {
			if (highest[i] < highest[t]) {
				highest[i]++;
			}
		}
		highest[t] = 1;
	}
	cout << nl;
}
