#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

char numToCh(int i) {
	return (i == 0) ? '(' : ')';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		string s;
		cin >> s; 
		bool works = false;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					if (works) {
						break;
					}
					string newS = s;
					for (int l = 0; l < s.length(); l++) {
						if (s[l] == 'A') {
							newS[l] = numToCh(i);
						} else if (s[l] == 'B') {
							newS[l] = numToCh(j);
						} else if (s[l] == 'C') {
							newS[l] = numToCh(k);
						}
					}
					int totalParentheses = 0;
					for (int l = 0; l < newS.length(); l++) {
						if (newS[l] == '(') {
							totalParentheses++;
						} else {
							totalParentheses--;
						}
						if (totalParentheses < 0) {
							break;
						} else if (l == newS.length() - 1) {
							works = (totalParentheses == 0);
							break;
						}
					}
				}
			}
		}
		cout << (works ? "YES" : "NO") << nl;
		// char ch = s[0];
		// int aCount = 0;
		// int bCount = 0;
		// int cCount = 0;
		// for (int i = 0; i < s.length(); i++) {
		// 	if (s[i] == 'A') {
		// 		aCount++;
		// 	} else if (s[i] == 'B') {
		// 		bCount++;
		// 	} else {
		// 		cCount++;
		// 	}
		// }
		// if ()	
	}	
}
