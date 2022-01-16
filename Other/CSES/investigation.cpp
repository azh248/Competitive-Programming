#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

#define FOR(i, a, b) for (ll i = a; i < (b); i++)
#define F0R(i, a) for (ll i = 0; i < (a); i++)
#define F0R1(i, a) for (ll i = 1; i <= (a); i++)
#define FORd(i, a, b) for (ll i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (ll i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (ll i = a; i > 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())
#define S0RT(arr, n) sort(arr, arr + n)

#define pA first
#define pB second
#define MOD 1000000007
#define nl "\n"
#define pb push_back

ll n, m;
vector<pii> adj[100000];

class cmp1 {
  public:
	bool operator()(vector<ll> a, vector<ll> b) { 
		if (a[1] == b[1]) {
			return a[3] > b[3];
		}
		return a[1] > b[1]; 
	}
};

pii dist1[100000]; // { minimum distance, minimum flights to get there }

void dijkstra1(ll root) { // traceback
	for (ll i = 0; i < n; i++) {
		dist1[i].pA = 1e18;
		dist1[i].pB = 1e18;
	}
	dist1[root].pA = 0;
	dist1[root].pB = 0;
	priority_queue<vector<ll>, vector<vector<ll>>, cmp1> nodes;
	nodes.push({root, 0, -1, 0});
	while (!nodes.empty()) {
		ll node = nodes.top()[0];
		ll minDist = nodes.top()[1];
		ll parent = nodes.top()[2];
		ll flights = nodes.top()[3];
		nodes.pop();
		if (minDist != dist1[node].pA || flights != dist1[node].pB) {
			continue;
		}
		for (pii i : adj[node]) {
			ll neighbor = i.pA;
			ll length = i.pB;
			if (dist1[node].pA + length < dist1[neighbor].pA) {
				dist1[neighbor].pA = dist1[node].pA + length;
				dist1[neighbor].pB = dist1[node].pB + 1;
				nodes.push({neighbor, dist1[neighbor].pA, node, dist1[neighbor].pB});
			} else if (dist1[node].pA + length == dist1[neighbor].pA && dist1[node].pB + 1 < dist1[neighbor].pB) {
				dist1[neighbor].pB = dist1[node].pB + 1;
				nodes.push({neighbor, dist1[neighbor].pA, node, dist1[neighbor].pB});
			}
		}
	}
}

class cmp2 {
  public:
	bool operator()(vector<ll> a, vector<ll> b) { 
		if (a[1] == b[1]) {
			return a[3] < b[3];
		}
		return a[1] > b[1]; 
	}
};

pii dist2[100000]; // { minimum distance, maximum number of flights to get there }

void dijkstra2(ll root) { // traceback
	for (ll i = 0; i < n; i++) {
		dist2[i].pA = 1e18;
		dist2[i].pB = -1;
	}
	dist2[root].pA = 0;
	dist2[root].pB = 0;
	priority_queue<vector<ll>, vector<vector<ll>>, cmp2> nodes;
	nodes.push({root, 0, -1, 0});
	while (!nodes.empty()) {
		ll node = nodes.top()[0];
		ll minDist = nodes.top()[1];
		ll parent = nodes.top()[2];
		ll flights = nodes.top()[3];
		nodes.pop();
		if (minDist != dist2[node].pA) {
			continue;
		}
		for (pii i : adj[node]) {
			ll neighbor = i.pA;
			ll length = i.pB;
			if (dist2[node].pA + length < dist2[neighbor].pA) {
				dist2[neighbor].pA = dist2[node].pA + length;
				dist2[neighbor].pB = dist2[node].pB + 1;
				nodes.push({neighbor, dist2[neighbor].pA, node, dist2[neighbor].pB});
			} else if (dist2[node].pA + length == dist2[neighbor].pA && dist2[node].pB + 1 > dist2[neighbor].pB) {
				dist2[neighbor].pB = dist2[node].pB + 1;
				nodes.push({neighbor, dist2[neighbor].pA, node, dist2[neighbor].pB});	
			}
		}
	}
}



// dijkstra's PQ guarantees that we always process minimum price routes first so we don't have to worry about 
// processing a node and then having another node connect to it with a minimum price route later, as that node
// will always be processed before this node since it has a lesser distance

class cmp3 {
  public:
	bool operator()(vector<ll> a, vector<ll> b) { 
		return a[1] > b[1]; 
	}
};

pii dist3[100000]; // { minimum distance, number of ways to get that distance }

void dijkstra3(ll root) { // traceback
	for (ll i = 0; i < n; i++) {
		dist3[i].pA = 1e18;
		dist3[i].pB = 0;
	}
	dist3[root] = {0, 1};
	priority_queue<vector<ll>, vector<vector<ll>>, cmp3> nodes;
	nodes.push({root, 0, -1, 1});
	while (!nodes.empty()) {
		ll node = nodes.top()[0];
		ll minDist = nodes.top()[1];
		ll parent = nodes.top()[2];
		ll ways = nodes.top()[3];
		nodes.pop();
		if (minDist != dist3[node].pA || ways != dist3[node].pB) {
			continue;
		}
		for (pii i : adj[node]) {
			ll neighbor = i.pA;
			ll length = i.pB;
			if (dist3[node].pA + length < dist3[neighbor].pA) {
				dist3[neighbor].pA = dist3[node].pA + length;
				dist3[neighbor].pB = ways;
				dist3[neighbor].pB %= MOD;
				nodes.push({neighbor, dist3[neighbor].pA, node, dist3[neighbor].pB});
			} else if (dist3[node].pA + length == dist3[neighbor].pA) {
				dist3[neighbor].pB += ways;
				dist3[neighbor].pB %= MOD;
				nodes.push({neighbor, dist3[neighbor].pA, node, dist3[neighbor].pB});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].pb(pii(b, c));
	}
	dijkstra1(0);
	dijkstra2(0);
	dijkstra3(0);
	cout << dist1[n - 1].pA << " " << dist3[n - 1].pB << " " << dist1[n - 1].pB << " " << dist2[n - 1].pB << nl;
}
