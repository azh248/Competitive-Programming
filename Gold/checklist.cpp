/*
ID: azh248
LANG: C++
TASK: checklist 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back
#define long long long

int h, g;
int dp[1000][1000][2];

vector<pii> holsteins;
vector<pii> guernseys;

ll dist(pii a, pii b) {
	return (ll)(a.first - b.first)*(ll)(a.first - b.first) + (ll)(a.second - b.second)*(ll)(a.second - b.second);
}

ll minEnergy(int holstein, int guernsey, int currentBreed) { // the last holstein that we moved to, the last guernsey that we moved to, the breed that we're currently on (0 for holstein, 1 for guernsey)
	if (holstein >= h || guernsey >= g) {
		return 1000000000;
	} else if (holstein == h - 1 && guernsey == g - 1 && currentBreed == 0) {
		return 0;
	} else if (holstein == h - 1 && guernsey <= g - 2) {
		return 1000000000;
	} else if (guernsey != -1 && dp[holstein][guernsey][currentBreed] != -1) {
		return dp[holstein][guernsey][currentBreed];
	}
	ll minE = minEnergy(holstein + 1, guernsey, 0) + ((currentBreed == 0) ? dist(holsteins[holstein + 1], holsteins[holstein]) : dist(holsteins[holstein + 1], guernseys[guernsey]));
	minE = min(minE, minEnergy(holstein, guernsey + 1, 1) + ((currentBreed == 0) ? dist(guernseys[guernsey + 1], holsteins[holstein]) : dist(guernseys[guernsey + 1], guernseys[guernsey])));
	dp[holstein][guernsey][currentBreed] = minE;
	return minE;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);
	cin >> h >> g;
	for (int i = 0; i < h; i++) {
		int holsteinX;
		cin >> holsteinX;
		int holsteinY;
		cin >> holsteinY;
		holsteins.pb({holsteinX, holsteinY});
	}
	for (int i = 0; i < g; i++) {
		int guernseyX;
		cin >> guernseyX;
		int guernseyY;
		cin >> guernseyY;
		guernseys.pb({guernseyX, guernseyY});
	}
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	cout << minEnergy(0, -1, 0) << nl;
}