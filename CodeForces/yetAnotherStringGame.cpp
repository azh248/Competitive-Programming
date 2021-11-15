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
	for (int t1 = 0; t1 < t; t1++) {
		string s;
		cin >> s;
		int move = 0;
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (move == 0) {
				move++;
				if (c == 'a') {
					s[i] = 'b';
				} else {
					s[i] = 'a';
				}
			} else {
				move = 0;
				if (c == 'z') {
					s[i] = 'y';
				} else {
					s[i] = 'z';
				}
			}
		}	
		cout << s << nl;
	}	
}
