/*
ID:azh248
LANG:C++
TASK:grass 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;

vector<int> adj[100000];
vector<int> reverseAdj[100000];
int topo[100000];
int curr;
bool topovis[100000];
bool vis[100000];
vector<int> currVis;
vector<vector<int>> sccs;
int roots[100000];
int sccSize[100000];
vector<int> sccAdj[100000];
vector<int> reverseSccAdj[100000];

void topodfs(int node) {
	topovis[node] = true;
	for (int i = 0; i < reverseAdj[node].size(); i++) {
		if (!topovis[reverseAdj[node][i]]) {
			topodfs(reverseAdj[node][i]);
		}
	}
	topo[--curr] = node;
}

void toposort() {
	curr = n;
	for (int i = 0; i < n; i++) {
		if (!topovis[i]) {
			topodfs(i);
		}
	}
}

void dfs(int node) {
	vis[node] = true;
	currVis.pb(node);
	for (int i = 0; i < adj[node].size(); i++) {
		if (!vis[adj[node][i]]) {
			dfs(adj[node][i]);
		}
	}
}

void findSCCs() {
	for (int i = 0; i < n; i++) {
		for (int j : adj[i]) {
			reverseAdj[j].pb(i);
		}
	}
	toposort();
	for (int i = 0; i < n; i++) {
		if (!vis[topo[i]]) {
			dfs(topo[i]);
			sccs.pb(currVis);
			currVis = vector<int>();
		}
	}
}

void condensationGraph() {
	findSCCs();
	for (vector<int> scc : sccs) {
		int root = scc[0];
		for (int i : scc) {
			roots[i] = root;
		}
		sccSize[root] = scc.size();
	}
	for (int i = 0; i < n; i++) {
		for (int j : adj[i]) {
			if (roots[i] != roots[j]) {
				sccAdj[roots[i]].pb(roots[j]);
				reverseSccAdj[roots[j]].pb(roots[i]);
			}
		}
	}
}

pii dp[100000][2];

pii maxVisited(int node, int wrong) {
	// we never want to visit a node we've already visited unless it's 0; therefore to use our "wrong path" we must be visiting a new node or 0
	if (node == roots[0] && wrong) {
		return {0, 1};
	} else if (dp[node][wrong] != pii(-1, -1)) {
		return dp[node][wrong];
	}
	pii visited = {sccSize[node], 0};
	for (int i : sccAdj[node]) {
		if ((!visited.second && maxVisited(i, wrong).second) || ((maxVisited(i, wrong).first + sccSize[node] > visited.first) && maxVisited(i, wrong).second)) {
			visited = maxVisited(i, wrong);
			visited.first += sccSize[node];
		}
	}
	if (!wrong) {
		for (int i : reverseSccAdj[node]) {
			if ((!visited.second && maxVisited(i, 1).second) || ((maxVisited(i, 1).first + sccSize[node] > visited.first) && maxVisited(i, 1).second)) {
				visited = maxVisited(i, 1);
				visited.first += sccSize[node];
			}
		}
	}
	dp[node][wrong] = visited;
	return visited;
}

int main() {
	freopen("grass.in", "r", stdin);
	freopen("grass.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].pb(b);
	}
	condensationGraph();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = {-1, -1};
		}
	}
	cout << maxVisited(roots[0], 0).first << nl;
}