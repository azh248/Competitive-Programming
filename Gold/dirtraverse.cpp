/*
ID:azh248
LANG:C++
TASK:dirtraverse 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
vector<int> adj[100000];
ll pathLengths[100000];
ll subtreeSize[100000];
ll fileLength[100000];

void dfs(int node) {
	for (int i = 0; i < adj[node].size(); i++) {
		int child = adj[node][i];
		// 3 * blah is the nodes above this node, since we need to add ../ for the parent directory
		// the other stuff is for the bottom nodes; we remove the filelength + 1 to account for the folder name and the / (we don't need to accoutn for files since we can just subtract that at the end)
		pathLengths[child] = pathLengths[node] + 3 * (subtreeSize[0] - subtreeSize[child]) - ((fileLength[child] + 1) * subtreeSize[child]);
		dfs(child);
	}
}

ll dist[100000];

void treeDfs(int node) {
	subtreeSize[node] = 0;
	if (adj[node].size() == 0) {
		subtreeSize[node]++;
	}
	for (int i : adj[node]) {
		dist[i] = dist[node] + fileLength[i] + 1;
		treeDfs(i);
		subtreeSize[node] += subtreeSize[i];
	}
}

int main() {
	freopen("dirtraverse.in", "r", stdin);
	freopen("dirtraverse.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int files = 0;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		fileLength[i] = s.length();
		int children; cin >> children;
		for (int j = 0; j < children; j++) {
			int child; cin >> child; child--;
			adj[i].pb(child);
		}
		if (children == 0) {
			files++;
		}
	}
	dist[0] = 0;
	treeDfs(0);
	pathLengths[0] = 0;
	for (int i = 0; i < n; i++) {
		if (adj[i].size() == 0) {
			pathLengths[0] += dist[i];
		}
	}
	dfs(0);
	ll minTotalDist = 1e18;
	for (int i = 0; i < n; i++) {
		minTotalDist = min(minTotalDist, pathLengths[i]);
	}
	cout << minTotalDist - files << nl;
}