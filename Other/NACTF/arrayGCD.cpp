#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;
ll arr[100005];
pii k[55];
ll numpow[55][100005]{}; // power of p at all numbers from (p, p * 2, p * 3, ...p * q)
ll pSums[55][100005]{}; // pSums[i][q] = power of p in pair i in p!, 2p!, 3p!, ...qp!

int main() {
	freopen("in1.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> k[i].first >> k[i].second;
	}
	for (int j = 0; j < m; j++) {
		// precompute prefix sums so we know what power of p is in each viable x! in O(1)
		ll p = k[j].first;
		ll q = k[j].second;
		ll pToI = 1; // p to the power of i, we maintain this as we loop through
		// x = p!, (p*2)!, (p*3)!, etc. to (p*q)!
		// we need to account for legendre's formula, so we loop through to log p of q so we know what powers
		for (int i = 1; i <= floor(log(q)/log(p)) + 1; i++) { // 1 to log_p (q) + 1
			for (int k = pToI; k <= q; k += pToI) {
				numpow[j][k]++;
			}
			pToI *= p;
		}
		pSums[j][0] = 0;
		for (int i = 1; i <= q; i++) {
			pSums[j][i] = pSums[j][i - 1] + numpow[j][i];
		}
	}
	ll totalCost = 0;
	for (int i = 0; i < n; i++) {
		ll maxXDivP = 0; // we find the x that's required for each prime power, then we take the max of all these x's
						  // represented in terms of the actual max x divided by p
		ll maxXP = 0; // prime p that's in the greatest x required
		for (int j = 0; j < m; j++) {
			ll p = k[j].first;
			ll q = k[j].second;
			int pPow = 0;
			// find the power of p in a_i so we know what power we need in x
			ll currA_i = arr[i];
			while (currA_i % p == 0) {
				currA_i /= p;
				pPow++;
			}

			if (pPow >= q) {
				continue;
			}

			// see how high you need x to go so that you have p^q as a factor when you multiply by a_i
			int l = 1;
			int r = q;
			int ans = l - 1;
			while (l <= r) {
				int mid = (r + l) / 2; // seeing if x = p * mid would work to get up to the power that we need
				if (pSums[j][mid] >= q - pPow) {
					ans = mid;
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			}
			if (((double)ans)/maxXDivP * ((double)p)/maxXP > 1) {
				maxXDivP = ans;
				maxXP = p;
			}
		}
		totalCost += ((maxXDivP % MOD) * (maxXP % MOD)) % MOD;
		totalCost %= MOD;
	}
	cout << totalCost << nl;
}