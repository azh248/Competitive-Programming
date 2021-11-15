/*
ID:azh248
LANG:C++
TASK:dream 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, m;
int arr[1000000];
int visited[1000000][2]; // oranges and sliding
int dist[1000000][2]; // distance from starting node

void bfs(int root) {
	queue<vector<int> > bfsQueue;
	visited[root][0] = true;
	bfsQueue.push({root, 0});
	dist[root][0] = 0;
	while (!bfsQueue.empty()) {
		int node = bfsQueue.front()[0];
		int oranges = bfsQueue.front()[1];
		bfsQueue.pop();
		if (node == (n * m) - 1) {
			return;
		}
		vector<int> adjList;
		if (node - m >= 0) {
			adjList.pb(node - m);
		} 
		if (node + m < (n * m)) {
			adjList.pb(node + m);
		}
		if ((node % m) + 1 != m) {
			adjList.pb(node + 1);
		}
		if ((node % m) - 1 != -1) {
			adjList.pb(node - 1);
		}
		for (int i = 0; i < adjList.size(); i++) {
			int neighbor = adjList[i];
			if ((arr[neighbor] == 0) || ((arr[neighbor] == 3) && (oranges == 0))) {
				continue;
			}
			int orangesNeighbor = ((arr[neighbor] == 2) || oranges) && (arr[neighbor] != 4);
			int slidingNeighbor = (arr[neighbor] == 4);
			if (!visited[neighbor][orangesNeighbor]) {
				if (slidingNeighbor) {
					if ((neighbor - node) == -1) {
						int neighbor1 = neighbor;
						int distFromNode = 1;
						while (((neighbor1 % m) - 1) != -1) {
							if (arr[neighbor1 - 1] != 4) {
								if (visited[neighbor1 - 1][arr[neighbor1 - 1] == 2]) {
									break;
								} else if ((arr[neighbor1 - 1] == 3) || (arr[neighbor1 - 1] == 0)) {
									neighbor1++;
									distFromNode--;
								}
								visited[neighbor1 - 1][arr[neighbor1 - 1] == 2] = true;
								dist[neighbor1 - 1][arr[neighbor1 - 1] == 2] = dist[node][oranges] + distFromNode + 1;
								bfsQueue.push({neighbor1 - 1, (arr[neighbor1 - 1] == 2)});
								break;
							} else {
								neighbor1--;
								distFromNode++;
							}
						}
						if (((neighbor1 % m) - 1) == -1) {
							neighbor1++;
							if (visited[neighbor1 - 1][arr[neighbor1 - 1] == 2]) {
								continue;
							} else if ((arr[neighbor1 - 1] == 3) || (arr[neighbor1 - 1] == 0)) {
								neighbor1++;
								distFromNode--;
							}
							visited[neighbor1 - 1][arr[neighbor1 - 1] == 2] = true;
							dist[neighbor1 - 1][arr[neighbor1 - 1] == 2] = dist[node][oranges] + distFromNode;
							bfsQueue.push({neighbor1 - 1, (arr[neighbor1 - 1] == 2)});
						}
					} else if ((neighbor - node) == 1) {
						int neighbor1 = neighbor;
						int distFromNode = 1;
						while (((neighbor1 % m) + 1) != m) {
							if (arr[neighbor1 + 1] != 4) {
								if (visited[neighbor1 + 1][arr[neighbor1 + 1] == 2]) {
									break;
								} else if ((arr[neighbor1 + 1] == 3) || (arr[neighbor1 + 1] == 0)) {
									neighbor1--;
									distFromNode--;
								}
								visited[neighbor1 + 1][arr[neighbor1 + 1] == 2] = true;
								dist[neighbor1 + 1][arr[neighbor1 + 1] == 2] = dist[node][oranges] + distFromNode + 1;
								bfsQueue.push({neighbor1 + 1, (arr[neighbor1 + 1] == 2)});
								break;
							} else {
								neighbor1++;
								distFromNode++;
							}
						}	
						if (((neighbor1 % m) + 1) == m) {
							neighbor1--;
							if (visited[neighbor1 + 1][arr[neighbor1 + 1] == 2]) {
								continue;
							} else if ((arr[neighbor1 + 1] == 3) || (arr[neighbor1 + 1] == 0)) {
								neighbor1--;
								distFromNode--;
							}
							visited[neighbor1 + 1][arr[neighbor1 + 1] == 2] = true;
							dist[neighbor1 + 1][arr[neighbor1 + 1] == 2] = dist[node][oranges] + distFromNode;
							bfsQueue.push({neighbor1 + 1, (arr[neighbor1 + 1] == 2)});
						}
					} else if ((neighbor - node) == m) {
						int neighbor1 = neighbor;
						int distFromNode = 1;
						while ((neighbor1 + m) < (n * m)) {
							if (arr[neighbor1 + m] != 4) {
								if (visited[neighbor1 + m][arr[neighbor1 + m] == 2]) {
									break;
								} else if ((arr[neighbor1 + m] == 3) || (arr[neighbor1 + m] == 0)) {
									neighbor1 -= m;
									distFromNode--;
								}
								visited[neighbor1 + m][arr[neighbor1 + m] == 2] = true;
								dist[neighbor1 + m][arr[neighbor1 + m] == 2] = dist[node][oranges] + distFromNode + 1;
								bfsQueue.push({neighbor1 + m, (arr[neighbor1 + m] == 2)});
								break;
							} else {
								neighbor1 += m;
								distFromNode++;
							}
						}	
						if ((neighbor1 + m) >= (n * m)) {
							neighbor1 -= m;
							if (visited[neighbor1 + m][arr[neighbor1 + m] == 2]) {
								continue;
							} else if ((arr[neighbor1 + m] == 3) || (arr[neighbor1 + m] == 0)) {
								neighbor1 -= m;
								distFromNode--;
							}
							visited[neighbor1 + m][arr[neighbor1 + m] == 2] = true;
							dist[neighbor1 + m][arr[neighbor1 + m] == 2] = dist[node][oranges] + distFromNode;
							bfsQueue.push({neighbor1 + m, (arr[neighbor1 + m] == 2)});
						}
					} else if ((neighbor - node) == -m) {
						int neighbor1 = neighbor;
						int distFromNode = 1;
						while ((neighbor1 - m) >= 0) {
							if (arr[neighbor1 - m] != 4) {
								if (visited[neighbor1 - m][arr[neighbor1 - m] == 2]) {
									break;
								} else if ((arr[neighbor1 - m] == 3) || (arr[neighbor1 - m] == 0)) {
									neighbor1 += m;
									distFromNode--;
								}
								visited[neighbor1 - m][arr[neighbor1 - m] == 2] = true;
								dist[neighbor1 - m][arr[neighbor1 - m] == 2] = dist[node][oranges] + distFromNode + 1;
								bfsQueue.push({neighbor1 - m, (arr[neighbor1 - m] == 2)});
								break;
							} else {
								neighbor1 -= m;
								distFromNode++;
							}
						}	
						if ((neighbor1 - m) < 0) {
							neighbor1 += m;
							if (visited[neighbor1 - m][arr[neighbor1 - m] == 2]) {
								continue;
							} else if ((arr[neighbor1 - m] == 3) || (arr[neighbor1 - m] == 0)) {
								neighbor1 += m;
								distFromNode--;
							}
							visited[neighbor1 - m][arr[neighbor1 - m] == 2] = true;
							dist[neighbor1 - m][arr[neighbor1 - m] == 2] = dist[node][oranges] + distFromNode;
							bfsQueue.push({neighbor1 - m, (arr[neighbor1 - m] == 2)});
						}
					}
					continue;
				} else {
					bfsQueue.push({neighbor, orangesNeighbor});
					visited[neighbor][orangesNeighbor] = true;
					dist[neighbor][orangesNeighbor] = dist[node][oranges] + 1;
				}
			}
		}
	}
}


int main() {
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i * m + j];
		}		
	}
	bfs(0);
	if ((dist[(n * m) - 1][0] == 0) && (dist[(n * m) - 1][1] == 0)) {
		cout << -1 << nl;
 	} else {
		 if (dist[(n * m) - 1][0] == 0) {
			 cout << dist[(n * m) - 1][1] << nl;
		 } else if (dist[(n * m) - 1][1] == 0) {
			 cout << dist[(n * m) - 1][0] << nl;
		 } else {
			 cout << min(dist[(n * m) - 1][0], dist[(n * m) - 1][1]) << nl;
		 }
	}
}
