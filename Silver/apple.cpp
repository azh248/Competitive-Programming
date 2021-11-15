#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int c, p, start, end1, end2;

class cmp {
	public:
		bool operator()(pii a, pii b) {
			return a.second > b.second;
		}
};

vector<pii> adjLists[100000];

int dist[100000];

void dijkstra(int root) {
	fill(dist, dist + p, 1e9);
	dist[root] = 0;
	priority_queue<pii, vector<pii>, cmp> nodes; // pii's are in the form {node, distance from starting node to
			   // that node}
	nodes.push(make_pair(root, 0));
	while (!nodes.empty()) { // continously process the closest unvisited node
							 // and later process its neighbors
		int minDistNode = nodes.top().first; // min dist to starting node
		int minDist = nodes.top().second;
		nodes.pop();
		if (minDist != dist[minDistNode]) {
			continue;
		}
		for (pii i : adjLists[minDistNode]) {
			int neighbor = i.first;
			int length = i.second;
			if (dist[minDistNode] + length < dist[neighbor]) {
				dist[neighbor] = dist[minDistNode] + length;
				nodes.push(make_pair(neighbor, dist[neighbor])); // process the neighbor later
			}
		}
	}
}

int dist1[100000];

void dijkstra1(int root) {
	fill(dist1, dist1 + p, 1e9);
	dist1[root] = 0;
	priority_queue<pii, vector<pii>, cmp> nodes; // pii's are in the form {node, distance from starting node to
			   // that node}
	nodes.push(make_pair(root, 0));
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> p >> start >> end1 >> end2;
	start--;
	end1--;
	end2--;
	for (int i = 0; i < c; i++) {
		int a, b, d; cin >> a >> b >> d; a--; b--;
		adjLists[a].pb({b, d});
		adjLists[b].pb({a, d});
	}	
	dijkstra(start);
	dijkstra1(end1);
	cout << min(dist[end1], dist[end2]) + dist1[end2] << nl;
}
