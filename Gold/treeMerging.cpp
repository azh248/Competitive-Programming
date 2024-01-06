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
int n, m;
vector<int> adj[100005];
int par[100005];
vector<int> mergedAdj[100005];
int mergedPar[100005];
int depth[100005];
int maxDepth = 0;
// nodeDepths[i] is the set of all nodes at depth i from the root
unordered_set<int> nodeDepths[100005];
// mergedNodeDepths[i] is the set of all nodes at depth i from the root in the merged tree
unordered_set<int> mergedNodeDepths[100005];

// maxNode[i] is the node with the maximum value at depth i
int maxNode[100005];

int maxChild[100005];

void dfsDepths(int node, int currDepth) {
    nodeDepths[currDepth].insert(node);
    depth[node] = currDepth;
    maxNode[currDepth] = max(maxNode[currDepth], node);
    for (int child : adj[node]) {
        dfsDepths(child, currDepth + 1);
    }
}

void dfsMergedDepths(int node, int currDepth) {
    mergedNodeDepths[currDepth].insert(node);
    for (int child : mergedAdj[node]) {
        dfsMergedDepths(child, currDepth + 1);
        maxChild[node] = max(maxChild[node], child);
    }
    maxDepth = max(maxDepth, currDepth);
}

int findMergedChild(int node) {
    // if it's in the merged tree
    if (mergedNodeDepths[depth[node]].find(node) != mergedNodeDepths[depth[node]].end()) {
        return node;
    }
    for (int child : adj[node]) {
        int mergedChild = findMergedChild(child);
        if (mergedChild != -1) {
            return mergedChild;
        }
    }
    return -1;
}

// find the max child at each depth
void findMaxChildrenMerged(int node, vector<int> &maxChildren) {
    // cout << "hello" << nl;
    for (int child : mergedAdj[node]) {
        // cout << "hello1"<< nl;
        maxChildren[depth[child] - depth[node]] = max(maxChildren[depth[child] - depth[node]], child);
        findMaxChildrenMerged(child, maxChildren);
    }
}

void findMaxChildren(int node, vector<int> &maxChildren) {
    // cout << "hello2" << nl;
    for (int child : adj[node]) {
        // cout << "hello3" << nl;
        maxChildren[depth[child] - depth[node]] = max(maxChildren[depth[child] - depth[node]], child);
        findMaxChildren(child, maxChildren);
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            par[i] = -1;
            mergedAdj[i].clear();
            mergedPar[i] = -1;
            maxNode[i] = -1;
            maxChild[i] = -1;
            nodeDepths[i].clear();
            mergedNodeDepths[i].clear();
            depth[i] = -1;
            maxDepth = 0;
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b;
            a--; b--;
            adj[b].pb(a);
            par[a] = b;
        }
        cin >> m;
        for (int i = 0; i < m - 1; i++) {
            int a, b; cin >> a >> b;
            a--; b--;
            mergedAdj[b].pb(a);
            mergedPar[a] = b;
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (par[i] == -1) {
                root = i;
                break;
            }
        }
        cout << n - m << nl;
        dfsDepths(root, 0);
        dfsMergedDepths(root, 0);
        // cout << "STARTING OUTPUT" << nl;
        // cout << "n = " << n << nl;
        // for (int i = 0; i < n; i++) {
        //     cout << maxChild[i] << " ";
        // }
        // cout << nl << nl;
        for (int i = 0; i < n; i++) {
            // i is the depth
            if (nodeDepths[i].size() == 0) {
                break;
            }
            for (int node : nodeDepths[i]) {
                // need to merge this node -- but where?
                if (mergedNodeDepths[i].find(node) == mergedNodeDepths[i].end()) {


                    int mergedChild = findMergedChild(node);
                    // cout << "node = " << node << " merged child: " << mergedChild << nl;

                    // merge arbitrarily
                    if (adj[node].size() == 0) {
                        int mergedIntoNode = maxChild[par[node]];
                        // cout << "node: " << node << " merged into: " << mergedIntoNode << " with merged par: " << mergedPar[node] << nl;
                        assert(node != mergedIntoNode);
                        cout << node + 1 << " " << mergedIntoNode + 1 << nl;
                        for (int child : adj[node]) {
                            adj[mergedIntoNode].pb(child);
                            par[child] = mergedIntoNode;
                        }
                    }
                    // must merge into a node such that all of its children can be merged
                    // to do this, make the only node on each depth the max node on that depth so its subtree is a line, and then figure out 
                    // where the line can be merged by trying all siblings on the merged tree
                    else if (mergedChild == -1) {
                        int mergedIntoNode = -1;
                        for (int sibling : mergedAdj[par[node]]) {
                            // can optimize by bfs, then check immediately after each depth if it works
                            vector<int> maxChildren2(maxDepth + 5, -1);
                            findMaxChildren(node, maxChildren2);
                            // find an older sibling that is in the merged tree
                            if (sibling > node) {
                                vector<int> maxChildren(maxDepth + 5, -1);
                                findMaxChildrenMerged(sibling, maxChildren);
                                bool works = true;
                                // cout << maxChildren2[1] << " " << maxChildren[1] << nl;
                                for (int j = 1; j <= maxDepth; j++) {
                                    if (maxChildren2[j] != -1) {
                                        if (maxChildren[j] == -1) {
                                            works = false;
                                            break;
                                        } else {
                                            if (maxChildren[j] < maxChildren2[j]) {
                                                works = false;
                                                break;
                                            }
                                        }
                                    } else {
                                        break;
                                    }
                                }
                                if (works) {
                                    mergedIntoNode = sibling;
                                    break;
                                }
                            }
                        }
                        // cout << "node: " << node << " merged into: " << mergedIntoNode << " with par: " << par[node] << nl;
                        assert(node != mergedIntoNode);
                        assert(mergedIntoNode != -1);
                        cout << node + 1 << " " << mergedIntoNode + 1 << nl;
                        for (int child : adj[node]) {
                            adj[mergedIntoNode].pb(child);
                            par[child] = mergedIntoNode;
                        }
                    } 
                    
                    else {
                        int depthDiff = depth[mergedChild] - depth[node];
                        for (int j = 0; j < depthDiff; j++) {
                            mergedChild = mergedPar[mergedChild];
                        }
                        assert(mergedChild != node);
                        cout << node + 1 << " " << mergedChild + 1 << nl;
                        for (int child : adj[node]) {
                            adj[mergedChild].pb(child);
                            par[child] = mergedChild;
                        }
                    }
                }
            }
        }
	}	
}
