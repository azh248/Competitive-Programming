/*
ID:azh248
LANG:C++
TASK:sprime 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n;

bool prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

vector<int> sPrimes;

void findSPrimes(int num) {
	if (!prime(num)) {
		return;
	} else if (num/(pow(10, n)) >= 1) {
		sPrimes.pb(num);
		return;
	}
	findSPrimes(10*num + 1);
	findSPrimes(10*num + 3);
	findSPrimes(10*num + 5);
	findSPrimes(10*num + 7);
	findSPrimes(10*num + 9);
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
    cin >> n;
	n--;
	findSPrimes(2);
	findSPrimes(3);
	findSPrimes(5);
	findSPrimes(7);
	sort(sPrimes.begin(), sPrimes.end());
	for (int i : sPrimes) {
		cout << i << nl;
	}
}
