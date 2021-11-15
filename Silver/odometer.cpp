/*
ID:azh248
LANG:C++
TASK:odometer 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

ll x, y;
string s;
int t1, t2;

ll dp[20][2][40][2]; // dp[i][j][k][l] = number of ways to get to the state such that you're on position i, you are/are not under x
					 // (you go from the rightmost digit to the leftmost), you've used k - 20 occurrences of the target number (the number you want
					 // to have >= half occurrences which is changed with each call of the dp), and you currently have/do not have leading zeroes

ll targetDP(int pos, int over, int targOccurrences, int started) {
	if (pos == s.length()) {
		if (!started) {
			return 0;
		}
		if (t2 != -1) {
			return (targOccurrences == 20);
		} else {
			return (targOccurrences >= 20);
		}
	} else if (dp[pos][over][targOccurrences][started] != -1) {
		return dp[pos][over][targOccurrences][started];
	}
	ll val = 0;
	for (int i = 0; i < 10; i++) {
		int nextDig = s[pos] - '0';
		if (over && i > nextDig) { // if it activates at all, it'll activate when i is 0 so we need to break then
			break;
		}
		bool newOver = over;
		if (i < nextDig) { // if at any time we go over the number we break because of the previous if statement, so we're guaranteed that the number is <= and 
						   // we update newover accordingly --> once we go under, it stays under because we go from left to right, and otherwise we're equal to the number so far
			newOver = false;
		}
		bool newStarted = started || (i != 0);
		if (newStarted && t2 != -1 && i != t1 && i != t2) { // when we have 2 targets, every number can only be one of the two targets so we don't want any i that isn't one of the two targets
			continue;
		}
		val += targetDP(pos + 1, newOver, targOccurrences + (newStarted ? ((i == t1) ? 1 : -1) : 0), newStarted); // ternary operators to add to targoccurrences: 
																															   // if we have leading zeroes and i is 0, then 
																															   // we don't want to modify targOccurrences 
																															   // because we haven't started the number yet;
																															   // otherwise we add 1 or subtract 1 depending
																															   // on if i is equal to target 1 (if we have a
																															   // target2 then we can just check if target1 had
																															   // half the occurrences of s's length at the end)
	}
	dp[pos][over][targOccurrences][started] = val;
	return val;
}

ll moos(string str) {
	s = str;
	ll ret = 0;
	for (int targ1 = 0; targ1 <= 9; targ1++) { // actual answer
		memset(dp, -1, sizeof(dp));
		t1 = targ1;
		t2 = -1;
		ret += targetDP(0, 1, 20, 0);
	}
	for (int targ1 = 0;  targ1 <= 9; targ1++) { // overcount since when you have 2 digits that are both half the length of the number, we count that number twice
		for (int targ2 = targ1 + 1; targ2 <= 9; targ2++) {
			memset(dp, -1, sizeof(dp));
			t1 = targ1;
			t2 = targ2;
			ret -= targetDP(0, 1, 20, 0);
		}
	}
	return ret;
}

int main() {
	freopen("odometer.in", "r", stdin);
	freopen("odometer.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> x >> y;
	cout << moos(to_string(y)) - moos(to_string(x - 1)); // interesting numbers <= y minus interesting numbers <= x - 1 to get interesting numbers between x an y
}