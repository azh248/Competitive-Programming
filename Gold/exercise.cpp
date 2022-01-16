/*
ID:azh248
LANG:C++
TASK:exercise 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define F0R1(i, a) for (int i = 1; i <= (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i = a; i > 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())
#define S0RT(arr, n) sort(arr, arr + n)

#define pA first
#define pB second
#define nl "\n"
#define pb push_back

int n, m;
int dp[2000][10000]; // dp[i][j] = sum of all k using powers of prime i and above such that the current 
					 // sequence length is j
vector<int> primes;
int sieveResult[10000]{};

void sieve(int n) { // find all prime numbers up to n by marking the composite
					// numbers with their least prime factor
	for (int i = 2; i <= n; i++) {
		if (sieveResult[i] != 0)
			continue;
		primes.pb(i);
		for (int multiple = 2 * i; multiple <= n; multiple += i) {
			sieveResult[multiple] = i;
		}
	}
}

// key observation: you can divide the array into sections that each contain 
// the same numbers as in the same indices of the sorted array (i.e. in 3 2 1 5 4 the 
// sections are the first 3 elements and the last 2, since the first 3 elements 
// cycle back to 1 2 3 every 3 iterations and the last 2 elements cycle back to 4 5 every
// 2 iterations)

// dp[i][j] = sum of all k such that we have a current length of j and the max
// subsequence length you can choose is prime i (we choose subsequences in
// decreasing order to be a self-contained permutation without a cycle until
// it's repeated times equal to its length; then we take the lcm of the
// lengths of all the subsequences to see how many moves it would take for
// the whole array A to cycle back to its original) (we don't need repeat subsequence
// lengths since that doesn't change the lcm);
// it should be only made up of primes and prime powers, since theres no point in having a composite number
// as we can just use its primes and fill the rest with 1's
// only a few 1000 primes/prime powers

// basically sum of all possible lcms of numbers that sum to n

int numPermutes(int prime, int currLen) {
	if (currLen >= n) {
		return 1;
	} else if (prime >= primes.size()) {
		return 1;
	} else if (dp[prime][currLen] != -1) {
		return dp[prime][currLen];
	}
	ll permutes = numPermutes(prime + 1, currLen);
	for (int primePow = primes[prime]; primePow <= n; primePow *= primes[prime]) {
		if (currLen + primePow <= n) {
			permutes += ((ll) primePow) * numPermutes(prime + 1, currLen + primePow); // multiplies the lcm by the power since this is the only occurrence of this prime
			permutes %= m;
		} else {
			break;
		}
	}
	dp[prime][currLen] = permutes;
	return permutes;
}

int main() {
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	sieve(n);
	memset(dp, -1, sizeof(dp));
	cout << numPermutes(0, 0) << nl;
}
