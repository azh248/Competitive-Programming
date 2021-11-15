#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m, q;

class cmp {
	public:
		bool operator()(pii a, pii b) {
			return a.second < b.second;
		}
};

int mNodes[10000]{};

vector<int> adjLists[10000]{}; // should be of size n
int dist[10000]{}; // distance from starting node
bool visited[10000]{};
void dijkstra(int node) {
	priority_queue<pii, vector<pii>, cmp> nodes; // pii's are in the form {node, distance from starting node to that node}
	for (int i : adjLists[node]) {
		nodes.push({i, dist[i]});
	}
	while (!nodes.empty()) { // continously process the closest unvisited node and later process its neighbors
		int minDistNode = nodes.top().first; // min dist to starting node 
		int minDist = nodes.top().second;
		nodes.pop();
		if (visited[minDistNode]) {
			continue;
		}
		visited[minDistNode] = true;
		for (int i : adjLists[minDistNode]) {
			int neighbor = i;
			if ((int)(minDist/2) > dist[neighbor] && mNodes[neighbor] == 0) {
				dist[neighbor] = (int)(minDist/2);
				nodes.push({neighbor, dist[neighbor]}); // process the neighbor later
			} 
		}
	}
}


bool cmp1(pii a, pii b) {
	return a.second > b.second;
}

bool cmp2(pii a, pii b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--;
		dist[a] = b;
		mNodes[a] = b;
	}
	visited[0] = true;
	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adjLists[a].pb(b);
		adjLists[b].pb(a);
	}
	dijkstra(0);
	vector<pii> friends;
	for (int i = 1; i < n; i++) {
		friends.pb({i, dist[i]});
	}
	sort(friends.begin(), friends.end(), cmp2);
	sort(friends.begin(), friends.end(), cmp1);
	for (int i = 0; i < n - 1; i++) {
		cout << friends[i].first + 1 << " " << friends[i].second << nl;
	}
}
