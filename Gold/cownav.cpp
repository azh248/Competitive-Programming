#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
bool haybale[20][20]{};

bool visited[20][20][20][20][4]{}; 
int dist[20][20][20][20][4]{}; // distance from starting node

void bfs() {
	queue<vector<int> > bfsQueue;
	visited[0][0][0][0][1] = true;
	bfsQueue.push({0, 0, 0, 0, 1});
	// memset(dist, 1e9, sizeof(dist));
	dist[0][0][0][0][1] = 0;
	while (!bfsQueue.empty()) {
		vector<int> node = bfsQueue.front();
		int distance = dist[node[0]][node[1]][node[2]][node[3]][node[4]];
		bfsQueue.pop();
		vector<int> neighbor = node;
		int x1 = neighbor[0];
		int y1 = neighbor[1];
		int x2 = neighbor[2];
		int y2 = neighbor[3];
		if (node[4] == 0) {
			if (x1 + 1 < n && !haybale[x1 + 1][y1] && (x1 != n - 1 || y1 != n - 1)) {
				neighbor[0]++;
			}
			if (y2 - 1 >= 0 && !haybale[x2][y2 - 1] && (x2 != n - 1 || y2 != n - 1)) {
				neighbor[3]--;
			}
		} else if (node[4] == 1) {
			if (y1 + 1 < n && !haybale[x1][y1 + 1] && (x1 != n - 1 || y1 != n - 1)) {
				neighbor[1]++;
			} 
			if (x2 + 1 < n && !haybale[x2 + 1][y2] && (x2 != n - 1 || y2 != n - 1)) {
				neighbor[2]++;
			}
		} else if (node[4] == 2) {
			if (x1 - 1 >= 0 && !haybale[x1 - 1][y1] && (x1 != n - 1 || y1 != n - 1)) {
				neighbor[0]--;
			}
			if (y2 + 1 < n && !haybale[x2][y2 + 1] && (x2 != n - 1 || y2 != n - 1)) {
				neighbor[3]++;
			}
		} else if (node[4] == 3) {
			if (y1 - 1 >= 0 && !haybale[x1][y1 - 1] && (x1 != n - 1 || y1 != n - 1)) {
				neighbor[1]--;
			} 
			if (x2 - 1 >= 0 && !haybale[x2 - 1][y2] && (x2 != n - 1 || y2 != n - 1)) {
				neighbor[2]--;
			}
		}
		if (!visited[neighbor[0]][neighbor[1]][neighbor[2]][neighbor[3]][neighbor[4]]) {
			visited[neighbor[0]][neighbor[1]][neighbor[2]][neighbor[3]][neighbor[4]] = true;
			bfsQueue.push(neighbor);
			dist[neighbor[0]][neighbor[1]][neighbor[2]][neighbor[3]][neighbor[4]] = distance + 1;
		}
		neighbor = node;
		neighbor[4] += 1;
		neighbor[4] %= 4;
		if (!visited[neighbor[0]][neighbor[1]][neighbor[2]][neighbor[3]][neighbor[4]]) {
			visited[neighbor[0]][neighbor[1]][neighbor[2]][neighbor[3]][neighbor[4]] = true;
			bfsQueue.push(neighbor);
			dist[neighbor[0]][neighbor[1]][neighbor[2]][neighbor[3]][neighbor[4]] = distance + 1;
		}
		neighbor = node;
		neighbor[4] += 3;
		neighbor[4] %= 4;
		if (!visited[neighbor[0]][neighbor[1]][neighbor[2]][neighbor[3]][neighbor[4]]) {
			visited[neighbor[0]][neighbor[1]][neighbor[2]][neighbor[3]][neighbor[4]] = true;
			bfsQueue.push(neighbor);
			dist[neighbor[0]][neighbor[1]][neighbor[2]][neighbor[3]][neighbor[4]] = distance + 1;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("cownav.in", "r", stdin);
	freopen("cownav.out", "w", stdout);
	cin >> n;
	for (int i = n - 1; i >= 0; i--) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'H') {
				haybale[i][j] = true;
			}
		}
	}	
	bfs();
	cout << min(min(dist[n - 1][n - 1][n - 1][n - 1][0], dist[n - 1][n - 1][n - 1][n - 1][1]), min(dist[n - 1][n - 1][n - 1][n - 1][2], dist[n - 1][n - 1][n - 1][n - 1][3])) << nl;
}
