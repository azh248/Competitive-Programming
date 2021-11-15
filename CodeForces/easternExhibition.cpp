#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

bool cmp1(pii a, pii b) {
	return a.first < b.first;
}

bool cmp2(pii a, pii b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		pii arrX[n];
		pii arrY[n];
		for (int i = 0; i < n; i++) {
			cin >> arrX[i].first >> arrX[i].second;
			arrY[i].first = arrX[i].first;
			arrY[i].second = arrX[i].second;
		}	
		sort(arrX, arrX + n, cmp1);
		sort(arrY, arrY + n, cmp2);
		if (n % 2 == 1) {
			cout << 1 << nl;
			continue;
		} 
		ll xWays = arrX[((n + 1) / 2)].first - arrX[((n - 1) / 2)].first + 1;
		ll yWays = arrY[((n + 1) / 2)].second - arrY[((n - 1) / 2)].second + 1; 

		ll ways = xWays * yWays;
		cout << ways << nl;
	}	
}
