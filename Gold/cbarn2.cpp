/*
ID: azh248
LANG: C++
TASK: cbarn2 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back
#define long long long

int n, k;
ll cows[105];
ll dp[105][105][10]; // dp[i][j][k] = min total dist from room i onwards given we just unlocked room i, the first room unlocked was j, and we've unlocked k rooms

ll minDist(int room, int first, int unlocked) { 
	if (unlocked == k || room == n - 1) {		
		// return the distance from this room to the rest of the unfilled barns
		ll dist = 0;
		for (int i = room + 1; i < n + first; i++) {
			dist += cows[(i % n)] * (ll) (i - room);
		}
		return dist;
	} else if (dp[room][first][unlocked] != -1) { 
		return dp[room][first][unlocked]; 
	}
	ll minimum = 1e18;
	// try all possible choices of next room to unlock, for each one we can
	// calculate the distance in O(1) time using the previous result 
	ll dist = 0;
	for (int i = room + 1; i < n; i++) { 
		// for each room, find the total distance that the cows going to rooms up to that room would travel
		dist += cows[i - 1] * (ll) (i - 1 - room); // update distance to include the room right behind this room
		minimum = min(minimum, minDist(i, first, unlocked + 1) + dist); // try opening the ith room and seeing if it's the new min
	}
	dp[room][first][unlocked] = minimum;
	return minimum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("cbarn2.in", "r", stdin);
	freopen("cbarn2.out", "w", stdout);
    cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> cows[i];		
	}
	memset(dp, -1, sizeof(dp));
	ll minimum = 1e18;
	for (int i = 0; i < n; i++) {
		minimum = min(minimum, minDist(i, i, 1));
	}
	cout << minimum << nl;
}
