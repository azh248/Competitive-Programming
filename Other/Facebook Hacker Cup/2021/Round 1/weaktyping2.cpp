#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	freopen("weak_typing_chapter_2_input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int endFs = 0;
		while (s[n - 1] == 'F') {
			n--;
			endFs++;
			if (n == 0) {
				break;
			}
		}
		if (n == 0) {
			cout << "Case #" << t1 << ": " << 0 << nl;
			continue;
		}
		ll switches = 0;
		ll prevSwitches = 0;
		char prevSwitchChar = s[n - 1];
		int prevSwitchCharLoc = n - 1;
		for (int i = n - 2; i >= 0; i--) {
			if (s[i] == prevSwitchChar || s[i] == 'F') {
				switches += prevSwitches;
				switches %= MOD;
				if (s[i] == prevSwitchChar) {
					prevSwitchCharLoc = i;
				}
			} else {
				prevSwitchChar = s[i];
				prevSwitches += (n - 1 - prevSwitchCharLoc + 1);
				prevSwitches %= MOD;
				switches += prevSwitches;
				switches %= MOD;
				prevSwitchCharLoc = i;
			}
		}
		int currSwitches = 0;
		char currPrevSwitchChar = s[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			if (s[i] != currPrevSwitchChar && s[i] != 'F') {
				currPrevSwitchChar = s[i];
				currSwitches++;
			}
			switches += ((currSwitches * endFs) % MOD);
			switches %= MOD;
		}
		cout << "Case #" << t1 << ": " << switches << nl;
	}
}