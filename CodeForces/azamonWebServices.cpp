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
		string s, c;
		cin >> s >> c;
		if (s < c) {
			cout << s << nl;
			continue;
		}
		int smallestValIndex[5000]; // smallestValIndex[i] = latest occurrence of the smallest value possible that's after or equal to index i
		int smallestVal[5000]; // smallest value after index i
		smallestVal[s.length() - 1] = s[s.length() - 1] - 'A';
		smallestValIndex[s.length() - 1] = s.length() - 1;
		for (int i = s.length() - 2; i >= 0; i--) {
			if (s[i] - 'A' < smallestVal[i + 1]) {
				smallestValIndex[i] = i;
				smallestVal[i] = s[i] - 'A';
			} else {
				smallestVal[i] = smallestVal[i + 1];
				smallestValIndex[i] = smallestValIndex[i + 1];
			}
		}	
		for (int i = 0; i < s.length(); i++) {
			char a = s[i];
			char b = s[smallestValIndex[i]];
			s.replace(i, 1, string(1, b));
			s.replace(smallestValIndex[i], 1, string(1, a));
			if (s < c) {
				cout << s << nl;
				break;
			}
			char a1 = s[i];
			char b1 = s[smallestValIndex[i]];
			s.replace(i, 1, string(1, b1));
			s.replace(smallestValIndex[i], 1, string(1, a1));	
			if (i == s.length() - 1) {
				cout << "---" << nl;
			}
		}
	}	
}