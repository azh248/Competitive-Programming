#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, k;
string s;

int dp[100000][4][2];
vector<int> letters[100000];
int pSums[100000][3];

int maxPoints(int pos, int prevChar, int kLetters) {
	if (pos >= n) {
		return 0;
	} else if (dp[pos][prevChar][kLetters] != -1) {
		return dp[pos][prevChar][kLetters];
	}
	int points = 0;
	points = max(points, maxPoints(pos + 1, prevChar, kLetters) + (pos + 1 == n ? 0 : pSums[pos + 1][prevChar] - pSums[pos][prevChar])); // continue with this letter
	if (pos + k < n) {
		points = max(points, maxPoints(pos + k, prevChar, 1) + pSums[pos + k][prevChar] - pSums[pos][prevChar]);
		for (int i = 0; i < 3; i++) {
			if (i != prevChar) {
				points = max(points, maxPoints(pos + k, i, 0) + pSums[pos + k - 1][prevChar] - pSums[pos][prevChar] + pSums[pos + k][i] - pSums[pos + k - 1][i]);
			}
		}
	} 
	if (kLetters == 1) {
		for (int i = 0; i < 3; i++) {
			if (i != prevChar) {
				points = max(points, maxPoints(pos + 1, i, 0) + (pos + 1 == n ? 0 : pSums[pos + 1][i] - pSums[pos][i]));
			}
		}
	}
	dp[pos][prevChar][kLetters] = points;
	return points;
}

int main() {
	// freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	cin >> s;
	int count[3]{};
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') {
			count[0]++;
		} else if (s[i] == 'B') {
			count[1]++;
		} else {
			count[2]++;
		}
		if (count[0] > count[1]) {
			if (count[0] > count[2]) {
				letters[i] = {0};
			} else if (count[0] < count[2]) {
				letters[i] = {2};
			} else {
				letters[i] = {0, 2};
			}
		} else {
			if (count[0] < count[1]) {
				if (count[1] == count[2]) {
					letters[i] = {1, 2};
				} else if (count[1] > count[2]) {
					letters[i] = {1};
				} else {
					letters[i] = {2};
				}
			} else {
				if (count[0] == count[2]) {
					letters[i] = {0, 1, 2};
				} else if (count[0] > count[2]) {
					letters[i] = {0, 1};
				} else {
					letters[i] = {2};
				}
			}
		}
	}
	pSums[0][letters[0][0]] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			pSums[i][j] = pSums[i - 1][j];
		}
		for (int num : letters[i]) {
			pSums[i][num]++;
		}
	} 
	memset(dp, -1, sizeof(dp));
	// add the initial value to each dp because i don't account for that
	int points = 0;
	for (int i = 0; i < 3; i++) {
		points = max(points, maxPoints(0, i, 0) + pSums[0][i]);
	}
	cout << points << nl;
}