#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, k;
vector<pii> adjLists[200000];
int par[200000];
int subTreeSize[200000];
bool vis[200000];

int dist[200000];
int anc[200000][19];

void findAncestors() {
	for (int i = 0; i < n; i++) {
		if (dist[i] != 0) {
			anc[i][0] = par[i];
		}
	}
	for (int j = 1; j <= 18; j++) {
		for (int i = 0; i < n; i++) {
			if (dist[i] != 0) {
				anc[i][j] = anc[anc[i][j - 1]][j - 1];
			}
		}
	}
}

void treeDfs2(int node, int prevNode) {
	for (int i = 0; i < adjLists[node].size(); i++) {
		if (adjLists[node][i].first != prevNode) {
			pii child = adjLists[node][i];
			par[child.first] = node;
			dist[child.first] = dist[node] + 1;
			treeDfs2(child.first, node);
		}
	}
}

int lca(int a, int b) {
	if (dist[a] > dist[b]) { // swap if a is further
		return lca(b, a);
	}
	if (dist[a] < dist[b]) { // find ancestor of b that's the same depth as a
		for (int k = 18; dist[b] != dist[a]; k--) {
			while (dist[b] - (1 << k) >= dist[a]) {
				b = anc[b][k];
			}
		}
	}
	for (int k = 18; k > 0; k--) {
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

int distance(int a, int b) {
	int ancestor = lca(a, b);
	return dist[a] + dist[b] - 2 * dist[ancestor];
}

void calcSubtrees(int node) {
	for (pii i : adjLists[node]) {
		if (i.first != par[node]) {
			calcSubtrees(i.first);
			subTreeSize[node] += subTreeSize[i.first];
		}
	}
}

unordered_set<int> visited;

int findCentroid(int node) {
	// we don't need to worry about the parent and its subtrees because we
	// already know it's not a centroid
	visited.insert(node);
	for (pii i : adjLists[node]) {
		if (visited.count(i.first) == 0) {
			if (subTreeSize[i.first] * 2 > n) {
				return findCentroid(i.first);
			} else {
				return node;
			}
		}
	}
	return -1;
}

int minOverallPath = 1e9;
int minPath;

void treeDfs1(int node, int path, int root) {
	if (path == k) {
		minPath = min(minPath, distance(node, root));
		return;
	}
	visited.insert(node);
	for (int i = 0; i < adjLists[node].size(); i++) {
		pii child = adjLists[node][i];
		if (visited.count(child.first) > 0 || vis[child.first]) {
			continue;
		}
		treeDfs1(child.first, path + child.second, root);
	}
}

unordered_map<int, pii> nodeDists;
queue<pair<int, pii>> nodeDistsQueue;

void treeDfs3(int node, int path, int root) {
	if (nodeDists.find(path) != nodeDists.end()) {
		if (distance(node, root) < (*nodeDists.find(path)).second.second) {
			nodeDists[path] = pii(distance(node, root), node);
		} 
	} else {
		nodeDistsQueue.push(make_pair(path, pii(distance(node, root), node)));
		if (nodeDists.find(k - path) != nodeDists.end()) {
			minPath = min(minPath, distance(node, root) + distance((*nodeDists.find(k - path)).second.second, root));
		}
	}
	visited.insert(node);
	for (int i = 0; i < adjLists[node].size(); i++) {
		pii child = adjLists[node][i];
		if (visited.count(child.first) > 0 || vis[child.first]) {
			continue;
		}
		treeDfs3(child.first, path + child.second, root);
	}
}

void decomp(int node) {
	int centroid = findCentroid(node);
	vis[centroid] = true;
	minPath = 1e9;
	treeDfs1(centroid, 0, centroid);
	visited.clear();
	for (pii i : adjLists[centroid]) {
		if (vis[i.first]) {
			continue;
		}
		treeDfs3(i.first, i.second, centroid);
		visited.clear();
		while (!nodeDistsQueue.empty()) {
			nodeDists.insert(nodeDistsQueue.front());
			nodeDistsQueue.pop();
		}
	}
	nodeDists.clear();
	minOverallPath = min(minOverallPath, minPath);
	for (pii i : adjLists[centroid]) {
		if (!vis[i.first]) {
			decomp(i.first);
		}
	}
}

int main() {
	freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int a, b, l; cin >> a >> b >> l; 
		adjLists[a].pb(pii(b, l));
		adjLists[b].pb(pii(a, l));
	}
	treeDfs2(0, -1);
	findAncestors();
	calcSubtrees(0);
	decomp(0);
	cout << ((minOverallPath == 1e9) ? -1 : minOverallPath) << nl;
}
