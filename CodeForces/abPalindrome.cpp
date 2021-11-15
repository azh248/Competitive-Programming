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
		int a, b; cin >> a >> b;
		string s;
		cin >> s;
		int n = s.length();
		vector<int> questionMarks; // locations of all places where an index and its palindromic flipped index are both ?
		bool cont = false;
		for (int i = 0; i * 2 < n - 1; i++) {
			if (s[i] != '?') {
				if (s[n - 1 - i] != '?') {
					if (s[i] != s[n - 1 - i]) {
						cont = true;
						break;
					} else {
						if (s[i] == '0') {
							a -= 2;
						} else {
							b -= 2;
						}
					}
				} else {
					if (s[i] == '0') {
						a -= 2;
					} else {
						b -= 2;
					}
					s[n - 1 - i] = s[i];
				}
			} else if (s[n - 1 - i] != '?') {
				if (s[n - 1 - i] == '0') {
					a -= 2;
				} else {
					b -= 2;
				}
				s[i] = s[n - 1 - i];
			} else {
				questionMarks.pb(i);
			}
		}
		if (n % 2 == 1) {
			if (s[n/2] == '0') {
				a--;
			} else if (s[n/2] == '1') {
				b--;
			} else {
				if (a % 2 == 1) {
					if (b % 2 == 1) {
						cout << -1 << nl;
						continue;
					} else {
						a--;
						s[n/2] = '0';
					}
				} else if (b % 2 == 1) {
					b--;
					s[n/2] = '1';
				} else {
					cout << -1 << nl;
					continue;
				}
			}
		}
		if (cont || a < 0 || b < 0 || (a + b) != questionMarks.size() * 2 || a % 2 != 0 || b % 2 != 0) {
			cout << -1 << nl;
			continue;
		}
		while (a > 0) {
			int index = questionMarks[questionMarks.size() - 1];
			questionMarks.pop_back();
			s[index] = '0';
			s[n - 1 - index] = '0';
			a -= 2;
		}
		while (b > 0) {
			int index = questionMarks[questionMarks.size() - 1];
			questionMarks.pop_back();
			s[index] = '1';
			s[n - 1 - index] = '1';	
			b -= 2;
		}
		cout << s << nl;
	}	
}
