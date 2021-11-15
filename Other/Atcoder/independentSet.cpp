#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;

vector<int> adjLists[100000];
ll dp[100000][2];

ll numWays(int node, int color, int parent) { // color of node is white or black
	if (dp[node][color] != -1) {
		return dp[node][color];
	}
	ll ways = 1;
	if (color == 1) {
		for (int i : adjLists[node]) {
			if (i != parent) {
				ways *= numWays(i, 0, node);
				ways %= MOD;
			}
		}
	} else if (color == 0) {
		for (int i : adjLists[node]) {
			if (i != parent) {
				ways *= (numWays(i, 0, node) + numWays(i, 1, node));
				ways %= MOD;
			}
		}
	} 
	dp[node][color] = ways;
	return ways;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adjLists[a].pb(b);		
		adjLists[b].pb(a);
	}	
	memset(dp, -1, sizeof(dp));
	cout << (numWays(0, 0, -1) + numWays(0, 1, -1)) % MOD << nl;
}