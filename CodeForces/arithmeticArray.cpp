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
		int n;
		cin >> n;
		int ret = 0;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			ret += (num - 1);
		}			
		if (ret > 0) {
			cout << ret << nl;
		} else if (ret == 0) {
			cout << 0 << nl;
		} else {
			cout << 1 << nl;
		}
	}	
}