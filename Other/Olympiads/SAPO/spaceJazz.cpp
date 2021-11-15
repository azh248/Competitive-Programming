#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

string s;

int dp[500][500];

int minNotes(int l, int r) { // need an end condition (i.e. single letter)
	if (l > r) {
		return 0;
	} else if (r >= s.length() || l >= s.length() || r < 0) {
		return 1e5;
	} else if (dp[l][r] != -1) {
		return dp[l][r];
	}
	int notes = 1e5;
	for (int i = l + 1; i <= r; i++) {
		if (s[i] == s[l]) {
			notes = min(notes, minNotes(l + 1, i - 1) + minNotes(i + 1, r));
		} 
	}
	notes = min(notes, minNotes(l + 1, r) + 1);
	dp[l][r] = notes;
	return notes;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	memset(dp, -1, sizeof(dp));
	cout << minNotes(0, s.length() - 1) << nl;
}
