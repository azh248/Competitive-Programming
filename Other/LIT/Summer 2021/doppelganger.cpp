#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;
int dp[50][50][50][50];
bool blocked1[50][50];
bool blocked2[50][50];
bool visited[50][50][50][50];
int ex1, ey1, ex2, ey2, x1, y11, x2, y2;
ll dist[50][50][50][50];

void bfs() {
	memset(dist, -1, sizeof(dist));
	queue<vector<int> > bfsQueue;
	visited[x1][y11][x2][y2] = true;
	bfsQueue.push({x1, y11, x2, y2});
	dist[x1][y11][x2][y2] = 0;
	while (!bfsQueue.empty()) {
		vector<int> p = bfsQueue.front();
		bfsQueue.pop();
		if (p[0] == n - 1 || blocked1[p[0] + 1][p[1]]) {
			if (p[2] != n - 1 && !blocked2[p[2] + 1][p[3]]) {
				if (!visited[p[0]][p[1]][p[2] + 1][p[3]]) {
				visited[p[0]][p[1]][p[2] + 1][p[3]] = true;
				dist[p[0]][p[1]][p[2] + 1][p[3]] = dist[p[0]][p[1]][p[2]][p[3]] + 1; 
				bfsQueue.push({p[0], p[1], p[2] + 1, p[3]});
				}
			}
		} else if (p[2] == n - 1 || blocked2[p[2] + 1][p[3]]) {
			if (!visited[p[0] + 1][p[1]][p[2]][p[3]]) {
			visited[p[0] + 1][p[1]][p[2]][p[3]] = true;
			dist[p[0] + 1][p[1]][p[2]][p[3]] = dist[p[0]][p[1]][p[2]][p[3]] + 1;
			bfsQueue.push({p[0] + 1, p[1], p[2], p[3]});
			}
		} else {
			if (!visited[p[0] + 1][p[1]][p[2] + 1][p[3]]) {
			visited[p[0] + 1][p[1]][p[2] + 1][p[3]] = true;
			dist[p[0] + 1][p[1]][p[2] + 1][p[3]] = dist[p[0]][p[1]][p[2]][p[3]] + 1;
			bfsQueue.push({p[0] + 1, p[1], p[2] + 1, p[3]});
			}
		}

		if (p[1] == m - 1 || blocked1[p[0]][p[1] + 1]) {
			if (p[3] != m - 1 && !blocked2[p[2]][p[3] + 1]) {
				if (!visited[p[0]][p[1]][p[2]][p[3] + 1]) {
				visited[p[0]][p[1]][p[2]][p[3] + 1] = true;
				dist[p[0]][p[1]][p[2]][p[3] + 1] = dist[p[0]][p[1]][p[2]][p[3]] + 1;
				bfsQueue.push({p[0], p[1], p[2], p[3] + 1});
				}
			}
		} else if (p[3] == m - 1 || blocked2[p[2]][p[3] + 1]) {
			if (!visited[p[0]][p[1] + 1][p[2]][p[3]]) {
			visited[p[0]][p[1] + 1][p[2]][p[3]] = true;
			dist[p[0]][p[1] + 1][p[2]][p[3]] = dist[p[0]][p[1]][p[2]][p[3]] + 1;
			bfsQueue.push({p[0], p[1] + 1, p[2], p[3]});
			}
		} else {
			if (!visited[p[0]][p[1] + 1][p[2]][p[3] + 1] + 1) {
			visited[p[0]][p[1] + 1][p[2]][p[3] + 1] = true;
			dist[p[0]][p[1] + 1][p[2]][p[3] + 1] = dist[p[0]][p[1]][p[2]][p[3]] + 1;
			bfsQueue.push({p[0], p[1] + 1, p[2], p[3] + 1});
			}
		}

		if (p[0] == 0 || blocked1[p[0] - 1][p[1]]) {
			if (p[2] != 0 && !blocked2[p[2] - 1][p[3]]) {
				if (!visited[p[0]][p[1]][p[2] - 1][p[3]]) {
				visited[p[0]][p[1]][p[2] - 1][p[3]] = true;
				dist[p[0]][p[1]][p[2] - 1][p[3]] = dist[p[0]][p[1]][p[2]][p[3]] + 1;
				bfsQueue.push({p[0], p[1], p[2] - 1, p[3]});
				}
			}
		} else if (p[2] == 0 || blocked2[p[2] - 1][p[3]]) {
			if (!visited[p[0] - 1][p[1]][p[2]][p[3]]) {
			visited[p[0] - 1][p[1]][p[2]][p[3]] = true;
			dist[p[0] - 1][p[1]][p[2]][p[3]] = dist[p[0]][p[1]][p[2]][p[3]] + 1;
			bfsQueue.push({p[0] - 1, p[1], p[2], p[3]});
			}
		} else {
			if (!visited[p[0] - 1][p[1]][p[2] - 1][p[3]]) {
			visited[p[0] - 1][p[1]][p[2] - 1][p[3]] = true;
			dist[p[0] - 1][p[1]][p[2] - 1][p[3]] = dist[p[0]][p[1]][p[2]][p[3]] + 1;
			bfsQueue.push({p[0] - 1, p[1], p[2] - 1, p[3]});
			}
		}

		if (p[1] == 0 || blocked1[p[0]][p[1] - 1]) {
			if (p[3] != 0 && !blocked2[p[2]][p[3] - 1]) {
				if (!visited[p[0]][p[1]][p[2]][p[3] - 1]) {
				visited[p[0]][p[1]][p[2]][p[3] - 1] = true;
				dist[p[0]][p[1]][p[2]][p[3] - 1] = dist[p[0]][p[1]][p[2]][p[3]] + 1;
				bfsQueue.push({p[0], p[1], p[2], p[3] - 1});
				}
			}
		} else if (p[3] == 0 || blocked2[p[2]][p[3] - 1]) {
			if (!visited[p[0]][p[1] - 1][p[2]][p[3]]) {
			visited[p[0]][p[1] - 1][p[2]][p[3]] = true;
			dist[p[0]][p[1] - 1][p[2]][p[3]] = dist[p[0]][p[1]][p[2]][p[3]] + 1;
			bfsQueue.push({p[0], p[1] - 1, p[2], p[3]});
			}
		} else {
			if (!visited[p[0]][p[1] - 1][p[2]][p[3] - 1]) {
			visited[p[0]][p[1] - 1][p[2]][p[3] - 1] = true;
			dist[p[0]][p[1] - 1][p[2]][p[3] - 1] = dist[p[0]][p[1]][p[2]][p[3]] + 1;
			bfsQueue.push({p[0], p[1] - 1, p[2], p[3] - 1});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> x1 >> y11 >> x2 >> y2 >> ex1 >> ey1 >> ex2 >> ey2;
	x1--; y11--; x2--; y2--; ex1--; ey1--; ex2--; ey2--;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '#') {
				blocked1[i][j] = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '#') {
				blocked2[i][j] = true;
			}
		}
	}
	bfs();
	cout << dist[ex1][ey1][ex2][ey2] << nl;

	// cout << ((minMoves(x1, y11, x2, y2) == 1e9) ? -1 : minMoves(x1, y11, x2, y2)) << nl;
}