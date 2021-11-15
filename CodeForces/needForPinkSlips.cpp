#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;
double c, m, p, v;
double dp[22][22][10000]; // dp[i][j][k][l] = expected value given that all 3 items are still in play and c has been drawn i times, m has been drawn j times, and p has been drawn k times, and we've moved l times

double expectedValAllItems(int cDraws, int mDraws, int moves) {
	if (moves >= 10000) {
		return moves;
	}
	if (dp[cDraws][mDraws][moves] != -1) {
		return dp[cDraws][mDraws][moves];
	}
	double val = 0;
	double cVal = c - (cDraws) * v + (mDraws) * v / 2;
	double mVal = m - (mDraws) * v + (cDraws) * v / 2;
	double pVal = p + (mDraws + cDraws) * v / 2;
	if ((cVal - v <= 0) || (abs(cVal - v) < 0.0000001)) {
		double mVal1 = mVal + cVal/2;
		double pVal1 = pVal + cVal/2;
		int moves1 = moves + 1;
		double prob = cVal;
		while (mVal1 - v > 0 && abs(mVal1 - v) > 0.0000001) {
			val += pVal1 * prob * (moves1 + 1);
			moves1++;
			prob *= mVal1;
			pVal1 += v;
			mVal1 -= v;
		}
		val += prob * pVal1 * (moves1 + 1);
		prob *= mVal1;
		val += prob * (moves1 + 2); 
	} else {
		val += cVal * expectedValAllItems(cDraws + 1, mDraws, moves + 1);
	}

	if ((mVal - v <= 0) || (abs(mVal - v) < 0.0000001)) {
		double cVal1 = cVal + mVal / 2;
		double pVal1 = pVal + mVal / 2;
		int moves1 = moves + 1;
		double prob = mVal;
		while (cVal1 - v > 0 && abs(cVal1 - v) > 0.0000001) {
			val += pVal1 * prob * (moves1 + 1);
			moves1++;
			prob *= cVal1;
			pVal1 += v;
			cVal1 -= v;
		}
		val += prob * pVal1 * (moves1 + 1);
		prob *= cVal1;
		val += prob * (moves1 + 2);
	} else {
		val += mVal * expectedValAllItems(cDraws, mDraws + 1, moves + 1);
	}

	val += pVal * (moves + 1);

	dp[cDraws][mDraws][moves] = val;
	return val;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> c >> m >> p >> v;
		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 22; j++) {
					for (int l = 0; l < 10000; l++) {
						dp[i][j][l] = -1;
					}
			}
		}
		cout << fixed << setprecision(10) << expectedValAllItems(0, 0, 0) << nl;
	}
}
