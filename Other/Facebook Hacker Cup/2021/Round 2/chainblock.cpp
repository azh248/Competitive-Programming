#include <vector>
#include <iostream>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t, n;
vector<int> adj[800001];
int par[800001];
vector<int> frequency[800001];
int ctr[800001];

int dist[800001];
int anc[800001][21];

int blockaded = 0;

void findAncestors() {
	for (int i = 1; i < n; i++) {
		if (dist[i] != 0) {
			anc[i][0] = par[i];
		}
	}
	for (int j = 1; j <= 20; j++) {
		for (int i = 0; i < n; i++) {
			if (dist[i] != 0) {
				anc[i][j] = anc[anc[i][j - 1]][j - 1];
			}
		}
	}
}

void treeDfs(int node) {
	for (int i : adj[node]) {
		if (i == par[node]) {
			continue;
		}
		par[i] = node;
		dist[i] = dist[node] + 1;
		treeDfs(i);
	}
}

int lca(int a, int b) {
	if (dist[a] > dist[b]) { // swap if a is further
		return lca(b, a);
	}
	if (dist[a] < dist[b]) { // find ancestor of b that's the same depth as a
		for (int k = 20; dist[b] != dist[a]; k--) {
			while (dist[b] - (1 << k) >= dist[a]) {
				b = anc[b][k];
			}
		}
	}
	for (int k = 20; k > 0; k--) {
		while (anc[a][k] != anc[b][k]) {
			a = anc[a][k];
			b = anc[b][k];
		}
	}
	while (a != b) {
		a = par[a];
		b = par[b];
	}
	return a;
}

int dfs(int node) {
	int currCtr = 0;
	for (int i : adj[node]) {
		if (i == par[node]) {
			continue;
		}
		par[i] = node;
		currCtr += dfs(i);
	}
	currCtr += ctr[node];
	if (currCtr == 0 && node != 0) {
		blockaded++;
	}
	return currCtr;
}

int main() {
	freopen("chainblock_input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		if (t1 == 10) {
			int num = 0;
		}
		cin >> n;
		blockaded = 0;
		for (int i = 0; i < n; i++) {
			adj[i].clear();
			frequency[i].clear();
			ctr[i] = 0;
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b; cin >> a >> b; a--; b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		par[0] = -1;
		dist[0] = 0;
		treeDfs(0);
		findAncestors();
		for (int i = 0; i < n; i++) {
			int f; cin >> f; f--;
			frequency[f].pb(i);
		}
		for (int freq = 0; freq < n; freq++) {
			if (frequency[freq].size() == 0) {
				continue;
			}
			int commonLCA = frequency[freq][0];
			for (int i : frequency[freq]) {
				ctr[i]++;
				commonLCA = lca(commonLCA, i);
			}
			ctr[commonLCA] -= frequency[freq].size();
		}
		dfs(0);
		cout << "Case #" << t1 << ": " << blockaded << nl;
	}
}
