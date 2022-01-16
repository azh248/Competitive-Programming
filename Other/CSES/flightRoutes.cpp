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

int n, m, k;

class cmp {
  public:
	bool operator()(pii a, pii b) { return a.pB > b.pB; }
};

multiset<ll> dist[100000];
vector<pair<int, int>> adj[100000];

void dijkstra(int root) { // traceback
	dist[root].insert(0);
	priority_queue<pii, vector<pii>, cmp> nodes;
	nodes.push({root, 0});
	while (!nodes.empty()) {
		int node = nodes.top().pA;
		ll minDist = nodes.top().pB;
		nodes.pop();
		if (minDist > *(--dist[node].end())) {
			continue;
		}
		for (pair<int, int> i : adj[node]) {
			int neighbor = i.pA;
			int length = i.pB;
			if (dist[neighbor].size() < k) {
				dist[neighbor].insert(minDist + length);
				nodes.push(pii(neighbor, minDist + length));
			} else if (minDist + length < *--dist[neighbor].end()) {
				dist[neighbor].erase(--dist[neighbor].end());
				dist[neighbor].insert(minDist + length);
				nodes.push(pii(neighbor, minDist + length));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].pb(pii(b, c));
	}
	dijkstra(0);
	auto it = dist[n - 1].begin();
	FOR(i, 0, k) {
		cout << *it << " ";
		it++;
	}
	cout << nl;
}
