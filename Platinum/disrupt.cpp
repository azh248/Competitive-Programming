/*
ID:azh248
LANG:C++
TASK:disrupt 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

int n, m;

vector<int> adjLists[50000];
unordered_set<int> visited;
int par[50000];
pii edges[50000];
vector<pii> extraAdjLists[50000];
int optimalEdge[50000];

void treeDfs(int node) {
	for (int i = 0; i < adjLists[node].size(); i++) {
		int child = adjLists[node][i];
		if (child == par[node]) {
			continue;
		}
		par[child] = node;
		treeDfs(child);
	}
}

set<pii> calcWorkingEdges(int node) {
	if (adjLists[node].size() == 1 && node != 0) {
		set<pii> leafSet;
		for (pii i : extraAdjLists[node]) {
			leafSet.insert(i);
		}
		if (leafSet.size() == 0) {
			return leafSet;
		}
		optimalEdge[node] = (*leafSet.begin()).first;
		return leafSet;
	}
	set<pii> currWorkingEdges;
	for (pii i : extraAdjLists[node]) {
		currWorkingEdges.insert(i);
	}
	for (int i : adjLists[node]) {
		if (i != par[node]) {
			set<pii> neighborWorkingEdges = calcWorkingEdges(i);
			if (currWorkingEdges.size() < neighborWorkingEdges.size()) {
				swap(currWorkingEdges, neighborWorkingEdges);
			}
			for (pii i : neighborWorkingEdges) {
				if (currWorkingEdges.count(i) > 0) {
					currWorkingEdges.erase(i);
					continue;
				}
				currWorkingEdges.insert(i);
			}
		}
	}
	if (currWorkingEdges.size() == 0) {
		return currWorkingEdges;
	}
	optimalEdge[node] = (*currWorkingEdges.begin()).first;
	return currWorkingEdges;
}

int main() {
	freopen("disrupt.in", "r", stdin);
	freopen("disrupt.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		edges[i] = pii(a, b);
		adjLists[a].pb(b);
		adjLists[b].pb(a);
	}
	for (int i = 0; i < m; i++) {
		int a, b, l; cin >> a >> b >> l; a--; b--;
		extraAdjLists[a].pb(pii(l, i));
		extraAdjLists[b].pb(pii(l, i));
	}
	memset(optimalEdge, -1, sizeof(optimalEdge));
	treeDfs(0);
	calcWorkingEdges(0);
	for (int i = 0; i < n - 1; i++) {
		pii edge = edges[i];
		if (par[edge.first] == edge.second) {
			cout << optimalEdge[edge.first] << nl;
		} else {
			cout << optimalEdge[edge.second] << nl;
		}
	}
}
