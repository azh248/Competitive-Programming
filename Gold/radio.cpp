/*
ID: azh248
LANG: C++
TASK:radio 
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

int n, m;
pii fj, bess;
string fjPath, bessPath;
int dp[1000][1000]; // dp[i][j] = min energy if fj is at point i on his path and bess is at point j on her path

pii move(pii coords, char move) {
	if (move == 'N') {
		coords.second++;
	} else if (move == 'E') {
		coords.first++;
	} else if (move == 'S') {
		coords.second--;
	} else if (move == 'W') {
		coords.first--;
	}
	return coords;
}

int dist(pii a, pii b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int minimumEnergy(int fjIndex, pii fjCoords, int bessIndex, pii bessCoords) { 
	if (fjIndex > n || bessIndex > m) {
		return 1000000000;
	} else if (fjIndex == n && bessIndex == m) {
		return 0;
	} else if (fjIndex == n || bessIndex == m) {
		return 1000000000;
	} else if (dp[fjIndex][bessIndex] != -1) {
		return dp[fjIndex][bessIndex];
	}
	// fj move or not, bess move or not
	int minEnergy = 1000000000;
	pii fjMove = move(fjCoords, fjPath[fjIndex]);
	pii bessMove = move(bessCoords, bessPath[bessIndex]); 
	minEnergy = min(minEnergy, minimumEnergy(fjIndex + 1, fjMove, bessIndex, bessCoords) + dist(fjMove, bessCoords));
	minEnergy = min(minEnergy, minimumEnergy(fjIndex, fjCoords, bessIndex + 1, bessMove) + dist(fjCoords, bessMove));
	minEnergy = min(minEnergy, minimumEnergy(fjIndex + 1, fjMove, bessIndex + 1, bessMove) + dist(fjMove, bessMove));
	dp[fjIndex][bessIndex] = minEnergy;
	return minEnergy;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("radio.in", "r", stdin);
	freopen("radio.out", "w", stdout);
	cin >> n >> m >> fj.first >> fj.second >> bess.first >> bess.second >> fjPath >> bessPath;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			dp[i][j] = -1;
		}
	}
	cout << minimumEnergy(0, fj, 0, bess) << nl;
}
