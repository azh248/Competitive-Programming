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

int n, t;

vector<int> adj[1000005];
int par[1000005];
ll rate[1000005];
int depth[1000005];
int sz[1000005];
ll totalRate[1000005];
bool maxDepthRouteCandidate[1000005]{};
// vector<int> adj[10];
// int par[10];
// int rate[10];
// int depth[10];
// int sz[10];
// int totalRate[10];
// int maxDepthRouteCandidate[10]{};
int maxDepth = 0;

void bfs(int root) {
	queue<int> bfsQueue;
	bfsQueue.push(root);
    sz[root] = n;
    vector<int> maxDepthNodes;
	while (!bfsQueue.empty()) {
		int node = bfsQueue.front();
		bfsQueue.pop();
		for (int neighbor : adj[node]) {
			bfsQueue.push(neighbor);
            if (depth[neighbor] == maxDepth) {
                maxDepthNodes.pb(neighbor);
            }
		}
	}

    for (int maxDepthNode : maxDepthNodes) {
        while (maxDepthNode != root) {
            if (maxDepthRouteCandidate[maxDepthNode] == 0) {
                maxDepthRouteCandidate[maxDepthNode] = 1;
                maxDepthNode = par[maxDepthNode];
            } else {
                break;
            }
        }
    }
}

void totalFertilizerPerSec(int i) {
    totalRate[i] = rate[i];
    sz[i] = 1;
    for (int j : adj[i]) {
        depth[j] = depth[i] + 1;
        if (depth[j] > maxDepth) {
            maxDepth = depth[j];
        }
        totalFertilizerPerSec(j);
        sz[i] += sz[j];
        totalRate[i] += totalRate[j];
    }
}

int minFertilizer(int i, bool onMaxDepthRoute) {
    if (adj[i].size() == 0) {
        return 0;
    }
    int fertilizer = 0;

    vector<pair<double, int>> children;

    int maxDepthMaxRateChild = -1;
    double maxDepthMaxRate = 1e18;

    for (int j : adj[i]) {
        double efficiencyFactor = (double)(2 * (sz[j] - 1) + 1) * ((double)totalRate[j]); // 1 extra time for the root of the subtree
        if (maxDepthRouteCandidate[j]) {
            if (efficiencyFactor < maxDepthMaxRate) {
                maxDepthMaxRate = efficiencyFactor;
                maxDepthMaxRateChild = j;
            }
        }
        children.pb({efficiencyFactor, j}); // 1 extra time for the root of the subtree
    }

    sort(children.begin(), children.end());

    int time = 0;

    for (int j = 0; j < children.size(); j++) {
        if (onMaxDepthRoute && children[j].pB == maxDepthMaxRateChild) {
            continue;
        }
        time++;
        int child = children[j].pB;
        fertilizer += time * totalRate[child]; // account for all the time we spent visiting the other subtrees + travel time (1 second)
        fertilizer += minFertilizer(child, false);
        time += 2 * (sz[child] - 1) + 1; // add the time we spent in the subtree + travel time back (1 second)
    }

    if (onMaxDepthRoute) {
        time++;
        fertilizer += time * totalRate[maxDepthMaxRateChild];
        fertilizer += minFertilizer(maxDepthMaxRateChild, true);
    }

    return fertilizer;
}

int main() {
    // freopen("!.in", "r", stdin); // GET RID OF THIS
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t;
	for (int i = 2; i <= n; i++) {
		int p, a; cin >> p >> a; p--;
        adj[p].pb(i - 1);
        par[i - 1] = p;
        rate[i - 1] = a;
	}
    depth[0] = 0;
    maxDepthRouteCandidate[0] = 1;
    totalFertilizerPerSec(0);
    bfs(0);
    if (t == 0){
        cout << (n - 1) * 2 << " ";
    } else {
        cout << (n - 1) * 2 - maxDepth << " ";
    }

    if (t == 0) {
        cout << minFertilizer(0, false) << nl;
    } else {
        cout << minFertilizer(0, true) << nl;
    }
}
