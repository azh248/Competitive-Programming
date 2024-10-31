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

int t;

ll dp[300005][2]; // needs to be reset every round
ll a[300005]; // don't touch
vector<int> adj[300005]; // don't touch
unordered_set<int> visited; // doesn't matter
int par[300005]; // don't touch

ll treeDfs(int node, int prevNode) {
	visited.insert(node);
    ll sum = a[node];
	for (int i = 0; i < adj[node].size(); i++) {
		if (adj[node][i] != prevNode) {
			int child = adj[node][i];
			if (visited.count(child) > 0) {
				continue;
			}
			par[child] = node;
			sum += treeDfs(child, node);
		}
	}
    return sum;   
}

bool killNode[300005][2];
bool dead[300005];

ll treeDP(int node, bool prevKilled) {
    int prevKilledInt = prevKilled ? 1 : 0;
    if (dp[node][prevKilledInt] != -1) {
        return dp[node][prevKilledInt];
    }
    if (dead[node]) {
        ll sum = 0;
        for (int i = 0; i < adj[node].size(); i++) {
            int child = adj[node][i];
            if (child == par[node]) {
                continue;
            }
            sum += treeDP(child, 0);
        }
        killNode[node][prevKilledInt] = true;
        return dp[node][prevKilledInt] = sum;
    }
    ll sum0 = a[node];
    for (int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i];
        if (child == par[node]) {
            continue;
        }
        sum0 += treeDP(child, 0);
    }
    ll sum1 = 0;
    if (!prevKilled) {
        for (int i = 0; i < adj[node].size(); i++) {
            int child = adj[node][i];
            if (child == par[node]) {
                continue;
            }
            sum1 += treeDP(child, 1);
        }
    } else {
        sum1 = 1e18;
    }
    if (sum0 < sum1) {
        killNode[node][prevKilledInt] = false;
    } else {
        killNode[node][prevKilledInt] = true;
    }
    return dp[node][prevKilledInt] = min(sum0, sum1);
}

void killNodes(int node, int prevKilled) {
    int prevKilledInt = prevKilled ? 1 : 0;
    bool killedThisNode = false;
    if (!prevKilled && killNode[node][prevKilledInt] && !dead[node]) {
        dead[node] = true;
        killedThisNode = true;
    }
    for (int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i];
        if (child == par[node]) {
            continue;
        }
        killNodes(child, killedThisNode);
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
        int n; cin >> n;
        FOR(i, 0, n) {
            cin >> a[i];
        }
        F0R(i, n) {
            adj[i].clear();
            visited.clear();
            par[i] = -1;
            dead[i] = false;
        }
        F0R(i, n - 1) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        ll sum = treeDfs(0, -1);
        while (true) {
            F0R(i, n) {
                dp[i][0] = -1;
                dp[i][1] = -1;
                killNode[i][0] = false;
                killNode[i][1] = false;
            }
            ll ans = treeDP(0, 0);
            if (ans == 0) {
                break;
            }
            sum += ans;
            // backtrack to find the nodes to kill
            killNodes(0, 0);
            // FOR(i, 0, n) {
            //     cout << "NODE " << i << " dead: " << dead[i] << "; ";
            //     cout << "killNode[0]: " << killNode[i][0] << "; ";
            //     cout << "killNode[1]: " << killNode[i][1] << nl;
            // }
            // cout << nl;
        }
        cout << sum << nl;
	}	
}
