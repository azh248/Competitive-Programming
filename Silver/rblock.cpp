/*
ID:azh248
LANG:C++
TASK:rblock 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, m;

class cmp {
	public:
		bool operator()(vector<int> a, vector<int> b) {
			return a[1] > b[1];
		}
};

int dist[100];
int dist1[100];
vector<pii> adjLists[100];
unordered_map<int, int> adjListsIndexes[100];
int par[100];
int maxIncrease = 0;

class cmp1 {
	public:
		bool operator()(pii a, pii b) {
			return a.second > b.second;
		}
};

void dijkstra1(int node) {
	for (int i = 0; i < n; i++) {
		dist1[i] = 1e9;
	}
	dist1[node] = 0;
	priority_queue<pii, vector<pii>, cmp1> nodes; // pii's are in the form {node, distance from starting node to
			   // that node}
	nodes.push(make_pair(node, 0));
	while (!nodes.empty()) { // continously process the closest unvisited node
							 // and later process its neighbors
		int minDistNode = nodes.top().first; // min dist to starting node
		int minDist = nodes.top().second;
		nodes.pop();
		if (minDist != dist1[minDistNode]) {
			continue;
		}
		for (pii i : adjLists[minDistNode]) {
			int neighbor = i.first;
			int length = i.second;
			if (dist1[minDistNode] + length < dist1[neighbor]) {
				dist1[neighbor] = dist1[minDistNode] + length;
				nodes.push(make_pair(neighbor, dist1[neighbor])); // process the neighbor later
			}
		}
	}
}

void dijkstra(int node) { // traceback
	for (int i = 0; i < n; i++) {
		dist[i] = 1e9;
	}
	dist[node] = 0;
	priority_queue<vector<int>, vector<vector<int> >, cmp> nodes; // pii's are in the form {node, distance from starting node to
			   // that node}
	nodes.push({node, 0, -1});
	while (!nodes.empty()) { // continously process the closest unvisited node
							 // and later process its neighbors
		int minDistNode = nodes.top()[0]; // min dist to starting node
		int minDist = nodes.top()[1];
		int parent = nodes.top()[2];
		nodes.pop();
		if (minDist != dist[minDistNode]) {
			continue;
		}
		par[minDistNode] = parent;
		if (minDistNode == n - 1) {
			int node1 = n - 1;
			while (node1 != 0) {
				adjLists[par[node1]][(*adjListsIndexes[par[node1]].find(node1)).second].second *= 2;
				adjLists[node1][(*adjListsIndexes[node1].find(par[node1])).second].second *= 2;
				dijkstra1(0);
				int num = dist1[n - 1];
				maxIncrease = max(maxIncrease, dist1[n - 1] - dist[n - 1]);
				adjLists[par[node1]][(*adjListsIndexes[par[node1]].find(node1)).second].second /= 2;
				adjLists[node1][(*adjListsIndexes[node1].find(par[node1])).second].second /= 2;
				node1 = par[node1];
			}
			return;
		}
		for (pii i : adjLists[minDistNode]) {
			int neighbor = i.first;
			int length = i.second;
			if (dist[minDistNode] + length < dist[neighbor]) {
				dist[neighbor] = dist[minDistNode] + length;
				nodes.push({neighbor, dist[neighbor], minDistNode}); // process the neighbor later
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("rblock.in", "r", stdin);
	freopen("rblock.out", "w", stdout);
    cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, l; cin >> a >> b >> l; a--; b--;
		adjLists[a].pb({b, l});
		adjListsIndexes[a].insert({b, adjLists[a].size() - 1});
		adjLists[b].pb({a, l});
		adjListsIndexes[b].insert({a, adjLists[b].size() - 1});
	}	
	dijkstra(0);
	cout << maxIncrease << nl;
}
