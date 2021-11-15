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
		int n; cin >> n;
		int even = 0;
		int odd = 0;
		for (int i = 0; i < 2 * n; i++) {
			int a; cin >> a;
			if (a % 2 == 0){
				even++;
			} else {
				odd++;
			}
		}	
		if (even == odd) {
			cout << "Yes" << nl;
		}else {
			cout << "No" << nl;
		}
	}	
}