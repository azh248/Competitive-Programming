#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, ll>;

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

int n, m;

class cmp {
  public:
	bool operator()(vector<ll> a, vector<ll> b) { return a[1] > b[1]; }
};

ll dist[100000][2];
vector<pii> adj[100000];
vector<pii> radj[100000];
vector<vector<ll>> paths;

void dijkstra(int root) { // traceback
	for (int i = 0; i < n; i++) {
		dist[i][0] = 1e18;
	}
	dist[root][0] = 0;
	priority_queue<vector<ll>, vector<vector<ll>>, cmp> nodes;
	nodes.push({root, 0, -1});
	while (!nodes.empty()) {
		int node = nodes.top()[0];
		ll minDist = nodes.top()[1];
		int parent = nodes.top()[2];
		nodes.pop();
		if (minDist != dist[node][0]) {
			continue;
		}
		for (pii i : adj[node]) {
			int neighbor = i.pA;
			ll length = i.pB;
			if (dist[node][0] + length < dist[neighbor][0]) {
				dist[neighbor][0] = dist[node][0] + length;
				nodes.push({neighbor, dist[neighbor][0], node});
			}
		}
	}
}

void dijkstra1(int root) { // traceback
	for (int i = 0; i < n; i++) {
		dist[i][1] = 1e18;
	}
	dist[root][1] = 0;
	priority_queue<vector<ll>, vector<vector<ll>>, cmp> nodes;
	nodes.push({root, 0, -1});
	while (!nodes.empty()) {
		int node = nodes.top()[0];
		ll minDist = nodes.top()[1];
		int parent = nodes.top()[2];
		nodes.pop();
		if (minDist != dist[node][1]) {
			continue;
		}
		for (pii i : radj[node]) {
			int neighbor = i.pA;
			ll length = i.pB;
			if (dist[node][1] + length < dist[neighbor][1]) {
				dist[neighbor][1] = dist[node][1] + length;
				nodes.push({neighbor, dist[neighbor][1], node});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].pb(pii(b, c));
		radj[b].pb(pii(a, c));
		paths.pb({a, b, c});
	}
	dijkstra(0);
	dijkstra1(n - 1);
	ll minDist = 1e18;
	for (vector<ll> path : paths) {
		minDist = min(minDist, dist[path[0]][0] + dist[path[1]][1] + (int) (path[2]/2));
	}
	cout << minDist << nl;
}
