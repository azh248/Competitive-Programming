/*
ID: azh248
LANG: C++
TASK:nocross 
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

int n;
int leftFields[1000]{}; // leftFields[i] contains the left field location of field i
int rightFields[1000]{}; // rightFields[i] contains the right field location of field i
int leftFields2[1000]{}; // leftFields2[i] = field at left location i
int rightFields2[1000]{};
int dp[1000][1000]{};

int maxCrosswalks(int l, int r) { // location of top left crosswalk, top right crosswalk
	// go up through each field on both sides of the road - at each stage, we can choose 
	// to either connect the left side or connect the right side. we always want to connect to the nearerst neighbor.
	if (l >= n || r >= n) {
		return 0;
	} else if (dp[l][r] != -1) {
		return dp[l][r];
	}
	int maxCross = 0;
	int closestLeftField = 1000000000;
	for (int right = r + 1; right < n; right++) {
		for (int i = rightFields2[right] - 4; i <= rightFields2[right] + 4; i++) {
			if (i >= n) {
				break;
			} else if (i < 0) {
				continue;
			} else if (i == right) {
				continue;
			}
			if (leftFields[i] > l) {
				closestLeftField = min(closestLeftField, leftFields[i]);
			}
		}
		maxCross = max(maxCross, maxCrosswalks(closestLeftField, right) + 1);
		closestLeftField = 1000000000;
	}
	int closestRightField = 1000000000;
	for (int left = l + 1; left < n; left++) {
		for (int i = leftFields2[left] - 4; i <= leftFields2[left] + 4; i++) {
			if (i >= n) {
				break;
			} else if (i < 0) {
				continue;
			} else if (i == left) {
				continue;
			}
			if (rightFields[i] > r) {
				closestRightField = min(closestRightField, rightFields[i]);
			}
		}
		maxCross = max(maxCross, maxCrosswalks(left, closestRightField) + 1);
		closestRightField = 1000000000;
	}
	dp[l][r] = maxCross;
	return maxCross;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int field;
		cin >> field;
		leftFields[field - 1] = i;
		leftFields2[i] = field - 1;
	}
	for (int i = 0; i < n; i++) {
		int field;
		cin >> field;
		rightFields[field - 1] = i;
		rightFields2[i] = field - 1;
	}
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			dp[i][j] = -1;
		}
	}
	int maxCross = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			maxCross = max(maxCross, maxCrosswalks(i, j));
		}
	}
	cout << maxCross << nl;
}
