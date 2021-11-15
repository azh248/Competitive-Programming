#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, L;

int grass[1000];

ll dp[1000][1000][2]; // dp[i][j][k] = min time if the next haybale to be eaten on the left of Bessie is i, the next haybale
					   // on the right of Bessie is j, and the most recent haybale Bessie ate was k (0 for i + 1, 1 for j - 1)

ll minTime(int l, int r, int bessie) {
	if (l < 0) {
		ll time = 0;
		int bessieLocation = grass[0];
		while (r < n) {
			time += (n - 1 - r + 1) * (grass[r] - bessieLocation);
			bessieLocation = grass[r];
			r++;
		}
		return time;
	} else if (r >= n) {
		ll time = 0;
		int bessieLocation = grass[n - 1];
		while (l >= 0) {
			time += (l + 1) * (bessieLocation - grass[l]);
			bessieLocation = grass[l];
			l--;
		}
		return time;
	} else if (dp[l][r][bessie] != -1) {
		return dp[l][r][bessie];
	}
	ll time = 1e9;
	int bessieLocation = (bessie == 0) ? grass[l + 1] : grass[r - 1];
	time = min(time, (n - (r - l - 1)) * (bessieLocation - grass[l]) + minTime(l - 1, r, 0));
	time = min(time, (n - (r - l - 1)) * (grass[r] - bessieLocation) + minTime(l, r + 1, 1));
	dp[l][r][bessie] = time;
	return time;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> L;
	for (int i = 0; i < n; i++) {
		cin >> grass[i];
	}	
	sort(grass, grass + n);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n - 1; i++) {
		if (L >= grass[i] && L <= grass[i + 1]) {
			cout << min(minTime(i - 1, i + 1, 0) + n * (L - grass[i]), minTime(i, i + 2, 1) + n * (grass[i + 1] - L)) << nl;
			break;
		} else if (i == n - 2) {
			if (L < grass[0]) {
				cout << minTime(-1, 1, 1) + n * (grass[0] - L) << nl;
				break;
			} else {
				cout << minTime(n, n - 2, 0) + n * (L - grass[n - 1]) << nl;
				break;
			}
		}
	}
}
