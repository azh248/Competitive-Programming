/*
ID:azh248
LANG:C++
TASK: recording
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n;

pii arr[150];
int dp[150][150];

bool cmp(pii a, pii b) {
	return a.first < b.first;
}

int maxPrograms(int program1, int program2) {
	if (program1 >= n || program2 >= n) {
		return 0;
	} else if (dp[program1][program2] != -1) {
		return dp[program1][program2];
	}
	int programs = 0;
	// for (int i = program1 + 1; i < program2; i++) {
	// 	if (arr[i].first >= arr[program1].second) {
	// 		programs = max(programs, maxPrograms(i, program2) + 1);
	// 	}
	// }
	for (int i = program2 + 1; i < n; i++) {
		if (arr[i].first >= arr[program2].second) {
			programs = max(programs, maxPrograms(program1, i) + 1);
		} if (arr[i].first >= arr[program1].second) {
			programs = max(programs, maxPrograms(program2, i) + 1);
		}
	}
	dp[program1][program2] = programs;
	return programs;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("recording.in", "r", stdin);
	freopen("recording.out", "w", stdout);
    cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n, cmp);
	memset(dp, -1, sizeof(dp));
	int programs = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			programs = max(programs, maxPrograms(i, j) + 2);
		}
	}
	cout << programs << nl;
}
