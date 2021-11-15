/*
ID: azh248
LANG: C++
TASK:lasers 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back
#define long long long

int n;
vector<int> adjLists[100010]{}; // should be of size n
unordered_set<int> visited;
int dist[100010]{}; // distance from starting node
pii laser;
pii barn;
vector<pii> fences;

bool cmpFirst(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

bool cmpSecond(vector<int> a, vector<int> b) {
	return a[1] < b[1];
}

int bfs(int root) {
	queue<int> bfsQueue;
	visited.insert(root);
	bfsQueue.push(root);
	dist[root] = -1;
	while (!bfsQueue.empty()) {
		int node = bfsQueue.front();
		bfsQueue.pop();
		for (int i = 0; i < adjLists[node].size(); i++) {
			int neighbor = adjLists[node][i];
			if (neighbor == n + 1) {
				return dist[node] + 1;
			} else if (visited.count(neighbor) == 0) {
				visited.insert(neighbor);
				bfsQueue.push(neighbor);
				dist[neighbor] = dist[node] + 1;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
	cin >> n >> laser.first >> laser.second >> barn.first >> barn.second;
	vector<vector<int> > fencesX;
	vector<vector<int> > fencesY;
	for (int i = 0; i < n; i++) {
		int x;
		int y;
		cin >> x >> y;
		fences.pb({x, y});
		fencesX.pb({x, y, i});
		fencesY.pb({x, y, i});
	}
	fences.pb(laser);
	fences.pb(barn);
	fencesX.pb({laser.first, laser.second, n});
	fencesX.pb({barn.first, barn.second, n + 1});
	fencesY.pb({laser.first, laser.second, n});
	fencesY.pb({barn.first, barn.second, n + 1});
	sort(fencesX.begin(), fencesX.end(), cmpFirst);
	for (int i = 0; i < n + 2; i++) {
		for (int j = i + 1; j < n + 2; j++) {
			if (fencesX[j][0] != fencesX[i][0]) {
				break;
			} 
			adjLists[fencesX[i][2]].pb(fencesX[j][2]);
			adjLists[fencesX[j][2]].pb(fencesX[i][2]);
		}
	}
	sort(fencesY.begin(), fencesY.end(), cmpSecond);
	for (int i = 0; i < n + 2; i++) {
		for (int j = i + 1; j < n + 2; j++) {
			if (fencesY[j][1] != fencesY[i][1]) {
				break;
			}
			adjLists[fencesY[i][2]].pb(fencesY[j][2]);
			adjLists[fencesY[j][2]].pb(fencesY[i][2]);
		}
	}
	cout << bfs(n) << nl;
}
