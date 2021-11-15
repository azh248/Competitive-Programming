#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;

vector<int> reverseAdj[10000];
int topo[10000];
int curr;
bool topovis[10000];
bool vis[10000];
vector<int> currVis;
vector<vector<int>> sccs;

void topodfs(int node) {
	topovis[node] = true;
	for (int i = 0; i < reverseAdj[node].size(); i++) {
		if (!topovis[reverseAdj[node][i]]) {
			topodfs(reverseAdj[node][i]);
		}
	}
	topo[--curr] = node;
}

void toposort() {
	for (int i = 0; i < n; i++) {
		if (!topovis[i]) {
			topodfs(i);
		}
	}
}

void dfs(int node) {
	vis[node] = true;
	currVis.pb(node);
	for (int i = 0; i < reverseAdj[node].size(); i++) {
		if (!vis[reverseAdj[node][i]]) {
			dfs(reverseAdj[node][i]);
		}
	}
}

void findSCCs() {
	toposort();
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs(i);
			sccs.pb(currVis);
			currVis = vector<int>();
		}
	}
}

struct DSU {
	vector<int> p;
	void init(int n) { p = vector<int>(n, -1); }
	int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); }
	bool sameSet(int x, int y) { return get(x) == get(y); }
	int size(int x) { return -1 * p[get(x)]; }
	bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) {
			return false;
		}
		if (p[x] > p[y]) {
			swap(x, y);
		}
		p[x] += p[y];
		p[y] = x;
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	curr = n;
	DSU dsu;
	dsu.init(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--; 
		reverseAdj[b].pb(a);
		dsu.unite(a, b);
	}
	findSCCs();
	int workingGroups = 0;
	for (auto i : sccs) {
		if (i.size() == dsu.size(i[0]) && i.size() != 1) {
			workingGroups++;
		}
	}
	cout << workingGroups << nl;
}