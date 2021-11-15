#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

bool sieveResult[100000]{};

void sieve(int n) { // find all prime numbers up to n by marking the composite numbers with their least prime factor
    for (int i = 2; i <= n; i++) {
        if (sieveResult[i])
            continue;
        for (int multiple = 2 * i; multiple <= n; multiple += i) {
            sieveResult[multiple] = true;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve(100000);
	vector<int> primes;
	for (int i = 2; i < 100000; i++) {
		if (!sieveResult[i]) {
			primes.pb(i);
		}
	}
	ll arr[primes.size()];
	for (int i = 0; i < primes.size() - 1; i++) {
		arr[i] = (ll) primes[i] * (ll) primes[i + 1];
	}
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		int n;
		cin >> n;
		int l = 0;
		int r = primes.size() - 2;
		ll ans = l - 1;
		while (l <= r) {
			int mid = (r + l)/2;
			if (arr[mid] <= n) {
				ans = arr[mid];
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		cout << "Case #" << t1 << ": " << ans << nl;;
	}	
}