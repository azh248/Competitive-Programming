/*
ID:azh248
LANG:C++
TASK:timeline 
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

int n, m, c;
int minDay[100000];
vector<pii> adj[100000];
int topo[100000];
int curr;
bool topovis[100000];

void topodfs(int node) {
	topovis[node] = true;
	for (int i = 0; i < adj[node].size(); i++) {
		if (!topovis[adj[node][i].first]) {
			topodfs(adj[node][i].first);
		}
	}
	topo[--curr] = node;
}

void toposort() {
	curr = n;
	for (int i = 0; i < n; i++) {
		if (!topovis[i]) {
			topodfs(i);
		}
	}
}

vector<vector<int>> edges;

int main() {
	freopen("timeline.in", "r", stdin);
	freopen("timeline.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++) {
		cin >> minDay[i];
	}
	for (int i = 0; i < c; i++) {
		int a, b, x;
		cin >> a >> b >> x;
		a--;
		b--;
		adj[a].pb(pii(b, x));
		edges.pb({a, b, x});
	}
	toposort();
	for (int i = 0; i < n; i++) {
		for (pii j : adj[topo[i]]) {
			minDay[j.first] = max(minDay[j.first], minDay[topo[i]] + j.second);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << minDay[i] << nl;
	}
}
