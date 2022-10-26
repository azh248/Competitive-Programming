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

int n, steps, rootX, rootY, homeX, homeY;

vector<pii> adj[800][800];
bool vis[800][800];
int dist[800][800];
bool visBee[800][800];
int distBee[800][800];
bool blocked[800][800];
bool blocked1[800][800];
vector<pii> hives;

void bfsBees() {
	queue<pii> bfsQueue;
	for (pii root : hives) {
		visBee[root.pA][root.pB] = true;
		bfsQueue.push(root);
		distBee[root.pA][root.pB] = 0;
	}
	while (!bfsQueue.empty()) {
		pii node = bfsQueue.front();
		bfsQueue.pop();
		for (pii neighbor : adj[node.pA][node.pB]) {
			if (!visBee[neighbor.pA][neighbor.pB] && !(neighbor.pA == homeX && neighbor.pB == homeY)) {
				visBee[neighbor.pA][neighbor.pB] = true;
				bfsQueue.push(neighbor);
				distBee[neighbor.pA][neighbor.pB] = distBee[node.pA][node.pB] + 1;
			}
		}
	}
}

bool bfs(int eatHoney) {
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			vis[i][j] = false;
		}
	}
	queue<pii> bfsQueue;
	vis[rootX][rootY] = true;
	bfsQueue.push(pii(rootX, rootY));
	dist[rootX][rootY] = 0;
	if (distBee[rootX][rootY] <= eatHoney) {
		bfsQueue.pop();
	}
	while (!bfsQueue.empty()) {
		pii node = bfsQueue.front();
		bfsQueue.pop();
		for (pii neighbor : adj[node.pA][node.pB]) {
			int dist1 = dist[node.pA][node.pB] + 1;
			if (!vis[neighbor.pA][neighbor.pB] && dist1/steps < distBee[neighbor.pA][neighbor.pB] - eatHoney) {
				vis[neighbor.pA][neighbor.pB] = true;
				if (neighbor.pA == homeX && neighbor.pB == homeY) {
					return true;
				}
				bfsQueue.push(neighbor);
				dist[neighbor.pA][neighbor.pB] = dist1;
			}
		}
	}
	for (pii i : adj[homeX][homeY]) {
		if (vis[i.pA][i.pB] && dist[i.pA][i.pB]/steps < distBee[i.pA][i.pB] - eatHoney) {
			return true;
		}
	}
	return false;
}

void gridAdj() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
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
				if (j < n - 1 && !blocked[i][j + 1]) {
					adj[i][j].pb(pii(i, j + 1));
				}
			}
		}
	}
}

int main() {
	// freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> steps;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		FOR(j, 0, n) {
			if (s[j] == 'T') {
				blocked[i][j] = true;
			} else if (s[j] == 'M') {
				rootX = i;
				rootY = j;
			} else if (s[j] == 'D') {
				homeX = i;
				homeY = j;
			} else if (s[j] == 'H') {
				hives.pb(pii(i, j));
			}
		}
	}
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			vis[i][j] = false;
			visBee[i][j] = false;
			dist[i][j] = 1e9;
			distBee[i][j] = 1e9;
			blocked1[i][j] = false;
		}
	}
	gridAdj();
	bfsBees();
	int l = 0;
	int r = 1e6;
	int ans = l - 1;
	while (l <= r) {
		ll mid = (r + l) / 2;
		if (bfs(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << nl;
}
