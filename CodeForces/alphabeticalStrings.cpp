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
		string s; cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'a') {
				char ch = 'b';
				int pointer1 = i - 1;
				int pointer2 = i + 1;
				bool works = false;
				while ((pointer1) >= 0 || (pointer2) < s.length()) {
					if (pointer1 >= 0) {
						if (s[pointer1] == ch) {
							ch++;
							pointer1--;
							continue;
						}
					}
					if (pointer2 < s.length()) {
						if (s[pointer2] == ch) {
							ch++;
							pointer2++;
							continue;
						}
					}
					break;
				}
				if (pointer1 < 0 && pointer2 >= s.length()) {
					cout << "YES" << nl;
				} else {
					cout << "NO" << nl;
				}
				break;
			} else if (i == s.length() - 1) {
				cout << "NO" << nl;
			}
		}
	}
}
