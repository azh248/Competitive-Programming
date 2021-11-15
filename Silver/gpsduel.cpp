/*
ID:azh248
LANG:C++
TASK:gpsduel 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

int n, m;
vector<pii> adjLists1[10000];
int dist1[10000];
int parent1[10000];
vector<pii> adjLists2[10000];
int dist2[10000];
int parent2[10000];

vector<pii> complaintAdjLists[10000];

class cmp {
  public:
	bool operator()(pii a, pii b) { return a.second > b.second; }
};

void dijkstra1(int node) {
	for (int i = 0; i < n; i++) {
		dist1[i] = 1e9;
	}
	dist1[node] = 0;
	priority_queue<pii, vector<pii>, cmp> nodes; // pii's are in the form {node, distance from starting node to
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
		for (pii i : adjLists1[minDistNode]) {
			int neighbor = i.first;
			int length = i.second;
			if (dist1[minDistNode] + length < dist1[neighbor]) {
				dist1[neighbor] = dist1[minDistNode] + length;
				nodes.push(make_pair(neighbor, dist1[neighbor])); // process the neighbor later
			}
		}
	}
}

void dijkstra2(int node) {
	for (int i = 0; i < n; i++) {
		dist2[i] = 1e9;
	}
	dist2[node] = 0;
	priority_queue<pii, vector<pii >, cmp>
		nodes; // pii's are in the form {node, distance from starting node to
			   // that node}
	nodes.push(make_pair(node, 0));
	while (!nodes.empty()) { // continously process the closest unvisited node
							 // and later process its neighbors
		int minDistNode = nodes.top().first; // min dist to starting node
		int minDist = nodes.top().second;
		nodes.pop();
		if (minDist != dist2[minDistNode]) {
			continue;
		}
		for (pii i : adjLists2[minDistNode]) {
			int neighbor = i.first;
			int length = i.second;
			if (dist2[minDistNode] + length < dist2[neighbor]) {
				dist2[neighbor] = dist2[minDistNode] + length;
				nodes.push(make_pair(neighbor, dist2[neighbor])); // process the neighbor later
			}
		}
	}
}

int dist[10000];
void dijkstra(int node) {
	for (int i = 0; i < n; i++) {
		dist[i] = 1e9;
	}
	dist[node] = 0;
	priority_queue<pii, vector<pii>, cmp> nodes; // pii's are in the form {node, distance from starting node to
			   // that node}
	nodes.push(make_pair(node, 0));
	while (!nodes.empty()) { // continously process the closest unvisited node
							 // and later process its neighbors
		int minDistNode = nodes.top().first; // min dist to starting node
		int minDist = nodes.top().second;
		nodes.pop();
		if (minDist != dist[minDistNode]) {
			continue;
		}
		for (pii i : complaintAdjLists[minDistNode]) {
			int neighbor = i.first;
			int length = i.second;
			if (dist[minDistNode] + length < dist[neighbor]) {
				dist[neighbor] = dist[minDistNode] + length;
				nodes.push(make_pair(neighbor, dist[neighbor])); // process the neighbor later
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("gpsduel.in", "r", stdin);
	freopen("gpsduel.out", "w", stdout);
	cin >> n >> m;
	// find shortest path for both gps maps, add weight 2 for each edge if it's part of neither shortest path, weight 1 if it's part of 1 shortest path, and weigth 0 if it's part of both
	// then find the shortest path on this graph and print the sum of weights
	for (int i = 0; i < m; i++) {
		int a, b, p, q; cin >> a >> b >> p >> q; a--; b--;
		complaintAdjLists[a].pb(make_pair(b, 2));
		adjLists1[b].pb(make_pair(a, p));
		adjLists2[b].pb(make_pair(a, q));
	}
	dijkstra1(n - 1);
	dijkstra2(n - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < adjLists1[i].size(); j++) {
			int cnt = 0;
			if (dist1[adjLists1[i][j].first] - dist1[i] != adjLists1[i][j].second) {
				cnt++;
			}
			if (dist2[adjLists2[i][j].first] - dist2[i] != adjLists2[i][j].second) {
				cnt++;
			}
			complaintAdjLists[adjLists1[i][j].first].pb(make_pair(i, cnt));
		}
	}
	dijkstra(0);
	cout << dist[n - 1] << nl;
}
