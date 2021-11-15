#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int r, c;
bool grove[50][50];
pii start;
bool line[50][50];
vector<pii> adj[50][50]; // should be of size n
bool visited[50][50][2];
int dist[50][50][2]; // distance from starting node

void bfs(int rootX, int rootY) {
	queue<vector<int> > bfsQueue;
	visited[rootX][rootY][0] = true;
	bfsQueue.push({rootX, rootY, 0});
	dist[rootX][rootY][0] = 0;
	while (!bfsQueue.empty()) {
		int nodeX = bfsQueue.front()[0];
		int nodeY = bfsQueue.front()[1];
		int lineCrossed = bfsQueue.front()[2];
		bfsQueue.pop();
		for (int i = 0; i < adj[nodeX][nodeY].size(); i++) {
			pii neighbor = adj[nodeX][nodeY][i];
			int neighborLineCrossed = 0;
			if (line[nodeX][nodeY] && neighbor.first < nodeX) {
				continue;
			}
			if (line[neighbor.first][neighbor.second] && lineCrossed) {
				continue;
			} 
			if (lineCrossed || (line[neighbor.first][neighbor.second] && !lineCrossed && (neighbor.first > nodeX))) {
				neighborLineCrossed = true;
			}
			if (!visited[neighbor.first][neighbor.second][neighborLineCrossed]) {
				visited[neighbor.first][neighbor.second][neighborLineCrossed] = true;
				bfsQueue.push({neighbor.first, neighbor.second, neighborLineCrossed});
				dist[neighbor.first][neighbor.second][neighborLineCrossed] = dist[nodeX][nodeY][lineCrossed] + 1;
			}
		}
	}
}

void gridAdj() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!grove[i][j]) {
				if (i > 0 && !grove[i - 1][j]) {
					adj[i][j].pb({i - 1, j});
				}
				if (i < r - 1 && !grove[i + 1][j]) {
					adj[i][j].pb({i + 1, j});
				}
				if (j > 0 && !grove[i][j - 1]) {
					adj[i][j].pb({i, j - 1});
				}
				if (j < c - 1 && !grove[i][j + 1]) {
					adj[i][j].pb({i, j + 1});
				}

				if (i > 0 && j > 0 && (!grove[i - 1][j] || !grove[i][j - 1])) {
					adj[i][j].pb({i - 1, j - 1});
				}
				if (i > 0 && j < c - 1 && (!grove[i - 1][j] || !grove[i][j + 1])) {
					adj[i][j].pb({i - 1, j + 1});
				}
				if (i < r - 1 && j > 0 && (!grove[i + 1][j] || !grove[i][j - 1])) {
					adj[i][j].pb({i + 1, j - 1});
				}
				if (i < r - 1 && j < c - 1 && (!grove[i + 1][j] || !grove[i][j + 1])) {
					adj[i][j].pb({i + 1, j + 1});
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s; cin >> s;
		for (int j = 0; j < c; j++) {
			if (s[j] == 'X') {
				grove[i][j] = true;
			} else if (s[j] == '*') {
				start = {i, j};
			} 
		}
	}
	for (int i = 0; i < r - 1; i++) {
		for (int j = 0; j < c; j++) {
			if (grove[i][j] && start.first != i) {
				for (int k = 0; k < j; k++) {
					line[i][k] = true;
				}
				break;
			}
		}
		if (line[i][0]) {
			break;
		}
	}
	gridAdj();
	bfs(start.first, start.second);
	cout << dist[start.first][start.second][1] << nl;
}
