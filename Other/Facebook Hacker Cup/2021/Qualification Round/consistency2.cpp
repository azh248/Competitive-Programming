#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

vector<int> adj[30];
bool vis[30];
int dist[30];

void bfs(int root) {
	for (int i = 0; i < 30; i++) {
		dist[i] = 1e9;
		vis[i] = false;
	}
	queue<int> bfsQueue;
	vis[root] = true;
	bfsQueue.push(root);
	dist[root] = 0;
	while (!bfsQueue.empty()) {
		int node = bfsQueue.front();
		bfsQueue.pop();
		for (int i = 0; i < adj[node].size(); i++) {
			int neighbor = adj[node][i];
			if (!vis[neighbor]) {
				vis[neighbor] = true;
				bfsQueue.push(neighbor);
				dist[neighbor] = dist[node] + 1;
			}
		}
	}
}

int main() {
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		for (int i = 0; i < 30; i++) {
			adj[i].clear();
		}
		string s; cin >> s;
		int k; cin >> k;
		for (int i = 0; i < k; i++) {
			string s1; cin >> s1;
			adj[s1[1] - 'A'].pb(s1[0] - 'A');
		}
		int minSeconds = 1e9;
		for (int i = 0; i < 26; i++) {
			bfs(i);
			bool works = true;
			int totalDist = 0;
			for (int i = 0; i < s.length(); i++) {
				if (dist[s[i] - 'A'] == 1e9) {
					works = false;
					break;
				}
				totalDist += dist[s[i] - 'A'];
			}
			if (!works) {
				continue;
			}
			minSeconds = min(minSeconds, totalDist);
		}
		if (minSeconds == 1e9) {
			minSeconds = -1;
		}
		cout << "Case #" << t1 << ": " << minSeconds << nl;
	}
}