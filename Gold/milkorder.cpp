/*
ID:azh248
LANG:C++
TASK:milkorder 
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

int n, m;

vector<pii> adj[100000];
int topo[100000];
int curr;
bool topovis[100000];
priority_queue<int, vector<int>, greater<int>> currNodes;
vector<pii> pars[100000];

void toposort(int maxOrder) {
	curr = 0;
	for (int i = 0; i < n; i++) {
		if (pars[i].size() == 0 || pars[i][0].pB > maxOrder) {
			currNodes.push(i);
		}
	}
	while (!currNodes.empty()) {
		int node = currNodes.top();
		currNodes.pop();
		topovis[node] = true;
		topo[curr++] = node;
		for (pii next : adj[node]) {
			if (next.pB > maxOrder) {
				continue;
			}
			if (!topovis[next.pA]) {
				bool works = true;
				for (pii par : pars[next.pA]) {
					if (par.pB > maxOrder) {
						break;
					}
					if (!topovis[par.pA]) {
						works = false;
						break;
					}
				}
				if (!works) {
					continue;
				}
				currNodes.push(next.pA);
				// topovis[next.pA] = true;
			}
		}
	}
}

bool cycleVis[100000];
bool onStack[100000];

bool topodfsCycle(int node, int maxOrder) { // returns whether there's a cycle
	cycleVis[node] = onStack[node] = true;
	for (pii next : adj[node]) {
		if (next.pB > maxOrder) {
			continue;
		}
		if (onStack[next.pA]) {
			return true;
		} else if (!cycleVis[next.pA]) {
			if (topodfsCycle(next.pA, maxOrder)) {
				return true;
			}
		}
	}
	onStack[node] = false;
	return false;
}

bool toposortCycle(int maxOrder) {
	for (int i = 0; i < n; i++) {
		if (!cycleVis[i]) {
			if (topodfsCycle(i, maxOrder)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	freopen("milkorder.in", "r", stdin);
	freopen("milkorder.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int cows;
		cin >> cows;
		int prev;
		cin >> prev;
		prev--;
		for (int j = 1; j < cows; j++) {
			int curr;
			cin >> curr;
			curr--;
			adj[prev].pb(pii(curr, i));
			pars[curr].pb(pii(prev, i));
			prev = curr;
		}
	}
	int l = 0;
	int r = m - 1;
	int ans = l - 1;
	while (l <= r) {
		int mid = (r + l) / 2;
		for (int i = 0; i < n; i++) {
			onStack[i] = false;
			cycleVis[i] = false;
		}
		if (!toposortCycle(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	toposort(ans);
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			cout << topo[i] + 1;
			continue;
		}
		cout << topo[i] + 1 << " ";
	}
	cout << nl;
}
