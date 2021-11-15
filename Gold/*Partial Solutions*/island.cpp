/*
ID:azh248
LANG:C++
TASK:island 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

int r, c;
char arr[51][51];
vector<ll> islands[16];
ll islandNumber = 0;
ll islandDistance[16][16];
ll dp[(1 << 15) + 1][16];

vector<ll> adjLists[2500];
unordered_set<ll> visited;
ll dist[2500][2500]; // distance from starting node

int bfs(int root) {
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
				if (arr[neighbor / c][neighbor % c] == 'S') {
					dist[root][neighbor] = dist[root][node] + 1;
				} else {
					dist[root][neighbor] = dist[root][node];	
				}
			}
		}
	}
	return visited.size();
}

bool vis[51][51];

void ff(int i, int j) {
	if (i < 0 || i >= r || j < 0 || j >= c)
		return; // if outside grid
	if (arr[i][j] != 'X')
		return; // wrong color
	if (vis[i][j])
		return;			  // already visited this square
	vis[i][j] = true; // mark current square as visited
	islands[islandNumber].pb(i * c + j);
	// recursively call floodfill for neighboring squares
	ff(i, j + 1);
	ff(i, j - 1);
	ff(i - 1, j);
	ff(i + 1, j);
}

ll minDistance(int mask, int island) {
	if (mask == (1 << islandNumber) - 1) {
		return 0;
	} else if (dp[mask][island] != -1) {
		return dp[mask][island];
	}
	ll distance = 1e9;
	for (int i = 0; i < islandNumber; i++) {
		if (!(mask & (1 << i))) {
			distance = min(distance, minDistance(mask + (1 << i), i) + islandDistance[island][i]);
		}
	}
	dp[mask][island] = distance;
	return distance;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("island.in", "r", stdin);
	freopen("island.out", "w", stdout);
	cin >> r >> c;
	memset(dp, -1, sizeof(dp));
	// make a graph with all islands and shallow water, then flood fill to find the squares belonging to each distinct island. then, bfs from every square in the graph
	// and find the minimum distance from each island to each other island, and finally, use bitmask dp to find the minimum distance bessie has to swim (mst also works)
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			arr[i][j] = s[j];
		}
	}
	// ff to find all islands
	for (int i = 0; i < r; i++) {
		 for (int j = 0; j < c; j++) {
			 if (!vis[i][j] && arr[i][j] == 'X') {
				 ff(i, j);
				 islandNumber++;
			 }
		 }
	}
	// construct the graph
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == '.') {
				continue;
			}
			if (i > 0) {
				if (arr[i - 1][j] != '.') {
					adjLists[i * c + j].pb((i - 1) * c + j);
				}
			}
			if (i < r - 1) {
				if (arr[i + 1][j] != '.') {
					adjLists[i * c + j].pb((i + 1) * c + j);
				}
			}
			if (j > 0) {
				if (arr[i][j - 1] != '.') {
					adjLists[i * c + j].pb(i * c + j - 1);
				}				
			}
			if (j < c - 1) {
				if (arr[i][j + 1] != '.') {
					adjLists[i * c + j].pb(i * c + j + 1);
				}
			}
		}
	}
	// bfs from every square
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			bfs(i * c + j);
			visited.clear();
		}
	}
	// finding min distance between islands
	for (int i = 0; i < islandNumber; i++) {
		for (int j = i + 1; j < islandNumber; j++) {
			islandDistance[i][j] = 1e9;
			for (int square1 : islands[i]) {
				for (int square2 : islands[j]) {
					islandDistance[i][j] = min(islandDistance[i][j], min(dist[square1][square2], dist[square2][square1]));
				}
			}
			islandDistance[j][i] = islandDistance[i][j];
		}
	}
	ll distance = 1e9;
	for (int i = 0; i < islandNumber; i++) {
		distance = min(distance, minDistance((1 << i), i));
	}
	cout << distance << nl;
}
