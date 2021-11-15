#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;

double dp[301][301][301];

double expectedOperations(int onePiece, int twoPiece, int threePiece) {
	if (onePiece < 0 || twoPiece < 0 || threePiece < 0) {
		return -1;
	} else if (onePiece == 0 && twoPiece == 0 && threePiece == 0) {
		return 0;
	} else if (dp[onePiece][twoPiece][threePiece] != -1) {
		return dp[onePiece][twoPiece][threePiece];
	}
	double i = onePiece; 
	double j = twoPiece;
	double k = threePiece;
	double expectedNum = ((double) 1/(double) (i + j + k)) * (i * (expectedOperations(i - 1, j, k) + 1) + j * (expectedOperations(i + 1, j - 1, k) + 1) + k * (expectedOperations(i, j + 1, k - 1) + 1) + (n - i - j - k));
	dp[onePiece][twoPiece][threePiece] = expectedNum;
	return expectedNum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int arr[3]{};
	for (int i = 0; i < n; i++) {
		int pieces;
		cin >> pieces;
		arr[pieces - 1]++;
	}	
	for (int i = 0; i <= 300; i++) {
		for (int j = 0; j <= 300; j++) {
			for (int k = 0; k <= 300; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	cout << fixed << setprecision(10) << expectedOperations(arr[0], arr[1], arr[2]) << nl;
}
