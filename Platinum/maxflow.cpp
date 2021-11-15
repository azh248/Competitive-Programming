/*
ID:azh248
LANG:C++
TASK:maxflow 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

int n, k;

vector<int> adjLists[50000];
unordered_set<int> visited;
int dist[50000];
int par[50000];
int anc[50000][17];

void findAncestors() {
	for (int i = 1; i < n; i++) {
		anc[i][0] = par[i];
	}
	for (int j = 1; j <= 16; j++) {
		for (int i = 1; i < n; i++) {
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
		}
	}
}

void treeDfs(int node, int prevNode) {
	visited.insert(node);
	for (int i = 0; i < adjLists[node].size(); i++) {
		if (adjLists[node][i] != prevNode) {
			int child = adjLists[node][i];
			if (visited.count(child) > 0) {
				continue;
			}
			par[child] = node;
			dist[child] = dist[node] + 1;
			treeDfs(child, node);
		}
	}
}

int lca(int a, int b) {
	if (dist[a] > dist[b]) { // swap if a is further
		return lca(b, a);
	}
	if (dist[a] < dist[b]) { // find ancestor of b that's the same depth as a
		for (int k = 16; dist[b] != dist[a]; k--) {
			while (dist[b] - (1 << k) >= dist[a]) {
				b = anc[b][k];
			}
		}
	}
	for (int k = 16; k > 0; k--) {
		while (anc[a][k] != anc[b][k]) {
			a = anc[a][k];
			b = anc[b][k];
		}
	}
	while (a != b) {
		a = par[a];
		b = par[b];
	}
	return a;
}

int prefixVal[50000];
int maxPassThrough = 0;

unordered_set<int> visited1;

int dfs(int node) {
	visited1.insert(node);
	int passThrough = 0;
	for (int i = 0; i < adjLists[node].size(); i++) {
		int child = adjLists[node][i];
		if (visited1.count(child) > 0) {
			continue;
		}
		passThrough += dfs(child);
	}
	passThrough += prefixVal[node];
	maxPassThrough = max(maxPassThrough, passThrough);
	return passThrough;
}

int main() {
	freopen("maxflow.in", "r", stdin);
	freopen("maxflow.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adjLists[a].pb(b);
		adjLists[b].pb(a);
	}
	treeDfs(0, -1);
	findAncestors();
	for (int i = 0; i < k; i++) {
		int s, t; cin >> s >> t; s--; t--;
		prefixVal[s]++;
		prefixVal[t]++;
		int ancestor = lca(s, t);
		prefixVal[ancestor]--;
		prefixVal[par[ancestor]]--;
	}
	dfs(0);
	cout << maxPassThrough << nl;
}
