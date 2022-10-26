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

vector<int> adj[100000];
int dist[100000];
vector<pii> ans;
vector<string> names;

bool cmp(pii a, pii b) {
	if (a.pA == b.pA) {
		return names[a.pB] < names[b.pB];
	}
	return a.pA > b.pA;
}

void dfs(int node) {
	for (int child : adj[node]) {
		dist[child] = max(dist[child], dist[node] + 1);
		dfs(child);
	}
	ans.pb({dist[node], node});
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		FOR(i, 0, 100) {
			adj[i].clear();
		}
		int m, x; cin >> m >> x;
		map<string, int> nameToId;
		int curr = 0;
		names.clear();
		FOR(i, 0, m) {
			string a, b; cin >> a >> b;
			int a1, b1;
			if (nameToId.find(a) == nameToId.end()) {
				nameToId[a] = curr++;
				a1 = nameToId[a];
				names.pb(a);
			} else {
				a1 = nameToId[a];
			}
			if (nameToId.find(b) == nameToId.end()) {
				nameToId[b] = curr++;
				b1 = nameToId[b];
				names.pb(b);
			} else {
				b1 = nameToId[b];
			}
			adj[a1].pb(b1);
		}
		FOR(i, 0, x) {
			FOR(j, 0, 100) {
				dist[j] = 0;
			}
			ans.clear();
			string a; cin >> a;
			dfs(nameToId[a]);
			sort(ans.begin(), ans.end(), cmp);
			unordered_set<int> visited;
			for (pii p : ans) {
				if (visited.count(p.second) > 0) {
					continue;
				}
				visited.insert(p.second);
				cout << "restart " << names[p.second] << nl;
			}
			cout << "exit" << nl;
		}
	}	
}
