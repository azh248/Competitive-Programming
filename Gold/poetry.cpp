/*
ID: azh248
LANG: C++
TASK: poetry
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back
#define long long long

int n, m, k;
vector<vector<int> > words(5000); // words[i] contains all words in rhyme class i
ll dp[5000]; // possible different poems if i syllables have been used already
int rhymingLines[26]; // rhymingLines[i] = # of lines that have to end in rhyme set i (specified by distance from "A")

ll diffPoems(int syllables) { // takes too much time, if there's many different rhyme classes it's very costly
	if (syllables > k) {
		return 0;
	} else if (syllables == k) {
		return 1;
	} else if (dp[syllables] != -1) {
		return dp[syllables];
	}
	ll sum = 0;                                                                                                                                                                                                                                                                                                                                                                            
	for (int i = 0; i < n; i++) { // source of the problem
		for (int j : words[i]) {
			sum += diffPoems(syllables + j);
			sum %= MOD;
		}
	}
	dp[syllables] = sum;
	return sum;
}

ll modpower(ll x, ll pow) { // x^pow mod (mod) in O(logn) time, recursive
	if (pow == 0) {
		return 1 % MOD;
	}
	ll ret = modpower(x, pow / 2);
	ret = (ret * ret) % MOD;
	if (pow % 2 == 1) {
		ret = (ret * x) % MOD;
	}
	return ret;
}
ll modMultiply(ll a, ll b) {
	ll ret = 0;
	while (b > 0) {
		if (b % 2 == 1) {
			ret += a;
			ret %= MOD;
		}
		a *= 2;
		a %= MOD;
		b /= 2;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("poetry.in", "r", stdin); 
	freopen("poetry.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		int c;
		cin >> c;
		words[c - 1].pb(s);	
	}
	memset(dp, -1, sizeof(dp));
	int rhymeClassWays[5000]; // rhymeClassWays[i] = the number of ways to form a line with rhyme class i
	for (int i = 0; i < n; i++) { // rhyme class i
		ll sum = 0;
		for (int j = 0; j < words[i].size(); j++) { // each word in rhyme class i
			sum += diffPoems(words[i][j]);
			sum %= MOD;
		}
		rhymeClassWays[i] = sum;
	}
	for (int i = 0; i < m; i++) {
		char ch;
		cin >> ch;
		rhymingLines[ch - 'A']++;
	}
	ll numPoems = 1l;
	for (int i = 0; i < 26; i++) {
		if (rhymingLines[i] == 0) {
			continue;
		}
		ll diffWays = 0l;
		for (int j = 0; j < n; j++) {
			diffWays += modpower(rhymeClassWays[j], rhymingLines[i]);
			diffWays %= MOD;
		}
		numPoems = modMultiply(numPoems, diffWays);
		numPoems %= MOD;
	}
	if (numPoems == 1) {
		numPoems = 0;
	}
	cout << numPoems << nl;
}
