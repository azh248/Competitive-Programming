/*
ID:azh248
LANG:C++
TASK:triangles 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
bool cow[600][600]{};
int pSumsX[600][600]; // [i][j] = pSums for row i
int pSumsY[600][600]; // [j][i] = pSums for column j
vector<int> xCows[600]; // cows at this x position
vector<int> yCows[600]; // cows at this y position

int main() {
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '*') {
				cow[i - j + 300][i + j] = true; // conversion to chebyshev coordinates
				xCows[i - j + 300].pb(i + j);
				yCows[i + j].pb(i - j + 300);
			}
		}
	}
	n = 600;
	for (int i = 0; i < n; i++) {
		pSumsX[i][0] = cow[i][0];
		for (int j = 1; j < n; j++) {
			pSumsX[i][j] = pSumsX[i][j - 1] + cow[i][j];
		}
	}
	for (int j = 0; j < n; j++) {
		pSumsY[j][0] = cow[0][j];
		for (int i = 0; i < n; i++) {
			pSumsY[j][i] = pSumsY[j][i - 1] + cow[i][j];
		}
	}
	// sweep through x and y lines, all equilateral triangles with chebyshev coordinates have a side
	// with slope 0 or infinity, so we just fix 2 points and use prefix sums for the third
	int totalTriangles = 0;
	for (int i = 0; i < n; i++) {
		for (int cow1 = 0; cow1 < xCows[i].size(); cow1++) {
			for (int cow2 = cow1 + 1; cow2 < xCows[i].size(); cow2++) {
				int cow1Y = xCows[i][cow1];
				int cow2Y = xCows[i][cow2];
				int dist = abs(cow1Y - cow2Y);
				if (dist == 0) {
					continue;
				}
				if (i - dist >= 0) {
					totalTriangles += pSumsX[i - dist][max(cow1Y, cow2Y)] - ((min(cow1Y, cow2Y) == 0) ? 0 : pSumsX[i - dist][min(cow1Y, cow2Y) - 1]);
				}
				if (i + dist < n) {
					totalTriangles += pSumsX[i + dist][max(cow1Y, cow2Y)] - ((min(cow1Y, cow2Y) == 0) ? 0 : pSumsX[i + dist][min(cow1Y, cow2Y) - 1]);
				}
			}
		}
	}
	for (int j = 0; j < n; j++) {
		for (int cow1 = 0; cow1 < yCows[j].size(); cow1++) {
			for (int cow2 = cow1 + 1; cow2 < yCows[j].size(); cow2++) {
				int cow1X = yCows[j][cow1];
				int cow2X = yCows[j][cow2];
				int dist = abs(cow1X - cow2X);
				if (dist == 0) {
					continue;
				}
				if (j - dist >= 0) {
					totalTriangles += pSumsY[j - dist][max(cow1X, cow2X)] - ((min(cow1X, cow2X) == 0) ? 0 : pSumsY[j - dist][min(cow1X, cow2X) - 1]);
					totalTriangles -= cow[min(cow1X, cow2X)][j - dist];
					totalTriangles -= cow[max(cow1X, cow2X)][j - dist];
				}
				if (j + dist < n) {
					totalTriangles += pSumsY[j + dist][max(cow1X, cow2X)] - ((min(cow1X, cow2X) == 0) ? 0 : pSumsY[j + dist][min(cow1X, cow2X) - 1]);
					totalTriangles -= cow[min(cow1X, cow2X)][j + dist];
					totalTriangles -= cow[max(cow1X, cow2X)][j + dist];
				}
			}
		}
	}
	cout << totalTriangles << nl;
}