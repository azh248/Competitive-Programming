#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int a, b;
string aBinary, bBinary;

ll dp[32][32][2][2]; // dp[i][j][k][l] = the # of ways to form a round number below a (l == 0) or b (l == 1) if we're on digit i, 
					// we've counted j 0's, and we're under the desired number (k == 0) or we're matching it so far (k == 1)

ll numWays(int digit, int zeroes, int overUnder, int num) { 
	string s = (num == 0) ? aBinary : bBinary;
	if (digit == s.length()) {
		return (zeroes >= ceil(((double)s.length())/(double)2)) ? 1 : 0;
	} else if (dp[digit][zeroes][overUnder][num] != -1) {
		return dp[digit][zeroes][overUnder][num];
	}
	ll ways = 0;
	if (overUnder == 0) {
		ways += numWays(digit + 1, zeroes + 1, 0, num);
		ways += numWays(digit + 1, zeroes, 0, num);
	} else {
		if (s[digit] == '0') {
			ways += numWays(digit + 1, zeroes + 1, 1, num);
		} else {
			ways += numWays(digit + 1, zeroes + 1, 0, num);
			ways += numWays(digit + 1, zeroes, 1, num);
		}
	}
	dp[digit][zeroes][overUnder][num] = ways;
	return ways;
}
string decToBinary(int n) {  
	string ret = "";
    while (n > 0) {   
        ret = to_string(n % 2) + ret; 
        n /= 2; 
    } 
    return ret;
} 

ll aCb(int a, int b) {
	ll ret = 1;
	for (int i = a; i > a - b; i--) {
		ret *= i;
	}
	for (int i = b; i > 1; i--) {
		ret /= i;
	}
	return ret;
}

ll pow2Choose(int n) {
	ll sum = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= floor((i - 1)/2); j++) { // i is the number of 1's
			sum += aCb(i, j);
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	a--;
	// program: we find the number of round numbers below every power of 2 up to 32 using dp -- then, we can find the number of 
	// round numbers below a number and above the previous power of 2 by iterating through both numbers' binary representations, and having a dp
	// that counts the number of ways to form a round number below a number by keeping track of which digit we're on, how many 0's and 1's we've 
	// counted, and whether we're under the desired number or we're matching it so far (if we're under, we can choose any digits as long 
	// as the number is round in the end)
	memset(dp, -1, sizeof(dp));
	aBinary = decToBinary(a);
	bBinary = decToBinary(b); 
	cout << numWays(1, 0, 1, 1) + pow2Choose(bBinary.length() - 1) - (numWays(1, 0, 1, 0) + pow2Choose(aBinary.length() - 1)) << nl;
}	
