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

unordered_set<int> adj[100000];
int topo[100000];
int curr;
priority_queue<int> currNodes;
unordered_set<int> pars[100000];

void toposort() {
	curr = n;
	FOR(i, 0, n) {
		if (adj[i].size() == 0) {
			currNodes.push(i);
		}
	}
	while (!currNodes.empty()) {
		int node = currNodes.top();
		currNodes.pop();
		topo[node] = --curr;
		for (int par : pars[node]) {
			adj[par].erase(node);
			if (adj[par].size() == 0) {
				currNodes.push(par);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].insert(b);
		pars[b].insert(a);
	}
	toposort();
	for (int i = 0; i < n; i++) {
		cout << topo[i] + 1 << " ";
	}
	cout << nl;
}
