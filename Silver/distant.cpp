/*
ID:azh248
LANG:C++
TASK:distant 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, a, b;
char arr[40][40];
int dist[1600][1600];
vector<pii> adjLists[1600];
int maxDist = 0;

class cmp {
	public:
		bool operator()(pii a, pii b) {
			return a.second > b.second;
		}
};

void dijkstra(int node) {
	for (int i = 0; i < n * n; i++) {
		dist[node][i] = 1e9;
	}
	dist[node][node] = 0;
	priority_queue<pii, vector<pii>, cmp> nodes; // pii's are in the form {node, distance from starting node to
			   // that node}
	nodes.push(make_pair(node, 0));
	while (!nodes.empty()) { // continously process the closest unvisited node
							 // and later process its neighbors
		int minDistNode = nodes.top().first; // min dist to starting node
		int minDist = nodes.top().second;
		nodes.pop();
		if (minDist != dist[node][minDistNode]) {
			continue;
		}
		maxDist = max(maxDist, minDist);
		for (pii i : adjLists[minDistNode]) {
			int neighbor = i.first;
			int length = i.second;
			if (dist[node][minDistNode] + length < dist[node][neighbor]) {
				dist[node][neighbor] = dist[node][minDistNode] + length;
				nodes.push(make_pair(neighbor, dist[node][neighbor])); // process the neighbor later
			}
		}
	}
}

int travelTime(int i, int j) {
	if (arr[i/n][i%n] == arr[j/n][j%n]) {
		return a;
	} else {
		return b;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("distant.in", "r", stdin);
	freopen("distant.out", "w", stdout);
    cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j];
		}		
	}	
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			int num = i * n + j;
			adjLists[num].pb(make_pair(num - 1, travelTime(num, num - 1)));
			adjLists[num].pb(make_pair(num + 1, travelTime(num, num + 1)));
			adjLists[num].pb(make_pair(num - n, travelTime(num, num - n)));
			adjLists[num].pb(make_pair(num + n, travelTime(num, num + n)));
		}
	}
	for (int j = 1; j < n - 1; j++) {
		int num = j;
		adjLists[num].pb(make_pair(num - 1, travelTime(num, num - 1)));
		adjLists[num].pb(make_pair(num + 1, travelTime(num, num + 1)));
		adjLists[num].pb(make_pair(num + n, travelTime(num, num + n)));
		num = (n - 1) * n + j;
		adjLists[num].pb(make_pair(num - 1, travelTime(num, num - 1)));
		adjLists[num].pb(make_pair(num + 1, travelTime(num, num + 1)));
		adjLists[num].pb(make_pair(num - n, travelTime(num, num - n)));
	}
	for (int i = 1; i < n - 1; i++) {
		int num = i * n;
		adjLists[num].pb(make_pair(num + 1, travelTime(num, num + 1)));
		adjLists[num].pb(make_pair(num - n, travelTime(num, num - n)));
		adjLists[num].pb(make_pair(num + n, travelTime(num, num + n)));
		num = i * n + n - 1;
		adjLists[num].pb(make_pair(num - 1, travelTime(num, num - 1)));
		adjLists[num].pb(make_pair(num - n, travelTime(num, num - n)));
		adjLists[num].pb(make_pair(num + n, travelTime(num, num + n)));
	}
	int num = 0;
	adjLists[num].pb(make_pair(num + 1, travelTime(num, num + 1)));
	adjLists[num].pb(make_pair(num + n, travelTime(num, num + n)));
	num = n - 1;
	adjLists[num].pb(make_pair(num - 1, travelTime(num, num - 1)));
	adjLists[num].pb(make_pair(num + n, travelTime(num, num + n)));
	num = n * (n - 1);
	adjLists[num].pb(make_pair(num + 1, travelTime(num, num + 1)));
	adjLists[num].pb(make_pair(num - n, travelTime(num, num - n)));
	num = n * n - 1;
	adjLists[num].pb(make_pair(num - 1, travelTime(num, num - 1)));
	adjLists[num].pb(make_pair(num - n, travelTime(num, num - n)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dijkstra(i * n + j);
		}
	}
	cout << maxDist << nl;
}
