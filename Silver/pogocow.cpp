#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;

int nextCow0[1000000]; // nextCow[i] = the next cow located after i 
int nextCow1[1000000]; // nextCow1[i] = the next cow located before i
pii cows[1000];

bool cmp(pii a, pii b) {
	return a.first < b.first;
}

int dp[1000][1000][2];

int maxCowtonium(int cow, int prev, int direction) {
	if (cow >= n || cow < 0) {
		return 0;
	} else if (dp[cow][prev][direction] != -1) {
		return dp[cow][prev][direction];
	}
	int cowtonium = 0;
	if (direction == 0) {
		if (2 * cows[cow].first - cows[prev].first > cows[n - 1].first) {
			return cows[cow].second;
		}
		int minNext = nextCow0[cows[cow].first - cows[prev].first + cows[cow].first];
		if (minNext == -1) {
			return cows[cow].second;
		}
		if (cow == prev) {
			minNext = cow + 1;
		}
		for (int i = minNext; i < n; i++) {
			cowtonium = max(cowtonium, maxCowtonium(i, cow, 0) + cows[cow].second);
		}
	} else {
		if (2 * cows[cow].first < cows[prev].first) {
			return cows[cow].second;
		}
		int minNext = nextCow1[cows[cow].first - cows[prev].first + cows[cow].first];
		if (minNext == -1) {
			return cows[cow].second;
		}
		if (cow == prev) {
			minNext = cow - 1;
		}
		for (int i = minNext; i >= 0; i--) {
			cowtonium = max(cowtonium, maxCowtonium(i, cow, 1) + cows[cow].second);
		}
	}
	dp[cow][prev][direction] = cowtonium;
	return cowtonium;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("pogocow.in", "r", stdin);
	freopen("pogocow.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cows[i].first >> cows[i].second;		
	}	
	sort(cows, cows + n, cmp);
	memset(dp, -1, sizeof(dp));
	nextCow0[0] = 0;
	for (int i = 1; i < 1000000; i++) {
		if (nextCow0[i - 1] == n || nextCow0[i - 1] == -1) {
			nextCow0[i - 1] = -1;
			nextCow0[i] = -1; 
		} else if (cows[nextCow0[i - 1]].first == i - 1) {
			nextCow0[i] = nextCow0[i - 1] + 1;
		} else {
			nextCow0[i] = nextCow0[i - 1];
		}
	}
	nextCow1[999999] = n - 1;
	for (int i = 999998; i >= 0; i--) {
		if (nextCow1[i + 1] == -1 || nextCow1[i + 1] == -1) {
			nextCow1[i + 1] = -1;
			nextCow1[i] = -1;
		} else if (cows[nextCow1[i + 1]].first == i + 1) {
			nextCow1[i] = nextCow1[i + 1] - 1;
		} else {
			nextCow1[i] = nextCow1[i + 1];
		}
	}
	int cowtonium = 0;
	for (int i = 0; i < n; i++) {
		cowtonium = max(cowtonium, maxCowtonium(i, i, 0));
		cowtonium = max(cowtonium, maxCowtonium(i, i, 1));
	}
	cout << cowtonium << nl;
}
