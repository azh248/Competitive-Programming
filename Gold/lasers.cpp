/*
ID:azh248
LANG:C++
TASK:lasers 
*/

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, x1, y11, x2, y2;
vector<int> adjLists[200000]; // should be of size n
unordered_set<int> visited;
int dist[200000]; // distance from starting node
unordered_map<int, int> edgeIDx;
unordered_map<int, int> edgeIDy;
int edgeNumber = 0;

int bfs(int root) {
	queue<int> bfsQueue;
	visited.insert(root);
	bfsQueue.push(root);
	dist[root] = 0;
	while (!bfsQueue.empty()) {
		int node = bfsQueue.front();
		bfsQueue.pop();
		for (int i = 0; i < adjLists[node].size(); i++) {
			int neighbor = adjLists[node][i];
			if (visited.count(neighbor) == 0) {
				visited.insert(neighbor);
				bfsQueue.push(neighbor);
				dist[neighbor] = dist[node] + 1;
			}
		}
	}
	return visited.size();
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
    cin >> n >> x1 >> y11 >> x2 >> y2;
	// represent each point as an edge between the line nodes --> we can then find the minimum number of edges required 
	edgeIDx.insert(make_pair(x1, edgeNumber));
	edgeNumber++;
	edgeIDy.insert(make_pair(y11, edgeNumber));
	edgeNumber++;
	edgeIDx.insert(make_pair(x2, edgeNumber));
	edgeNumber++;
	edgeIDy.insert(make_pair(y2, edgeNumber));
	edgeNumber++;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		if (edgeIDx.find(x) == edgeIDx.end()) {
			edgeIDx.insert(make_pair(x, edgeNumber));
			edgeNumber++;
		} 
		if (edgeIDy.find(y) == edgeIDy.end()) {
			edgeIDy.insert(make_pair(y, edgeNumber));
			edgeNumber++;
		}
		adjLists[(*edgeIDx.find(x)).second].pb((*edgeIDy.find(y)).second);
		adjLists[(*edgeIDy.find(y)).second].pb((*edgeIDx.find(x)).second);	
	}	
	fill(dist, dist + 2 * n, 1e9);
	int minimum = 1e9;
	bfs(0);
	minimum = min(minimum, min(dist[2], dist[3]));
	visited.clear();
	bfs(1);
	minimum = min(minimum, min(dist[2], dist[3]));
	cout << minimum << nl;
}
