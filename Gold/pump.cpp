/*
ID:azh248
LANG:C++
TASK:pump 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define F0R1(i, a) for (int i = 1; i <= (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i = a; i > 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())
#define S0RT(arr, n) sort(arr, arr + n)

#define pA first
#define pB second
#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;
vector<vector<int>> adj[1000];
vector<vector<int>> paths;

class cmp {
  public:
	bool operator()(vector<int> a, vector<int> b) { return a[1] > b[1]; }
};

int dist[1000];

void dijkstra(int root, int minflow) { // traceback
	fill(dist, dist + n, 1e9);
	dist[root] = 0;
	priority_queue<vector<int>, vector<vector<int>>, cmp> nodes;
	nodes.push({root, 0, -1});
	while (!nodes.empty()) {
		int node = nodes.top()[0];
		int minDist = nodes.top()[1];
		int parent = nodes.top()[2];
		nodes.pop();
		if (minDist != dist[node]) {
			continue;
		}
		for (vector<int> i : adj[node]) {
			int neighbor = i[0];
			int cost = i[1];
			int flow = i[2];
			if (flow < minflow) {
				continue;
			}
			if (dist[node] + cost < dist[neighbor]) {
				dist[neighbor] = dist[node] + cost;
				nodes.push({neighbor, dist[neighbor], node});
			}
		}
	}
}

int dist1[1000];

void dijkstra1(int root, int minflow) { // traceback
	fill(dist1, dist1 + n, 1e9);
	dist1[root] = 0;
	priority_queue<vector<int>, vector<vector<int>>, cmp> nodes;
	nodes.push({root, 0, -1});
	while (!nodes.empty()) {
		int node = nodes.top()[0];
		int minDist = nodes.top()[1];
		int parent = nodes.top()[2];
		nodes.pop();
		if (minDist != dist1[node]) {
			continue;
		}
		for (vector<int> i : adj[node]) {
			int neighbor = i[0];
			int cost = i[1];
			int flow = i[2];
			if (flow < minflow) {
				continue;
			}
			if (dist1[node] + cost < dist1[neighbor]) {
				dist1[neighbor] = dist1[node] + cost;
				nodes.push({neighbor, dist1[neighbor], node});
			}
		}
	}
}



int main() {
	freopen("pump.in", "r", stdin);
	freopen("pump.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c, f;
		cin >> a >> b >> c >> f;
		a--;
		b--;
		adj[a].pb({b, c, f});
		adj[b].pb({a, c, f});
		paths.pb({a, b, c, f});
	}
	int maxNum = 0;
	for (vector<int> path : paths) {
		dijkstra(0, path[3]);
		dijkstra1(n - 1, path[3]);
		int cost1 = dist[path[0]] + dist1[path[1]] + path[2];
		int cost2 = dist[path[1]] + dist1[path[0]] + path[2];
		maxNum = max(maxNum, (1000000 * path[3]) / min(cost1, cost2));
	}
	// for (int minflow = 1; minflow <= 1000; minflow++) {
		// dijkstra(0, minflow);
		// if (dist1[n - 1] != 1e9) {
			// maxNum = max(maxNum, (int)((double)(1000000 * minflow)/dist1[n - 1]));
		// }
	// }
	cout << maxNum << nl;
}
