#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

ll b, e, p, n, m;

vector<int> adjLists[40000];
unordered_set<int> visited;
ll dist1[40000]; // distance from starting node

int bfs(int root) {
	queue<int> bfsQueue;
	visited.insert(root);
	bfsQueue.push(root);
	dist1[root] = 0;
	while (!bfsQueue.empty()) {
		int node = bfsQueue.front();
		bfsQueue.pop();
		for (int i = 0; i < adjLists[node].size(); i++) {
			int neighbor = adjLists[node][i];
			if (visited.count(neighbor) == 0) {
				visited.insert(neighbor);
				bfsQueue.push(neighbor);
				dist1[neighbor] = dist1[node] + 1;
			}
		}
	}
	return visited.size();
}

ll dist2[2][40000]; // distance from starting node

int bfs1(int root) {
	queue<int> bfsQueue;
	visited.insert(root);
	bfsQueue.push(root);
	dist2[root][root] = 0;
	while (!bfsQueue.empty()) {
		int node = bfsQueue.front();
		bfsQueue.pop();
		for (int i = 0; i < adjLists[node].size(); i++) {
			int neighbor = adjLists[node][i];
			if (visited.count(neighbor) == 0) {
				visited.insert(neighbor);
				bfsQueue.push(neighbor);
				dist2[root][neighbor] = dist2[root][node] + 1;
			}
		}
	}
	return visited.size();
}

int main() {
	freopen("piggyback.in", "r", stdin);
	freopen("piggyback.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> b >> e >> p >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y; x--; y--;
		adjLists[x].pb(y);
		adjLists[y].pb(x);
	}	
	bfs(n - 1);
	visited.clear();
	bfs1(0);
	visited.clear();
	bfs1(1);
	visited.clear();
	ll minDistance = 1e9;
	for (int i = 0; i < n; i++) {
		minDistance = min(minDistance, dist1[i] * p + dist2[0][i] * b + dist2[1][i] * e);
	}
	cout << minDistance << nl;
}
