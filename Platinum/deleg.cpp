/*
ID:azh248
LANG:C++
TASK:deleg 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

int n, k;
vector<int> adjLists[100000];
int par[100000];
unordered_set<int> visited;

void dfs(int node) {
	visited.insert(node);
	for (int i = 0; i < adjLists[node].size(); i++) {
		int child = adjLists[node][i];
		if (visited.count(child) > 0) {
			continue;
		}
		par[child] = node;
		dfs(child);
	}
}

int dp[100000]; // dp[i] = the remaining path length from all subtrees of i (1e9 if the subtrees can't be divided into path lengths of at least k)
bool works;

int remaining(int node) {
	if (dp[node] != -1) {
		return dp[node];
	} else if (adjLists[node].size() == 1 && node != 0) {
		return 0;
	}
	// after going through subtrees and figuring out the remaining path length, we can either start a new path if the remaining is >= k, or we can 
	// continue with the current path.  
	vector<int> remainders;
	for (int i : adjLists[node]) {
		if (i != par[node]) {
			remainders.pb(remaining(i) + 1);
			if (remaining(i) >= 1e9) {
				dp[node] = 1e9;
				return 1e9;
			}
		}
	}
	if (remainders.size() % 2 == 0) { // we need to add 0 to make the bsearch work; i.e. a possibility is that the remainder we end up using is just 0 because each 
									  // remainder pairs up perfectly
		remainders.pb(0);
	}
	sort(remainders.begin(), remainders.end());
	int l = 0;
	int r = remainders.size() - 1;
	int ans = l - 1;
	while (l <= r) {
		ll mid = (r + l) / 2;
		bool pairUpWorks = true;
		int pointer1 = 0;
		int pointer2 = remainders.size() - 1;
		while (pointer1 < pointer2) {
			if (pointer1 == mid) {
				pointer1++;
			} else if (pointer2 == mid) {
				pointer2--;
			}
			if (remainders[pointer1] + remainders[pointer2] < k) {
				pairUpWorks = false;
				break;
			}
			pointer1++;
			pointer2--;
		}
		if (pairUpWorks) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	if (ans == -1) {
		dp[node] = 1e9;
		return 1e9;
	} else {
		if (node == 0) {
			works = true;
		}
		dp[node] = remainders[ans];
		return remainders[ans];
	}
}

int main() {
	freopen("deleg.in", "r", stdin);
	freopen("deleg.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adjLists[a].pb(b);
		adjLists[b].pb(a);
	}
	dfs(0);
	int l = 0;
	int r = n;
	int ans = l - 1;
	while (l <= r) {
		int mid = (r + l) / 2;
		k = mid;
		memset(dp, -1, sizeof(dp));
		works = false;
		remaining(0);
		if (works) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << nl;
}
