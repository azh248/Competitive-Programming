/*
ID:azh248
LANG:C++
TASK:262144 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;

int arr[262150];
int dp[262150][65]; // dp[i][j] = the end index to make 2^j using the sums of the powers of 2 starting from index i (-1 if we can't make 2^j starting from i)

int maxVal(int ind, int pow) {
	if (ind >= n || pow < 1){
		return -2;
	} else if (arr[ind] == pow) {
		return ind + 1;
	} else if (dp[ind][pow] != -1) {
		return dp[ind][pow];
	}
	// we can find this dp value by looking at the 2 ranges that make up this range and each sum up to 2^(pow - 1)
	// therefore, when we combine them we get this range
	int num = maxVal(ind, pow - 1); 
	if (num == -2) {
		dp[ind][pow] = -2;
		return -2;
	}
	int num1 = maxVal(num, pow - 1); // we start where the previous range left off
	if (num1 == -2) {
		dp[ind][pow] = -2;
		return -2;
	}
	dp[ind][pow] = num1;
	return num1;
}

int main() {
	freopen("262144.in", "r", stdin);
	freopen("262144.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// if we take all of the numbers to their power of 2, we know that if a subsequence sums up to a power of 2 then it's collapsible into that power
	memset(dp, -1, sizeof(dp));
	int val = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 65; j++) {
			if (maxVal(i, j) >= 0) {
				val = max(val, j);
			}
		}
	}
	cout << val << nl;
}