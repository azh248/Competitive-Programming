#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
vector<int> adjLists[50000];
int dp[50000][2];
int par[50000];

int maxVisited(int cow, int prevVis) {
	if (dp[cow][prevVis] != -1) {
		return dp[cow][prevVis];
	} else if (adjLists[cow].size() == 1 && cow != 0) {
		return (prevVis + 1) % 2;
	}
	int visited1 = 0; // visit this node
	if (!prevVis) {
		for (int i : adjLists[cow]) {
			if (i != par[cow]) {
				visited1 += maxVisited(i, 1);
			}
		}
		visited1++;
	}
	int visited2 = 0; // don't visit this cow
	for (int i : adjLists[cow]) {
		if (i != par[cow]) {
			visited2 += maxVisited(i, 0);
		}
	}
	int visited = max(visited1, visited2);
	dp[cow][prevVis] = visited;
	return visited;
}

unordered_set<int> visited;

void dfs(int node) {
	visited.insert(node);
	for (int i = 0; i < adjLists[node].size(); i++) {
		int child = adjLists[node][i];
		if (visited.count(child) > 0) {
			continue;
		}
		par[child] = node;
		dfs(child);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adjLists[a].pb(b);
		adjLists[b].pb(a);
	}	
	dfs(0);
	memset(dp, -1, sizeof(dp));
	cout << maxVisited(0, 0) << nl;
}
