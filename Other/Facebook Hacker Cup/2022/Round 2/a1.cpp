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
int prefixChars[1000001][26];

int main() {
    freopen("perfectly_balanced_chapter_1_input.txt", "r", stdin);
    freopen("a1Test.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		string s;
		cin >> s;
		for (int j = 0; j < 26; j++) {
			prefixChars[0][j] = 0;
		}
		for (int i = 1; i <= s.length(); i++) {
			for (int j = 0; j < 26; j++) {
				prefixChars[i][j] = prefixChars[i - 1][j];
			}
			prefixChars[i][s[i - 1] - 'a']++;
		}
		int q; cin >> q;
		int cnt = 0;
		FOR(i, 0, q) {
			int l, r; cin >> l >> r;
			if ((r - l + 1) % 2 == 0) {
				continue;
			} else if ((r - l + 1) == 1) {
				cnt++;
				continue;
			}
			int half = l + (r - l) / 2;
			int extraChars1 = 0;
			int extraChars2 = 0;
			for (int j = 0; j < 26; j++) {
				// minimize the differences in characters between first half and second half
				int val1 = abs((prefixChars[r][j] - prefixChars[half][j]) - (prefixChars[half][j] - prefixChars[l - 1][j]));
				int val2 = abs((prefixChars[r][j] - prefixChars[half - 1][j]) - (prefixChars[half - 1][j] - prefixChars[l - 1][j]));
				extraChars1 += val1;
				extraChars2 += val2;
			}
			// cout << (to_string(extraChars1) + to_string(extraChars2)) << nl;
			if (min(extraChars1, extraChars2) <= 1) {
				cnt++;
			}
		}
		cout << "Case #" << t1 << ": " << cnt << nl;		
	}	
}