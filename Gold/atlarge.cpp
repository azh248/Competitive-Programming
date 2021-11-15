/*
ID:azh248
LANG:C++
TASK:atlarge 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, k;
int minLeafDist[100000];
int minRootDist[100000];
vector<int> adjLists[100000];
int farmerCount = 0;

int calcDistances(int node, int parent) {
	minLeafDist[node] = 1e9;
	for (int i : adjLists[node]) {
		if (i != parent) {
			minRootDist[i] = minRootDist[node] + 1;
			minLeafDist[node] = min(minLeafDist[node], calcDistances(i, node) + 1);
		}
	}
	if (minLeafDist[node] == 1e9) {
		minLeafDist[node] = 0;
	}
	return minLeafDist[node];
}

void treeDfs(int node, int prevNode) {
	if (minLeafDist[node] <= minRootDist[node]) {
		farmerCount++;
		return;
	}
	for (int i = 0; i < adjLists[node].size(); i++) {
		if (adjLists[node][i] != prevNode) {
			treeDfs(adjLists[node][i], node);
		}
	}
}

int main() {
	freopen("atlarge.in", "r", stdin);
	freopen("atlarge.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> k;
	k--;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adjLists[a].pb(b);
		adjLists[b].pb(a);
	}
	// dfs to find distances from root to all nodes and minimum distance from a leaf to every node
	// then bfs and remove a node/add 1 to farmer count if it's reachable by a farmer, otherwise visit its children
	minRootDist[k] = 0;
	calcDistances(k, -1);
	treeDfs(k, -1);
	cout << farmerCount << nl;
}
