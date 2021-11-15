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
vector<int> children[10000];

class cmp1 {
	public:
		bool operator()(vector<ll> a, vector<ll> b) {
			if (a[1] == b[1]) {
				return a[0] > b[0];
			}
			return a[1] > b[1];
		}
};

ll dist[10000];
bool visited[10000];
ll passThrough[10000];
int par[10000];
void dijkstra(int node) {
	for (int i = 0; i < n; i++) {
		dist[i] = 1e18;
	}
	dist[node] = 0;
	priority_queue<vector<ll>, vector<vector<ll> >, cmp1> nodes; // pii's are in the form {node, distance from starting node to that node}
	nodes.push({node, 0, - 1}); 
	while (!nodes.empty()) { // continously process the closest unvisited node and later process its neighbors
		int minDistNode = nodes.top()[0]; // min dist to starting node 
		int minDist = nodes.top()[1];
		int parent = nodes.top()[2];
		nodes.pop();
		if (visited[minDistNode]) {
			continue;
		}
		visited[minDistNode] = true;
		par[minDistNode] = parent;
		int node1 = minDistNode;
		while (node1 != 0) {
			passThrough[node1] += cows[minDistNode];
			node1 = par[node1];
		}
		for (pii i : adjLists[minDistNode]) {
			int neighbor = i.first;
			int length = i.second;
			if (minDist + length < dist[neighbor]) {
				dist[neighbor] = minDist + length;
				visited[neighbor] = false;
				nodes.push({neighbor, dist[neighbor], minDistNode}); // process the neighbor later
			}
		}
	}
}

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
		sort(adjLists[i].begin(), adjLists[i].end());
	}
	dijkstra(0);

	ll maxSaved = 0;
	for (int i = 0; i < n; i++) {
		maxSaved = max(maxSaved, (ll) passThrough[i] * (ll) (dist[i] - t));
	}
	cout << maxSaved << nl;
}
