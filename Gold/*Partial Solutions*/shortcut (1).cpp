/*
ID:azh248
LANG:C++
TASK:shortcut 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, ll>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, m, t;

vector<pii> adjLists[10000];

int cows[10000];

bool cmp(pii a, pii b) {
	return a.first < b.first;
}

class cmp1 {
	public:
		bool operator()(vector<ll> a, vector<ll> b) {
			if (a[1] == b[1]) {
				return a[0] > b[0];
			}
			return a[1] > b[1];
		}
};

vector<int> paths[10000]; // path with minimum distance from each node to barn

ll dist[10000];
bool visited[10000]{};
void dijkstra(int node) {
	for (int i = 0; i < n; i++) {
		dist[i] = 1e18;
	}
	dist[node] = 0;
	priority_queue<vector<ll>, vector<vector<ll> >, cmp1> nodes; // pii's are in the form {node, distance from starting node to that node}
	nodes.push({node, 0}); 
	while (!nodes.empty()) { // continously process the closest unvisited node and later process its neighbors
		int minDistNode = nodes.top()[0]; // min dist to starting node 
		int minDist = nodes.top()[1];
		int parent = nodes.top()[2];
		nodes.pop();
		if (visited[minDistNode]) {
			continue;
		}
		visited[minDistNode] = true;
		if (minDistNode != 0) {
			paths[minDistNode].pb(parent);
			for (int i : paths[parent]) {
				paths[minDistNode].pb(i);
			}	
		}
		for (pii i : adjLists[minDistNode]) {
			int neighbor = i.first;
			int length = i.second;
			if (dist[minDistNode] + length < dist[neighbor]) {
				dist[neighbor] = dist[minDistNode] + length;
				visited[neighbor] = false;
				nodes.push({neighbor, dist[neighbor], minDistNode}); // process the neighbor later
			}
		}
	}
}

ll passThrough[10000]{}; // the number of cows which pass through node i on their shortest path to the barn

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("shortcut.in", "r", stdin);
	freopen("shortcut.out", "w", stdout);
    cin >> n >> m >> t;

	for (int i = 0; i < n; i++) {
		cin >> cows[i];
	}	

	for (int i = 0; i < m; i++) {
		int a, b, t; cin >> a >> b >> t; a--; b--;
		adjLists[a].pb({b, t});
		adjLists[b].pb({a, t});
	}
	for (int i = 0; i < n; i++) {
		sort(adjLists[i].begin(), adjLists[i].end(), cmp);
	}
	dijkstra(0);
	for (int i = 1; i < n; i++) {
		for (int j : paths[i]) {
			passThrough[j] += cows[i];
		}
		passThrough[i] += cows[i];
	}
	ll maxSaved = 0;
	for (int i = 0; i < n; i++) {
		maxSaved = max(maxSaved, (ll) passThrough[i] * (ll) (dist[i] - t));
	}
	cout << maxSaved << nl;
}
