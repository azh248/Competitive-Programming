#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	bool filled[26];
	bool paired[26][26]{};
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			paired[i][j] = false;
		}
		filled[i] = false;
	}
	string s = "";
	s += "a";
	while (true) {
		int length = s.length();
		for (int i = 0; i < k; i++) {
			if (!paired[s[s.length() - 1] - 'a'][i] && !filled[i]) {
				paired[s[s.length() - 1] - 'a'][i] = true;
				if (i == k - 1) {
					filled[s[s.length() - 1] - 'a'] = true;
				}
				s += string(1, i + 'a');
				break;
			} 
		}
		if (s.length() == length) {
			break;
		}
	}
	int num = s.length();
	while (num < n) {
		cout << s;
		num += s.length();
	}
	num -= s.length();
	cout << s.substr(0, n - num) << nl;
}
