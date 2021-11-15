#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n" 
#define pb push_back
#define long long long

int t;

int sieveResult[200000]{};

void sieve(int n) { // find all prime numbers up to n by marking the composite numbers with their least prime factor
    for (int i = 2; i <= n; i++) {
        if (sieveResult[i] != 0)
            continue;
        for (int multiple = 2 * i; multiple <= n; multiple += i) {
            sieveResult[multiple] = i;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve(30010);
    cin >> t;
    for (int tcaseNum = 0; tcaseNum < t; tcaseNum++) {
		int d;
		cin >> d;
		ll primeA, primeB;
		for (int i = d + 1; i < 30010; i++) {
			if (sieveResult[i] == 0) {
				primeA = i;
				break;
			}
		}
		for (int i = primeA + d; i < 30010; i++) {
			if (sieveResult[i] == 0) {
				primeB = i;
				break;
			}
		}
		cout << primeA * primeB << nl;
    }
}
