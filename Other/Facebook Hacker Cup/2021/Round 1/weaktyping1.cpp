#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	freopen("weak_typing_chapter_1_input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		int n; cin >> n;
		string s; cin >> s;
		string w = "";
		for (int i = 0; i < n; i++) {
			if (s[i] != 'F') {
				w += string(1, s[i]);
			}
		}
		int switches = 0;
		for (int i = 1; i < w.length(); i++) {
			if (w[i] != w[i - 1]) {
				switches++;
			}
		}
		cout << "Case #" << t1 << ": " << switches << nl;
	}
}