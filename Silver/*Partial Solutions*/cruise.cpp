/*
ID:azh248
LANG:C++
TASK:cruise 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

ll n, m, k;
int ports[1000][2];
int direcs[500];
unordered_set<int> vis;
int endUp[1000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("cruise.in", "r", stdin);
	freopen("cruise.out", "w", stdout);
	// go through the m directions n times, if at any point you start a new cycle at a place you've started at a cycle before then you know the cycle
	// you can then mod k by the cycle length and find the last node
	// this will always work because you're bound to have at least one repeat starting node in the n iterations of the m directions
	cin >> n >> m >> k;
	n = (ll) n;
	m = (ll) m;
	k = (ll) k;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		ports[i][0] = a;
		ports[i][1] = b;
	}
	for (int i = 0; i < m; i++) {
		char ch; cin >> ch;
		if (ch == 'L') {
			direcs[i] = 0;
		} else {
			direcs[i] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		int node = i;
		for (int j = 0; j < m; j++) {
			node = ports[node][direcs[j]];
		}
		endUp[i] = node;
	}
	if (k <= n) {
		int node = 0;
		for (int i = 0; i < k; i++) {
			node = endUp[node];
		}
		cout << node + 1 << nl;
		return 0;
	}
	int node = 0;
	for (int i = 0; i < n; i++) {
		node = endUp[node];
	}	
	ll size1 = 0;
	while (true) {
		node = endUp[node];
		size1++;
		if (vis.count(node) > 0) {
			break;
		}
		vis.insert(node);
	}
	k -= n;
	k %= size1;
	for (int i = 0; i < k; i++) {
		node = endUp[node];
	}
	cout << node + 1 << nl;
}
