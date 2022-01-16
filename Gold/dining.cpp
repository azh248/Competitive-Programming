/*
ID:azh248
LANG:C++
TASK:dining 
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

int n, m, k;

class cmp {
  public:
	bool operator()(vector<int> a, vector<int> b) { return a[1] > b[1]; }
};

int dist[50000][2]; // index 0 is min dist without visiting a haybale, index 1 is with visiting a haybale
vector<pii> adj[500000];
set<int> haybales[50000]; // all haybales at each pasture

void dijkstra(int root) { // traceback
	for (int i = 0; i < n; i++) {
		dist[i][0] = 1e9;
		dist[i][1] = 1e9;
	}
	dist[root][0] = 0;
	priority_queue<vector<int>, vector<vector<int>>, cmp> nodes;
	nodes.push({root, 0, 0});
	if (haybales[root].size() > 0) {
		nodes.push({root, -*(--haybales[root].end()), 1});
	}
	while (!nodes.empty()) {
		int node = nodes.top()[0];
		int minDist = nodes.top()[1];
		int haybale = nodes.top()[2];
		nodes.pop();
		if (minDist != dist[node][haybale]) {
			continue;
		}
		for (pii i : adj[node]) {
			int neighbor = i.pA;
			int length = i.pB;
			if (!haybale) {
				if (haybales[neighbor].size() > 0) {
					int haybaleSubtract = *(--haybales[neighbor].end());
					if (dist[node][haybale] + length - haybaleSubtract < dist[neighbor][1]) {
						dist[neighbor][1] = dist[node][haybale] + length - haybaleSubtract;
						nodes.push({neighbor, dist[neighbor][1], 1});
					}
				}
			}
			if (dist[node][haybale] + length < dist[neighbor][haybale]) {
				dist[neighbor][haybale] = dist[node][haybale] + length;
				nodes.push({neighbor, dist[neighbor][haybale], haybale});
			}
		}
	}
}

int main() {
	freopen("dining.in", "r", stdin);
	freopen("dining.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].pb({b, c});
		adj[b].pb({a, c});
	}
	for (int i = 0; i < k; i++) {
		int pasture, yummy;
		cin >> pasture >> yummy;
		pasture--;
		haybales[pasture].insert(yummy);
	}
	dijkstra(n - 1);
	for (int i = 0; i < n - 1; i++) {
		if (dist[i][1] <= dist[i][0]) {
			cout << 1 << nl;
		} else {
			cout << 0 << nl;
		}
	}
}
