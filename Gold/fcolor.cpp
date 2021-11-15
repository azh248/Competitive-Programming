/*
ID:azh248
LANG:C++
TASK:fcolor 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, m;

int par[200000];
vector<int> nodes[200000];
vector<int> adj[200000];
int cmp[200000]{};
queue<int> q;

void merge(int a, int b) {
	a = par[a];
	b = par[b];
	if (nodes[a].size() < nodes[b].size()) {
		swap(a, b);
	}
	for (int i : nodes[b]) {
		par[i] = a;
		nodes[a].pb(i);
	}
	for (int i : adj[b]) {
		adj[a].pb(i);
	}
	adj[b].clear();
	if (adj[a].size() > 1) {
		q.push(a);
	}
}

int main() {
	freopen("fcolor.in", "r", stdin);
	freopen("fcolor.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].pb(b);
	}	
	for (int i = 0; i < n; i++) {
		par[i] = i;
		nodes[i].pb(i);
		if (adj[i].size() > 1) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		while (adj[node].size() > 1) {
			int a = adj[node][adj[node].size() - 1];
			adj[node].pop_back();
			int b = adj[node][adj[node].size() - 1];
			if (par[a] != par[b]) {
				merge(a, b);
			}
		}
	}
	int cmpNum = 0;
	for (int i = 0; i < n; i++) {
		if (cmp[par[i]] == 0) {
			cmp[par[i]] = ++cmpNum;
		}
		cout << cmp[par[i]] << nl;
	}
}
