#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int pow2 = 0;
		while (n % 2 == 0) {
			n /= 2;
			pow2++;
		}	
		if (n == 1) {
			cout << fixed << setprecision(0) << pow(2, pow2 - 1) << " ";
			cout << fixed << setprecision(0) << pow(2, pow2 - 2) << " ";
			cout << fixed << setprecision(0) << pow(2, pow2 - 2) << nl;
		} else {
			cout << fixed << setprecision(0) << pow(2, pow2) << " ";
			cout << fixed << setprecision(0) << pow(2, pow2) * (n - 1)/2 << " ";
			cout << fixed << setprecision(0) << pow(2, pow2) * (n - 1)/2 << nl;
		}
	}	
}
