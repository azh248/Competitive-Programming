/*
ID:azh248
LANG:C++
TASK:mooomoo 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, b;
ll minCowsVolume[100010]; // minCowsVolume[i] = minimum cows used to make a volume i
int breeds[20];
int volumes[100];

ll minimumCowsVolume(int volume) {
	if (volume < 0) {
		return 1e18;
	} else if (volume == 0) {
		return 0;
	} else if (minCowsVolume[volume] != -1) {
		return minCowsVolume[volume];
	}
	ll minVol = 1e18;
	for (int i = 0; i < b; i++) {
		minVol = min(minVol, minimumCowsVolume(volume - breeds[i]) + 1);
	}
	minCowsVolume[volume] = minVol;
	return minVol;
}

ll dp[100][100010]; // dp[i][j] = min cows from field i onwards satisfying volumes if the previous field's blowing over has volume i

ll minCows(int field, int volume) {
	if (field >= n || volume > volumes[field]) {
		return 0;
	} else if (dp[field][volume] != -1) {
		return dp[field][volume];
	}
	ll num = minimumCowsVolume(volumes[field] - volume) + minCows(field + 1, (volumes[field] == 0 ? 0 : (volumes[field] - 1)));
	dp[field][volume] = num;
	return num;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("mooomoo.in", "r", stdin);
	freopen("mooomoo.out", "w", stdout);
    cin >> n >> b;
	for (int i = 0; i < b; i++) {
		cin >> breeds[i];
	}	
	for (int i = 0; i < n; i++) {
		cin >> volumes[i];
	}
	memset(minCowsVolume, -1, sizeof(minCowsVolume));
	memset(dp, -1, sizeof(dp));
	cout << (minCows(0, 0) > 1e9 ? -1 : minCows(0, 0)) << nl;
}
