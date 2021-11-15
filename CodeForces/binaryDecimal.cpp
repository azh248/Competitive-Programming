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
		string s = to_string(n);
		int maxDigit = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] - '0' > maxDigit) {
				maxDigit = s[i] - '0';
			}
		}
		
		cout << maxDigit << nl;
	}
}