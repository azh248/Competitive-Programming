#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

ll n, q, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q >> k;
	// precalculate the space each element has (if its 1, 3, 6, then 3 can go to 2, 4, or 5 so 3 ways in total)
	ll arr[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	ll spaces[n + 1];
	ll prefixSpaces[n + 1];
	prefixSpaces[1] = 0;
	for (int i = 2; i <= n - 1; i++) {
		spaces[i] = arr[i + 1] - arr[i - 1] - 2; // can't include original position
		prefixSpaces[i] = prefixSpaces[i - 1] + spaces[i];
	}

	for (int t1 = 0; t1 < q; t1++) {
		int l, r;
		cin >> l >> r;
		ll kSimilar = 0;
		kSimilar += (arr[l] - 1) + (arr[l + 1] - arr[l] - 1);
		kSimilar += (k - arr[r]) + (arr[r] - arr[r - 1] - 1);
		kSimilar += prefixSpaces[r - 1] - prefixSpaces[l];
		cout << kSimilar << nl;
	}	
}
