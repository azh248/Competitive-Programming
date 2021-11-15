#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back
#define long long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tcaseNum = 0; tcaseNum < t; tcaseNum++) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 9 << nl;
			continue;
		}
		cout << 9 << 8;
		int num = 9;
		for (int i = 2; i < n; i++) {
			cout << num;
			num += 1;
			num %= 10;
		}
		cout << nl;
	}
}
