/*
ID:azh248
LANG:C++
TASK:visitfj 
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

int n, t;
int arr[100][100];

class cmp {
  public:
	bool operator()(vector<int> a, vector<int> b) { 
		return a[2] > b[2]; 
	}
};

int dist[100][100][3];
vector<pii> adj[100][100];

void dijkstra(int rootX, int rootY) { // grid dijkstra
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 3; k++) {
				dist[i][j][k] = 1e9;
			}
		}
	}
	dist[rootX][rootY][0] = 0;
	priority_queue<vector<int>, vector<vector<int>>, cmp> nodes;
	nodes.push({rootX, rootY, 0, 0});
	while (!nodes.empty()) {
		int nodeX = nodes.top()[0];
		int nodeY = nodes.top()[1];
		int minDist = nodes.top()[2];
		int mod = nodes.top()[3];
		nodes.pop();
		if (minDist != dist[nodeX][nodeY][mod]) {
			continue;
		}
		for (pii i : adj[nodeX][nodeY]) {
			int neighborX = i.pA;
			int neighborY = i.pB;
			int eatGrass = 0;
			if (mod == 2) {
				eatGrass = arr[neighborX][neighborY];
			}
			if (dist[nodeX][nodeY][mod] + t + eatGrass < dist[neighborX][neighborY][(mod + 1) % 3]) {
				dist[neighborX][neighborY][(mod + 1) % 3] = dist[nodeX][nodeY][mod] + t + eatGrass;
				nodes.push({neighborX, neighborY, dist[neighborX][neighborY][(mod + 1) % 3], (mod + 1) % 3});
			}
		}
	}
}

int main() {
	freopen("visitfj.in", "r", stdin);
	freopen("visitfj.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > 0) {
				adj[i][j].pb({i - 1, j});
			}
			if (i < n - 1) {
				adj[i][j].pb({i + 1, j});
			}
			if (j > 0) {
				adj[i][j].pb({i, j - 1});
			}
			if (j < n - 1) {
				adj[i][j].pb({i, j + 1});
			}
		}
	}
	dijkstra(0, 0);
	cout << min(min(dist[n - 1][n - 1][0], dist[n - 1][n - 1][1]), dist[n - 1][n - 1][2]) << nl;
}
