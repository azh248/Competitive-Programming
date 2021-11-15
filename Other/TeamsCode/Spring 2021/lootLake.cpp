#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;

int arr[1000][1000];

bool visited[1000][1000];
int dist[1000][1000]{}; // distance from starting node

void bfs(pii root) {
	queue<pii> bfsQueue;
	visited[root.first][root.second] = true;;
	bfsQueue.push(root);
	dist[root.first][root.second] = 0;
	while (!bfsQueue.empty()) {
		pii node = bfsQueue.front();
		bfsQueue.pop(); 
		vector<pii> adjList = {{node.first + 1, node.second}, {node.first - 1, node.second}, {node.first, node.second - 1}, {node.first, node.second + 1}};
		for (pii k : adjList) {
			int i = k.first;
			int j = k.second;
			if (i >= n || i < 0 || j >= m || j < 0) {
				continue;
			} else if (visited[i][j]) {
				continue;
			} else if (arr[i][j] == 1) {
				continue;
			}
			visited[i][j] = true;;
			bfsQueue.push(k);
			dist[i][j] = dist[node.first][node.second] + 1;
		}
	}
}

int dp[1000][1000];

int numWays(pii node) {
	if (node.first == n - 1 && node.second == m - 1) {
		return 1;
	} else if (dp[node.first][node.second] != -1) {
		return dp[node.first][node.second];
	}
	vector<pii> possibleParents = {{node.first + 1, node.second}, {node.first - 1, node.second}, {node.first, node.second + 1}, {node.first, node.second - 1}};
	int minDist = 1e9;
	for (pii k : possibleParents) {
		int i = k.first;
		int j = k.second;
		if (i >= n || i < 0 || j >= m || j < 0) {
			continue;
		} else if (arr[i][j] == 1) {
			continue;
		}	
		minDist = min(minDist, dist[i][j]);
	}
	int ways = 0;
	for (pii k : possibleParents) {
		int i = k.first;
		int j = k.second;
		if (i >= n || i < 0 || j >= m || j < 0) {
			continue;
		} else if (arr[i][j] == 1) {
			continue;
		}	
		if (dist[i][j] == minDist) {
			ways += numWays(k);
			ways %= MOD;
		}
	}
	dp[node.first][node.second] = ways;
	return ways;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}	
	memset(dist, 1e9, sizeof(dist));
	memset(dp, -1, sizeof(dp));
	bfs({n - 1, m - 1});
	if (dist[0][0] == 1e9) {
		cout << 0 << nl;
		return 0;
	}
	cout << numWays({0, 0}) << nl;
}
