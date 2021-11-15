#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;

ll dpBottom[5000]; // dpBottom[i] = # of paths that go from node i to a leaf
ll dpTop[5000]; // dpTop[i] = # of paths that go from node i to the root

pii paths[50000]; // array of all paths in the form {parent, child}

vector<int> children[5000];
vector<int> parents[5000];

ll maxPathsBottom(int node) {
	if (children[node].size() == 0) {
		return 1;
	} else if (dpBottom[node] != -1) {
		return dpBottom[node];
	}
	ll paths = 0;
	for (int i : children[node]) {
		paths += maxPathsBottom(i);
	}
	return paths;
}

ll maxPathsTop(int node) {
	if (parents[node].size() == 0) {
		return 1;
	} else if (dpTop[node] != -1) {
		return dpTop[node];
	}
	ll paths = 0;
	for (int i : parents[node]) {
		paths += maxPathsTop(i);
	}
	return paths;
}

ll maxPaths(int trail) {
	// max paths going through this path
	return maxPathsTop(paths[trail].first) * maxPathsBottom(paths[trail].second);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> paths[i].first >> paths[i].second;
		paths[i].first--;
		paths[i].second--;
		children[paths[i].first].pb(paths[i].second);
		parents[paths[i].second].pb(paths[i].first);
	}	
	memset(dpTop, -1, sizeof(dpTop));
	memset(dpBottom, -1, sizeof(dpBottom));
	ll paths = 0;
	for (int i = 0; i < m; i++) {
		paths = max(paths, maxPaths(i));
	}
	cout << paths << nl;
}
