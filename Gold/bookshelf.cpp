/*
ID:azh248
LANG:C++
TASK:bookshelf 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

ll n, l;

pii books[100000]; // height, width

ll dp[100000]; // dp[i] = minimum height if the next shelf starts with book i

ll minHeight(int book) {
	if (book == n) {
		return 0;
	} else if (dp[book] != -1){
		return dp[book];
	}
	ll width = 0;
	ll maxHeight = 0;
	ll height = 1e18;
	for (int i = book; i < n; i++){
		maxHeight = max(maxHeight, books[i].first);
		width += books[i].second;
		if (width > l) {
			break;
		}
		height = min(height, minHeight(i + 1) + maxHeight);
	}
	dp[book] = height;
	return height;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("bookshelf.in", "r", stdin);
	freopen("bookshelf.out", "w", stdout);
    cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> books[i].first >> books[i].second;
	}	
	memset(dp, -1, 100000);
	cout << minHeight(0) << nl;
}
