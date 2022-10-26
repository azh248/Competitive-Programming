#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define F0R1(i, a) for (int i = 1; i <= (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i = a; i > 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())
#define S0RT(arr, n) sort(arr, arr + n)

#define pA first
#define pB second
#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	string dummy;
	getline(cin, dummy);
	while (t--) {
		string s[26];
		FOR(i, 0, 26) {
			getline(cin, s[i]);
			s[i] = s[i].substr(2, s[i].size() - 2);
		}
		string encrypt;
		getline(cin, encrypt);
		FOR(i, 0, encrypt.size()) {
			if (encrypt[i] == ' ') {
				cout << "    ";
			} else {
				if (i == encrypt.size() - 1) {
					cout << s[encrypt[i] - 'A'] << nl;	
				} else {
					cout << s[encrypt[i] - 'A'] << "   ";
				}
			}
		}
		string decrypt;
		getline(cin, decrypt);
		int inWord = 0;
		string currentLetter = "";
		for (int i = 0; i < decrypt.size(); i += 2) {
			if (decrypt[i] == ' ') {
				if (inWord == 0) {
					currentLetter = currentLetter.substr(0, currentLetter.size() - 1);
					inWord = 1;
					for (int j = 0; j < 26; j++) {
						if (s[j] == currentLetter) {
							cout << string(1, char(j + 'A'));
							break;
						}
					}
					currentLetter = "";
				} else if (inWord == 2) {
					cout << " ";
				}
				inWord++;
			} else {
				inWord = 0;
				currentLetter += string(1, decrypt[i]) + " ";
			}
		}
		currentLetter = currentLetter.substr(0, currentLetter.size() - 1);
		inWord = 1;
		for (int j = 0; j < 26; j++) {
			if (s[j] == currentLetter) {
				cout << string(1, char(j + 'A'));
				break;
			}
		}
		currentLetter = "";
		cout << nl;
	}	
}
