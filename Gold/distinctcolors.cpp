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

int n;

vector<int> adj[200001];
int treeArr[200001];
int subtree[200001];
int par[200001];
int color[200001];
int ind;

void dfs(int node) {
	if (node == 0) {
		par[node] = -1;
		ind = n;
	}
	subtree[node] = 1;
	ind--;
	treeArr[ind] = node;
	for (int child : adj[node]) {
		if (child != par[node]) {
			par[child] = node;
			dfs(child);
			subtree[node] += subtree[child];
		}
	}
}

int BIT[200001]; // 1-indexed

void update(int ind, int val) {
	ind++;
	while (ind <= n) {
		BIT[ind] += val;
		ind += (ind & -ind);
	}
}

int get(int ind) {
	ind++;
	int ret = 0;
	while (ind > 0) {
		ret += BIT[ind];
		ind -= (ind & -ind);
	}
	return ret;
}

map<int, int> lastOccurrence;
int arr[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR(i, 0, n) { 
		cin >> color[i];
		color[i]--;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0);
	FOR(i, 0, n) {
		if (lastOccurrence.count(color[treeArr[i]]) != 0) {
			update(lastOccurrence[color[treeArr[i]]], -1);
		}
		update(i, 1);
		lastOccurrence[color[treeArr[i]]] = i;
		arr[treeArr[i]] = get(i) - get(i - subtree[treeArr[i]]);
	}
	FOR(i, 0, n) {
		cout << arr[i] << " ";
	}
	cout << nl;
}
