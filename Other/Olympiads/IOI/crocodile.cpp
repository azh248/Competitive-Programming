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

int n, m, k;
vector<int> exits;

class cmp {
  public:
	bool operator()(vector<int> a, vector<int> b) { 
		return a[1] > b[1]; 
	}
};

pii dist[100000]; // 2 smallest distances to each node
vector<pii> adj[100000];
int shortestVis[100000]; // whether the shortest path for each node has already been taken

void dijkstra() { // traceback
	for (int i = 0; i < n; i++) {
		dist[i] = {1e9, 1e9};
		shortestVis[i] = 0;
	}
	priority_queue<vector<int>, vector<vector<int>>, cmp> nodes;
	for (int root : exits) {
		dist[root] = {0, 0};
		nodes.push({root, 0});
		shortestVis[root] = 1;
	}
	while (!nodes.empty()) {
		int node = nodes.top()[0];
		int minDist = nodes.top()[1];
		int pathInd = nodes.top()[2];
		nodes.pop();
		if (shortestVis[node] == 0) {
			shortestVis[node]++;
			continue;
		} else if (shortestVis[node] == 1) {
			shortestVis[node]++;
		} else {
			continue;
		}
		for (pii i : adj[node]) {
			int neighbor = i.pA;
			int length = i.pB;
			if (minDist + length < dist[neighbor].pA) {
				dist[neighbor].pB = dist[neighbor].pA;
				dist[neighbor].pA = minDist + length;
				nodes.push({neighbor, dist[neighbor].pA});
			} else if (minDist + length < dist[neighbor].pB) {
				dist[neighbor].pB = minDist + length;
				nodes.push({neighbor, dist[neighbor].pB});
			} 
		}
	}
}

int travel_plan(int n1, int m1, int (*r1) [2], int* L, int k1, int* P) {
	n = n1;
	m = m1;
	k = k1;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		a = r1[i][0];
		b = r1[i][1];
		c = L[i];
		adj[a].pb(pii(b, c));
		adj[b].pb(pii(a, c));
	}
	FOR(i, 0, k) { 
		exits.pb(P[i]);
	}
	dijkstra();
	return dist[0].pB;
}
// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> n >> m >> k;
// 	for (int i = 0; i < m; i++) {
// 		int a, b, c;
// 		cin >> a >> b >> c;
// 		adj[a].pb(pii(b, c));
// 		adj[b].pb(pii(a, c));
// 	}
// 	FOR(i, 0, k) {
// 		int num;
// 		cin >> num;
// 		exits.pb(num);
// 	}
// 	dijkstra();
// 	cout << dist[0].pB.pA << nl;
// }
