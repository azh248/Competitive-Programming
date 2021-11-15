#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;

vector<int> adjLists[100000];
unordered_set<int> visited;
unordered_set<int> newVisited;

void dfs(int node) {
	visited.insert(node);
	newVisited.insert(node);
	for (int i = 0; i < adjLists[node].size(); i++) {
		int child = adjLists[node][i];
		if (visited.count(child) > 0) {
			continue;
		}
		dfs(adjLists[node][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adjLists[a].pb(b);
		adjLists[b].pb(a);
	}	
	ll ways = 1;
	for (int i = 0; i < n; i++) {
		if (visited.count(i) == 0) {
			dfs(i);
			int componentSize = newVisited.size();
			int componentEdges = 0;
			for (int j : newVisited) {
				componentEdges += adjLists[j].size();
			}
			componentEdges /= 2;
			if (componentSize == componentEdges) {
				ways *= 2;
				ways %= MOD;
			} else {
				ways *= componentSize;
				ways %= MOD;
			}
			newVisited.clear();
		}
	}
	cout << ways << nl;
}
