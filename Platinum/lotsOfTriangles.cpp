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
pii trees[300];
double belowLine[300][300]; // number of points that are below this line and have x values bounded by the line
int val[300]{};

int main() {
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> trees[i].first >> trees[i].second;
	}
	sort(trees, trees + n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int x1 = trees[i].first;
			int y1 = trees[i].second;
			int x2 = trees[j].first;
			int y2 = trees[j].second;
			belowLine[i][j] = 0;
			if (x1 == x2) {
				continue;
			}
			double slope = (double)(y2 - y1)/(x2 - x1);
			double yIntercept = y1 - slope * x1;
			for (int k = 0; k < n; k++) {
				if (trees[k].first < x1) {
					continue;
				} else if (trees[k].first > x2) {
					break;
				}
				if (trees[k].first == x1 || trees[k].first == x2) {
					if ((trees[k].first == x1 && trees[k].second < y1) || (trees[k].first == x2 && trees[k].second < y2)) {
						belowLine[i][j] += 0.5;
					}
					continue;
				}
				if ((trees[k].second <= slope * trees[k].first + yIntercept) || (abs(slope * trees[k].first + yIntercept - trees[k].second) <= 0.000001)) {
					belowLine[i][j]++;
				}
			}
			belowLine[j][i] = belowLine[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				// find top 2 lines (or 1 if it's horizontal), lot value is sum of below top line(s) - below bottom line(s)
				double points = 0;
				int x1 = trees[i].first;
				int y1 = trees[i].second;
				int x2 = trees[j].first;
				int y2 = trees[j].second;
				int x3 = trees[k].first;
				int y3 = trees[k].second;
				// check if there's a vertical line
				if (x1 == x2) {
					if (y1 > y2) {
						points += belowLine[i][k] - 0.5;
						points -= belowLine[j][k];
					} else {
						points += belowLine[j][k] - 0.5;
						points -= belowLine[i][k];
					}
					val[(int)points]++;
					continue;
				} else if (x2 == x3) {
					if (y2 > y3) {
						points += belowLine[i][j] - 0.5;
						points -= belowLine[i][k];
					} else {
						points += belowLine[i][k] - 0.5;
						points -= belowLine[i][j];
					}
					val[(int)points]++;
					continue;
				}
				// x2 is always middle point
				double slope = (double)(y3 - y1)/(x3 - x1);
				double yIntercept = y1 - slope * x1;
				if (y2 <= slope * x2 + yIntercept || (abs(slope * x2 + yIntercept - y2) <= 0.0000001)) { // 1 top line, the middle point is below the top line
					points += belowLine[i][k] - 1;
					points -= belowLine[i][j] + belowLine[j][k];
				} else { // 2 top lines, the middle point is above the bottom line
					points += belowLine[i][j] + belowLine[j][k];
					points -= belowLine[i][k];
				}
				val[(int)points]++;
			}
		}
	}
	for (int i = 0; i < n - 2; i++) {
		cout << val[i] << nl;
	}
}