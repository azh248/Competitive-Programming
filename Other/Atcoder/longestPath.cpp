#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back
#define long long long

int n, m;

vector<int> adjLists[100000];
vector<int> parents[100000];

int dp[100000];

int longestPath(int node) {
	if (dp[node] != -1) {
		return dp[node];
	}
	int longest = 0;
	for (int i : adjLists[node]) {
		longest = max(longest, longestPath(i) + 1);
	}
	dp[node] = longest;
	return longest;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adjLists[a].pb(b);
		parents[b].pb(a);
	}	
	for (int i = 0; i < n; i++) {
		dp[i] = -1;
	}
	int maxPath = 0;
	for (int i = 0; i < n; i++) {
		if (parents[i].size() == 0) {
			maxPath = max(maxPath, longestPath(i));
		}
	}
	cout << maxPath << nl;
}	