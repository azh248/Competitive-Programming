#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m, k;

vector<vector<int> > adjLists[1000][1000];
bool blocked[1000][1000];

void gridAdjList() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!blocked[i][j]) {
				if (i > 0 && !blocked[i - 1][j]) {
					adjLists[i][j].pb({i - 1, j, 1});
				}
				if (i < n - 1 && !blocked[i + 1][j]) {
					adjLists[i][j].pb({i + 1, j, 1});
				}
				if (j > 0 && !blocked[i][j - 1]) {
					adjLists[i][j].pb({i, j - 1, 1});
				}
				if (j < m - 1 && !blocked[i][j + 1]) {
					adjLists[i][j].pb({i, j + 1, 1});
				}
			}
		}
	}
}

int dist[1000][1000];

class cmp {
	public: 
		bool operator()(vector<int> a, vector<int> b) {
			return a[2] > b[2];
		}
};

void dijkstra() { // traceback
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = 1e9;
		}
	}
	dist[0][0] = 0;
	priority_queue<vector<int>, vector<vector<int> >, cmp> nodes;
	nodes.push({0, 0, 0});
	while (!nodes.empty()) {
		int nodeX = nodes.top()[0];
		int nodeY = nodes.top()[1];
		int minDist = nodes.top()[2];
		nodes.pop();
		if (minDist != dist[nodeX][nodeY]) {
			continue;
		}
		for (vector<int> i : adjLists[nodeX][nodeY]) {
			int neighborX = i[0];
			int neighborY = i[1];
			int length = i[2];
			if (dist[nodeX][nodeY] + length < dist[neighborX][neighborY]) {
				dist[neighborX][neighborY] = dist[nodeX][nodeY] + length;
				nodes.push({neighborX, neighborY, dist[neighborX][neighborY]});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '#') {
				blocked[i][j] = true;
			}
		}
	}
	gridAdjList();
	for (int i = 0; i < k; i++) {
		int a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2; a1--; b1--; a2--; b2--;
		adjLists[a1][b1].clear();
		adjLists[a1][b1].pb({a2, b2, 0});
	}
	dijkstra();
	cout << dist[n - 1][m - 1] << nl;
}