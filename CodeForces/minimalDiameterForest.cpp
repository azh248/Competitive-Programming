#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;


struct DSU {
	vector<int> p;
	void init(int n) { 
		p = vector<int>(n, -1); 
	}
	int get(int x) { 
		return p[x] < 0 ? x : p[x] = get(p[x]);
	}
	bool sameSet(int x, int y) {
		return get(x) == get(y);
	}
	int size(int x) {
		return -1 * p[get(x)]; 
	}
	bool unite(int x, int y) {
		x = get(x); 
		y = get(y); 
		if (x == y) {
			return false;
		}
		if (p[x] > p[y]) {
			swap(x, y);
		}
		p[x] += p[y];
		p[y] = x;
		return true;
	}
};

vector<int> adjLists[1000]{}; // should be of size n
unordered_set<int> visited;
int dist[1000][1000]{}; // distance from i to j

int bfs(int root) {
	visited.clear();
	queue<int> bfsQueue;
	visited.insert(root);
	bfsQueue.push(root);
	dist[root][root] = 0;
	while (!bfsQueue.empty()) {
		int node = bfsQueue.front();
		bfsQueue.pop();
		for (int i = 0; i < adjLists[node].size(); i++) {
			int neighbor = adjLists[node][i];
			if (visited.count(neighbor) == 0) {
				visited.insert(neighbor);
				bfsQueue.push(neighbor);
				dist[neighbor][root] = dist[node][root] + 1;
			}
		}
	}
	return visited.size();
}

bool cmp(pii a, pii b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	// dsu to find all trees, then we find the point in each tree whose longest shortest path to 
	// all the points is the minimum in that tree, and link them together
	// we can find the longest shortest path in the whole tree by doing a bfs from any point, 
	// then that point is guaranteed to be an endpoint of the longest path so we just bfs that
	DSU dsu;
	dsu.init(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adjLists[a].pb(b);
		adjLists[b].pb(a);
		dsu.unite(a, b);
	}
	vector<pii> shortestLongestShortestNodes; // nodes that are optimal for use because they have the least greatest distance from the node among all of the nodes in its tree
	bool treeVisited[1000]{};
	for (int i = 0; i < n; i++) {
		if (!treeVisited[dsu.get(i)]) {
			treeVisited[dsu.get(i)] = true;
			bfs(i);
			unordered_set<int> treeVisited = visited;
			int shortestLongestShortestNode = i;
			int shortestLongestShortestLength = 1e9;
			for (int j : treeVisited) {
				bfs(j);
				int longestShortestLength = 0;
				for (int k : treeVisited) {
					if (dist[k][j] > longestShortestLength) {
						longestShortestLength = dist[k][j];
					}
				}
				if (longestShortestLength < shortestLongestShortestLength) {
					shortestLongestShortestLength = longestShortestLength;
					shortestLongestShortestNode = j;
				}
			}
			shortestLongestShortestNodes.pb({shortestLongestShortestNode, shortestLongestShortestLength});
		}
	}
	sort(shortestLongestShortestNodes.begin(), shortestLongestShortestNodes.end(), cmp);
	for (int i = 0; i < shortestLongestShortestNodes.size() - 1; i++) {
		adjLists[shortestLongestShortestNodes[i].first].pb(shortestLongestShortestNodes[shortestLongestShortestNodes.size() - 1].first);
		adjLists[shortestLongestShortestNodes[shortestLongestShortestNodes.size() - 1].first].pb(shortestLongestShortestNodes[i].first);
	}
	memset(dist, 0, sizeof(dist));
	bfs(0);
	int longestFrom0Node = 0;
	int longestFrom0Length = 0;
	for (int i = 0; i < n; i++) {
		if (dist[i][0] > longestFrom0Length) {
			longestFrom0Length = dist[i][0];
			longestFrom0Node = i;
		}
	}
	bfs(longestFrom0Node);
	int longestShortestLength = 0;
	for (int i = 0; i < n; i++) {
		if (dist[i][longestFrom0Node] > longestShortestLength) {
			longestShortestLength = dist[i][longestFrom0Node];
		}
	}
	cout << longestShortestLength << nl;
	for (int i = 0; i < shortestLongestShortestNodes.size() - 1; i++) {
		cout << shortestLongestShortestNodes[i].first + 1 << " " << shortestLongestShortestNodes[shortestLongestShortestNodes.size() - 1].first + 1 << nl;
	}
}