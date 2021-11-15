/*
ID:azh248
LANG:C++
TASK:pushabox 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

int n, m, q;
pii bessie, box;
bool dp[1500][1500][4]; // dp[i][j][k] = if the box can reach (i, j) such that bessie is on side k of the box (0 for top side, 1 for right side, etc.)
bool vis[1500][1500][4];
bool blocked[1500][1500];
vector<pii> adjLists[1500][1500];
bool visited[1500][1500][4];
int timer = 0, num[1500][1500], low[1500][1500];
int biconnectedComponents = 0;
int biconnectedComponent[1500][1500][4];
stack<pair<pii, pii>> visitedEdges;

void findBiconnectedComponents(int i, int j, int side, pii par = pii(-1, -1)) {
	visited[i][j][side] = true;
	num[i][j] = low[i][j] = timer++;
	int children = 0;
	for (int k = 0; k < adjLists[i][j].size(); k++) {
		pii neighbor = adjLists[i][j][k];
		int neighborSide;
		if (i - neighbor.first == -1) {
			neighborSide = 0;
		} else if (i - neighbor.first == 1) {
			neighborSide = 2;
		} else if (j - neighbor.second == 1) {
			neighborSide = 1;
		} else {
			neighborSide = 3;
		}
		if (neighbor == par) {
			continue;
		} else if (visited[neighbor.first][neighbor.second][neighborSide]) {
			low[i][j] = min(low[i][j], num[neighbor.first][neighbor.second]);
		} else {
			visitedEdges.push(make_pair(pii(i, j), neighbor));
			findBiconnectedComponents(neighbor.first, neighbor.second, neighborSide, {i, j});
			low[i][j] = min(low[i][j], low[neighbor.first][neighbor.second]);
			if ((low[neighbor.first][neighbor.second] >= num[i][j] && par != make_pair(-1, -1)) || (par == make_pair(-1, -1) && children > 1)) {
				while (visitedEdges.top() != make_pair(make_pair(i, j), neighbor)) {
					pii a = visitedEdges.top().first;
					pii b = visitedEdges.top().second;
					int side;
					if (a.first - b.first == -1) { // if bessie is above the box; i.e. if she is pulling the box upwards
						side = 0;
					} else if (a.first - b.first == 1) { // if bessie is below the box; i.e. if she is pulling the box downwards
						side = 2;
					} else if (a.second - b.second == 1) { // if bessie is to the right of the box; i.e. if she is pulling the box to the right
						side = 1;
					} else { // if bessie is to the left of the box; i.e. if she is pulling the box to the left
						side = 3;
					}
					biconnectedComponent[b.first][b.second][side] = biconnectedComponents;
					biconnectedComponent[a.first][a.second][(side + 2) % 4] = biconnectedComponents;
					visitedEdges.pop();
				}
				pii a = visitedEdges.top().first;
				pii b = visitedEdges.top().second;
				int side;
				if (a.first - b.first ==
					-1) { // if bessie is above the box; i.e. if she is pulling
						  // the box upwards
					side = 0;
				} else if (a.first - b.first ==
						   1) { // if bessie is below the box; i.e. if she is
								// pulling the box downwards
					side = 2;
				} else if (a.second - b.second ==
						   1) { // if bessie is to the right of the box; i.e. if
								// she is pulling the box to the right
					side = 1;
				} else { // if bessie is to the left of the box; i.e. if she is
						 // pulling the box to the left
					side = 3;
				}
				biconnectedComponent[b.first][b.second][side] = biconnectedComponents;
				biconnectedComponent[a.first][a.second][(side + 2) % 4] = biconnectedComponents;
				visitedEdges.pop();
				biconnectedComponents++;
			}
			children++;
		}
	}
}

bool canReach(int i, int j, int side) {
	if (i < 0 || i >= n || j < 0 || j >= m || blocked[i][j]) {
		return false;
	} else if (vis[i][j][side]) {
		return dp[i][j][side];
	} else if (pii(i, j) == box &&
			   (biconnectedComponent[i][j][side] ==
					biconnectedComponent[box.first][box.second][0] || 
					biconnectedComponent[i][j][side] ==
					biconnectedComponent[box.first][box.second][1] ||
				biconnectedComponent[i][j][side] ==
					biconnectedComponent[box.first][box.second][2] ||
				biconnectedComponent[i][j][side] ==
					biconnectedComponent[box.first][box.second][3])) {
		return true;
	}
	vis[i][j][side] = true;
	bool reachable = false; 
	for (int k = 0; k < 4; k++) {
		// check if bessie can maneuver to side k, if so then we try pulling the box from that side
		// to do this, we find the biconnected component containing the edge from bessie to the box, 
		// and find the other edges next to the box that are in the same biconnected component
		// we have to pull instead of push because we're starting at the end and trying to get to the start position
		if (biconnectedComponent[i][j][side] == biconnectedComponent[i][j][k]) { 
			int bessieI = i;
			int bessieJ = j;
			if (k == 0) {
				bessieI--;
			} else if (k == 1) {
				bessieJ++;
			} else if (k == 2) {
				bessieI++;
			} else {
				bessieJ--;
			}
			reachable = (reachable || canReach(bessieI, bessieJ, k));
		}
	}
	dp[i][j][side] = reachable;
	return reachable;
}

int main() {
	freopen("pushabox.in", "r", stdin);
	freopen("pushabox.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '#') {
				blocked[i][j] = true;
			} else if (s[j] != '.') {
				if (s[j] == 'A') {
					bessie = pii(i, j);
				} else {
					box = pii(i, j);
				}
			} 
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!blocked[i][j]) {
				if (i > 0 && !blocked[i - 1][j]) {
					adjLists[i][j].pb(pii(i - 1, j));
				} if (i < n - 1 && !blocked[i + 1][j]) {
					adjLists[i][j].pb(pii(i + 1, j));
				} if (j > 0 && !blocked[i][j - 1]) {
					adjLists[i][j].pb(pii(i, j - 1));
				} if (j < m - 1 && !blocked[i][j + 1]) {
					adjLists[i][j].pb(pii(i, j + 1));
				}
			} 
		}
	}
	memset(biconnectedComponent, -1, sizeof(biconnectedComponent));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
			if (!visited[i][j][k] && !blocked[i][j]) {
				int bessieI = i;
				int bessieJ = j;
				if (k == 0) {
					bessieI--;
				} else if (k == 1) {
					bessieJ++;
				} else if (k == 2) {
					bessieI++;
				} else {
					bessieJ--;
				}
				if (blocked[bessieI][bessieJ]) {
					continue;
				}
				findBiconnectedComponents(i, j, k);
				while (!visitedEdges.empty()) {
					pii a = visitedEdges.top().first;
					pii b = visitedEdges.top().second;
					int side;
					if (a.first - b.first ==
						-1) { // if bessie is above the box; i.e. if she is
							  // pulling the box upwards
						side = 0;
					} else if (a.first - b.first ==
							   1) { // if bessie is below the box; i.e. if she
									// is pulling the box downwards
						side = 2;
					} else if (a.second - b.second ==
							   1) { // if bessie is to the right of the box;
									// i.e. if she is pulling the box to the
									// right
						side = 1;
					} else { // if bessie is to the left of the box; i.e. if she
							 // is pulling the box to the left
						side = 3;
					}
					biconnectedComponent[b.first][b.second][side] = biconnectedComponents;
					biconnectedComponent[a.first][a.second][(side + 2) % 4] = biconnectedComponents;
					visitedEdges.pop();
					if (visitedEdges.empty()) {
						biconnectedComponents++;
					}
				}
			}
			}
		}
	}
	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b; a--; b--;
		cout << (((pii(a, b) == box) || canReach(a, b, 0) || canReach(a, b, 1) || canReach(a, b, 2) || canReach(a, b, 3)) ? "YES" : "NO") << nl;
	}
}
