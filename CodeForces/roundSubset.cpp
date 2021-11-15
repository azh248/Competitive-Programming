#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, k;

int dp[205][205][700][2]; // dp[i][j][k][l] = max roundness possible from number i onwards, given that we've chosen j numbers 
						   // so far and the difference between the power of 2 and power of 5 is k * (l == 0 ? 1 : -1)

int pow2[205]{};
int pow5[205]{};

int maxRoundness(int num, int chosen, int difference, int posNeg) {
	if (chosen == k) {
		return 0;
	} else if (num >= n || chosen > k || difference >= 700) {
		return -1 * 1e9;
	} else if (dp[num][chosen][difference][posNeg] != -1) {
		return dp[num][chosen][difference][posNeg];
	}
	int origDifference = difference;
	int roundness = maxRoundness(num + 1, chosen, difference, posNeg);
	int pow10 = min(pow2[num], pow5[num]);
	int pow2Num = pow2[num];
	int pow5Num = pow5[num];
	pow2Num -= pow10;
	pow5Num -= pow10;
	int multiplyPosNeg = (posNeg == 0) ? 1 : -1;
	if (multiplyPosNeg == 1) {
		pow10 += min(pow5Num, difference);
		difference -= min(pow5Num, difference);
		pow5Num -= min(pow5Num, difference);
	} else {
		pow10 += min(pow2Num, difference);
		difference -= min(pow2Num, difference);
		pow2Num -= min(pow2Num, difference);
	}
	int newPosNeg = ((difference * multiplyPosNeg + pow2Num - pow5Num) < 0) ? 1 : 0;
	int newDifference = abs(difference * multiplyPosNeg + pow2Num - pow5Num); 
	roundness = max(roundness, maxRoundness(num + 1, chosen + 1, newDifference, newPosNeg) + pow10);
	dp[num][chosen][origDifference][posNeg] = roundness;
	return roundness;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		while (num % 2 == 0) {
			num /= 2;
			pow2[i]++;
		}
		while (num % 5 == 0) {
			num /= 5;
			pow5[i]++;
		}
	}	
	memset(dp, -1, sizeof(dp));
	cout << maxRoundness(0, 0, 0, 0) << nl;
}