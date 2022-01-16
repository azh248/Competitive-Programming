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

int n;
int dX, dY; // diamond location
int arr[8][8];

int getTurns(int direc, int nextDirec) {
	if (direc == nextDirec) {
		return 0;
	} else if (abs(direc - nextDirec) == 2) {
		return 2;
	} else {
		return 1;
	}
}

class cmp {
  public:
	bool operator()(vector<int> a, vector<int> b) { return a[2] > b[2]; }
};

int dist[8][8][4];
string currStr[8][8][4];

string dijkstra(int rootX, int rootY) { // grid dijkstra
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			FOR(k, 0, 4) { 
				dist[i][j][k] = 1e9;
				currStr[i][j][k] = "";
			}
		}
	}
	dist[rootX][rootY][1] = 0;
	priority_queue<vector<int>, vector<vector<int>>, cmp> nodes;
	nodes.push({rootX, rootY, 0, 1});
	// nodes.push({rootX, rootY, 0, 2});
	while (!nodes.empty()) {
		int nodeX = nodes.top()[0];
		int nodeY = nodes.top()[1];
		int minDist = nodes.top()[2];
		int direc = nodes.top()[3]; // 0 for down, 1 for right, 2 for up, 3 for left
		string nodeStr = currStr[nodeX][nodeY][direc];
		nodes.pop();
		if (minDist != dist[nodeX][nodeY][direc]) {
			continue;
		}
		int neighborX = nodeX;
		int neighborY = nodeY;
		if (direc == 0) {
			neighborX++;
		} else if (direc == 2) {
			neighborX--;
		} else if (direc == 1) {
			neighborY++;
		} else {
			neighborY--;
		}
		if (minDist + 1 < dist[nodeX][nodeY][(direc + 3) % 4]) {
			dist[nodeX][nodeY][(direc + 3) % 4] = minDist + 1;
			nodes.push({nodeX, nodeY, dist[nodeX][nodeY][(direc + 3) % 4], (direc + 3) % 4});
			currStr[nodeX][nodeY][(direc + 3) % 4] = nodeStr + "R";
		}
		if (minDist + 1 < dist[nodeX][nodeY][(direc + 1) % 4]) {
			dist[nodeX][nodeY][(direc + 1) % 4] = minDist + 1;
			nodes.push({nodeX, nodeY, dist[nodeX][nodeY][(direc + 1) % 4], (direc + 1) % 4});
			currStr[nodeX][nodeY][(direc + 1) % 4] = nodeStr + "L";
		}
		if (neighborX >= 0 && neighborX < n && neighborY >= 0 &&
			neighborY < n) {
			if (arr[neighborX][neighborY] == 2) {
				continue;
			} else if (arr[neighborX][neighborY] == 1) { // ice castle
				if (minDist + 2 < dist[neighborX][neighborY][direc]) {
					dist[neighborX][neighborY][direc] = minDist + 2;
					nodes.push({neighborX, neighborY, dist[neighborX][neighborY][direc], direc});
					currStr[neighborX][neighborY][direc] = nodeStr + "XF";
				}
			} else if (arr[neighborX][neighborY] == 0) { // empty
				if (minDist + 1 < dist[neighborX][neighborY][direc]) {
					dist[neighborX][neighborY][direc] = minDist + 1;
					nodes.push({neighborX, neighborY, dist[neighborX][neighborY][direc], direc});
					currStr[neighborX][neighborY][direc] = nodeStr + "F";
				}
			} else { // diamond
				if (minDist + 1 < dist[neighborX][neighborY][direc]) {
					dist[neighborX][neighborY][direc] = minDist + 1;
					nodes.push({neighborX, neighborY, dist[neighborX][neighborY][direc], direc});
					currStr[neighborX][neighborY][direc] = nodeStr + "F";
					return currStr[neighborX][neighborY][direc];
				}
			}
		}
	}
	return "no solution";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	n = 8;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		FOR(j, 0, n) {
			if (s[j] == 'C') {
				arr[i][j] = 2;
			} else if (s[j] == 'D') {
				arr[i][j] = 3;
				dX = i;
				dY = j;
			} else if (s[j] == 'I') {
				arr[i][j] = 1;
			} else {
				arr[i][j] = 0;
			}
		}
	}
	cout << dijkstra(n - 1, 0) << nl;
}
