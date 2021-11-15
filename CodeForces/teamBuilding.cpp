#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, p, k;
vector<vector<int>> person;

ll dp[100000][128]; // dp[i][mask] = max strength given person i and j is mask

ll maxStrength(int member, int team) {
	// we can choose to fill a team spot or not: if we fill then we try all positions of the team and 
	// add the strength added by the person if they play at that position, if we don't fill just
	// add the value if the person is in the audience
	// at the end we check how much is added by the maximum audience
	int filledTeamSpots = 0;
	for (int i = 0; i < p; i++) {
		if (team & (1 << i)) {
			filledTeamSpots++;
		}
	}
	if (team == (1 << p) - 1 && member - filledTeamSpots >= k) {
		return 0;
	} else if (member >= n) {
		return -1 * 1e9;
	} else if (dp[member][team] != -1) {
		return dp[member][team];
	}
	ll strength = maxStrength(member + 1, team) + ((member - filledTeamSpots < k) ? person[member][0] : 0);
	for (int i = 0; i < p; i++) {
		if (!(team & (1 << i))) {
			strength = max(strength, maxStrength(member + 1, team + (1 << i)) + person[member][i + 1]);
		}
	}
	dp[member][team] = strength;
	return strength;
}

bool cmp(vector<int> arr1, vector<int> arr2) {
	return arr1[0] > arr2[0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> p >> k;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		person.pb({num});
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= p; j++) {
			int num; cin >> num;
			person[i].pb(num);
		}
	}
	// sort people by audience value
	sort(person.begin(), person.end(), cmp);
	memset(dp, -1, sizeof(dp));
	cout << maxStrength(0, 0) << nl;
}
