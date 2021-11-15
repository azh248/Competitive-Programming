/*
ID:azh248
LANG:C++
TASK:promote 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;

int BIT[100001]{}; // 1-indexed
pii proficiencies[100001];
int sortedIndex[100001];
vector<int> adj[100001];
int par[100001];

// update prefix sums at a specified index and add a value
void update(int ind, int val) {
	ind++; // makes it 1-indexed
	while (ind <= n) {
		BIT[ind] += val;
		ind += (ind & -ind); // makes it so that ind is now the next node responsible for our updated one
	}
}

int get(int ind) {
	ind++; // makes it 1-indexed
	int ret = 0;
	while (ind > 0) {
		ret += BIT[ind];
		ind -= (ind & -ind); // repeatedly remove last "1" bit; all of these nodes make up our query 
	}
	return ret;
}

int inversions[100001];

void dfs(int node) { // we note down the inversions before we visit the subtree and after, so that when we subtract them from each other we get the # of inversions in the subtree
	int inversionsOutsideSubtree = get(sortedIndex[node]);
	for (int i : adj[node]) {
		dfs(i);
	}
	int inversionsWithSubtree = get(sortedIndex[node]);
	update(sortedIndex[node], 1);
	inversions[node] = inversionsWithSubtree - inversionsOutsideSubtree;
}

int main() {
	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> proficiencies[i].first;
		proficiencies[i].second = i;
	}
	par[0] = -1;
	for (int i = 1; i < n; i++) {
		cin >> par[i];
		par[i]--;
		adj[par[i]].pb(i);
	}
	sort(proficiencies, proficiencies + n);
	reverse(proficiencies, proficiencies + n);
	for (int i = 0; i < n; i++) {
		sortedIndex[proficiencies[i].second] = i;
	}
	dfs(0);
	for (int i = 0; i < n; i++) {
		cout << inversions[i] << nl;
	}
}