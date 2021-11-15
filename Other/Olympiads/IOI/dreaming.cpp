#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m, l;

vector<pii> adjLists[100000];
unordered_set<int> visited;
unordered_set<int> visited1;
int dist[100000];
int par[100000];

bool cmp(int a, int b) {
	return a > b;
}

void dfs(int node) {
	visited1.insert(node);
	visited.insert(node);
	for (int i = 0; i < adjLists[node].size(); i++) {
		pii child = adjLists[node][i];
		if (visited1.count(child.first) > 0) {
			continue;
		}
		dist[child.first] = dist[node] + child.second;
		par[child.first] = node;
		dfs(child.first);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> l;
	for (int i = 0; i < m; i++) {
		int a, b, t; cin >> a >> b >> t;
		adjLists[a].pb(pii(b, t));
		adjLists[b].pb(pii(a, t));
	}
	vector<int> centerPointDistances;
	int maxDist = 0;
	for (int i = 0; i < n; i++) {
		if (visited.count(i) == 0) {
			pii maxDistNode = pii(-1, -1);
			dist[i] = 0;
			dfs(i);
			if (visited1.size() == 1) {
				centerPointDistances.pb(0);
				visited1.clear();
				continue;
			}
			for (int j : visited1) {
				if (dist[j] > maxDistNode.second) {
					maxDistNode = pii(j, dist[j]);
				}
			}
			visited1.clear();
			int diameterNode1 = maxDistNode.first;
			maxDistNode = pii(-1, -1);
			dist[diameterNode1] = 0;
			dfs(diameterNode1);
			for (int j : visited1) {
				if (dist[j] > maxDistNode.second) {
					maxDistNode = pii(j, dist[j]);
				}
			}
			visited1.clear();
			int treeDiameter = maxDistNode.second;
			maxDist = max(maxDist, treeDiameter);
			int diameterNode2 = maxDistNode.first;
			int currNode = diameterNode2;
			int centerPointDistance = 1e9;
			while (currNode != diameterNode1) {
				centerPointDistance = min(centerPointDistance, max(dist[currNode], treeDiameter - dist[currNode]));
				currNode = par[currNode];
			}
			centerPointDistance = min(centerPointDistance, max(dist[currNode], treeDiameter - dist[currNode]));
			centerPointDistances.pb(centerPointDistance);
		}
	}
	sort(centerPointDistances.begin(), centerPointDistances.end(), cmp);
	if (centerPointDistances.size() == 1) {
		cout << maxDist << nl;
	} else if (centerPointDistances.size() == 2) {
		cout << max(maxDist, centerPointDistances[0] + centerPointDistances[1] + l) << nl;
	} else {
		cout << max(maxDist, max(centerPointDistances[0] + centerPointDistances[1] + l, centerPointDistances[1] + centerPointDistances[2] + 2 * l)) << nl;
	}
}
