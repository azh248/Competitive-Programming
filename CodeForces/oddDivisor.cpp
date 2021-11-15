#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back
#define long long long

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		while (num % 2 == 0) {
			num /= 2;
		}	
		cout << (num == 1 ? "NO" : "YES") << nl;
	}	
}
