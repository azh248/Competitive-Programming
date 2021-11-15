#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back
#define long long long

int n, m;
char grid[1010][1010]{};
string paths[1010][1010]{}; // paths[i][j] is the shortest path from A to grid[i][j]
bool visited[1010][1010]{};
int dist[1010][1010]{};

bool bfs(int rootI, int rootJ) {
	queue<pii> bfsQueue;
	visited[rootI][rootJ] = true;
	bfsQueue.push({rootI, rootJ});
	dist[rootI][rootJ] = 0;
	while (!bfsQueue.empty()) {
		pii node = bfsQueue.front();
		int a = node.first;
		int b = node.second;
		bfsQueue.pop();
		if (a > 0) {
			char ch = grid[a - 1][b];
			if (ch != '#' && !visited[a - 1][b]) {
				paths[a - 1][b] = paths[a][b] + "U";
				dist[a - 1][b] = dist[a][b] + 1;
				visited[a - 1][b] = true;
				bfsQueue.push({a - 1, b});
				if (ch == 'B') { // it's the endpoint
					cout << "YES" << nl << dist[a - 1][b] << nl << paths[a - 1][b] << nl;
					return true;
				}
			}
		}
		if (a < n - 1) {
			char ch = grid[a + 1][b];
			if (ch != '#' && !visited[a + 1][b]) {
				paths[a + 1][b] = paths[a][b] + "D";
				dist[a + 1][b] = dist[a][b] + 1;
				visited[a + 1][b] = true;
				bfsQueue.push({a + 1, b});
				if (ch == 'B') { // it's the endpoint
					cout << "YES" << nl << dist[a + 1][b] << nl << paths[a + 1][b] << nl;
					return true;
				}
			}
		}
		if (b > 0) {
			char ch = grid[a][b - 1];
			if (ch != '#' && !visited[a][b - 1]) {
				paths[a][b - 1] = paths[a][b] + "L";
				dist[a][b - 1] = dist[a][b] + 1;
				visited[a][b - 1] = true;
				bfsQueue.push({a, b - 1});
				if (ch == 'B') { // it's the endpoint
					cout << "YES" << nl << dist[a][b - 1] << nl << paths[a][b - 1] << nl;
					return true;
				}
			}
		}
		if (b < m - 1) {
			char ch = grid[a][b + 1];
			if (ch != '#' && !visited[a][b + 1]) {
				paths[a][b + 1] = paths[a][b] + "R";
				dist[a][b + 1] = dist[a][b] + 1;
				visited[a][b + 1] = true;
				bfsQueue.push({a, b + 1});
				if (ch == 'B') { // it's the endpoint
					cout << "YES" << nl << dist[a][b + 1] << nl << paths[a][b + 1] << nl;
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	pii start;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			grid[i][j] = s[j];
			if (s[j] == 'A') {
				start = {i, j};
			}
		}
	}
	bool result = bfs(start.first, start.second);
	if (!result) {
		cout << "NO" << nl;
	}
}
