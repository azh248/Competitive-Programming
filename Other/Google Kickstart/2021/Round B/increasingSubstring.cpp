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
	for (int t1 = 1; t1 <= t; t1++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		cout << "Case #" << t1 << ": " << 1 << " ";
		int len = 1;
		for (int i = 1; i < n; i++) {
			if (s[i] - 'A' > s[i - 1] - 'A') {
				len++;
				cout << len << " ";
			} else {
				len = 1;
				cout << len << " ";
			}
		}
		cout << nl;
	}	
}