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
int r, c, x, y;

vector<pii> adj[2000][2000];
bool vis[2000][2000];
pii dist[2000][2000];
bool blocked[2000][2000];

class cmp {
	public:
		bool operator()(const pii &a, const pii &b) {
			return dist[a.pA][a.pB].pA + dist[a.pA][a.pB].pB > dist[b.pA][b.pB].pA + dist[b.pA][b.pB].pB;
		}
};

void bfs(pii root) {
	priority_queue<pii, vector<pii>, cmp> bfsQueue;
	vis[root.pA][root.pB] = true;
	bfsQueue.push(root);
	dist[root.pA][root.pB] = {0, 0};
	while (!bfsQueue.empty()) {
		pii node = bfsQueue.top();
		bfsQueue.pop();
		for (pii neighbor : adj[node.pA][node.pB]) {
			if (!vis[neighbor.pA][neighbor.pB]) {
				if (neighbor.pB < node.pB) {
					if (dist[node.pA][node.pB].pA + 1 <= x) {
						dist[neighbor.pA][neighbor.pB] = {dist[node.pA][node.pB].pA + 1, dist[node.pA][node.pB].pB};
						bfsQueue.push(neighbor);
						vis[neighbor.pA][neighbor.pB] = true;
					}
				} else if (neighbor.pB > node.pB) {
					if (dist[node.pA][node.pB].pB + 1 <= y) {
						dist[neighbor.pA][neighbor.pB] = {dist[node.pA][node.pB].pA, dist[node.pA][node.pB].pB + 1};
						bfsQueue.push(neighbor);
						vis[neighbor.pA][neighbor.pB] = true;
					}
				} else {
					dist[neighbor.pA][neighbor.pB] = dist[node.pA][node.pB];
					bfsQueue.push(neighbor);
					vis[neighbor.pA][neighbor.pB] = true;
				}
			}
		}
	}
}

void gridAdj() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!blocked[i][j]) {
				if (i > 0 && !blocked[i - 1][j]) {
					adj[i][j].pb(pii(i - 1, j));
				}
				if (i < n - 1 && !blocked[i + 1][j]) {
					adj[i][j].pb(pii(i + 1, j));
				}
				if (j > 0 && !blocked[i][j - 1]) {
					adj[i][j].pb(pii(i, j - 1));
				}
				if (j < m - 1 && !blocked[i][j + 1]) {
					adj[i][j].pb(pii(i, j + 1));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> r >> c;
	r--;
	c--;
	cin >> x >> y;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		FOR(j, 0, m) {
			if (s[j] == '*') {
				blocked[i][j] = true;
			}
		}
	}
	gridAdj();
	memset(dist, -1, sizeof(dist));
	bfs({r, c});
	int visited = 0;
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			if (vis[i][j]) {
				visited++;
			}
		}
	}
	cout << visited << nl;
}
