#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, k;
pii arr[600];

bool cmp(pii a, pii b) {
	return a.first < b.first;
}

ll dp[600][50];

ll maxDist(int person, int selected) {
	if (selected > k) {
		return -1 * 1e18;
	} else if (selected == k) {
		// does it matter if you select less than k?
		return 0;
	} else if (dp[person][selected] != -1) {
		return dp[person][selected];
	}
	ll dist = 0;
	for (int i = person + 1; i < n; i++) {
		dist = max(dist, maxDist(i, selected + 1) + arr[i].first - arr[person].first + abs(arr[i].second - arr[person].second));
	}
	dp[person][selected] = dist;
	return dist;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;		
	}	
	sort(arr, arr + n, cmp);
	memset(dp, -1, sizeof(dp));
	ll dist = 0;
	for (int i = 0; i < n; i++) {
		dist = max(dist, maxDist(i, 1));
	}
	cout << dist << nl;
}
