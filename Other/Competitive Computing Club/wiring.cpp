#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using psi = pair<string, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back
#define long long long

int n, m, k1, a, b;

int dist[110][110];
vector<vector<int> > edges;
string colorNums[110][110]{};

void floydWarshall() { // O(nodes^3)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = 1e9; // initialize every distance to greatest value
		}
	}
	for (vector<int> i : edges) { // initializing
		int x = i[0];
		int y = i[1];
		int color = i[2];
		dist[x][y] = 1;
		dist[y][x] = 1;
		colorNums[x][y] = to_string(color);
		colorNums[y][x] = to_string(color);
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					colorNums[i][j] = colorNums[i][k] + colorNums[k][j];
				} else if (dist[i][k] + dist[k][j] == dist[i][j] && colorNums[i][k] + colorNums[k][j] < colorNums[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					colorNums[i][j] = colorNums[i][k] + colorNums[k][j];	
				}
			}
		}
	}
}

bool cmp(psi a, psi b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("wiring.in", "r", stdin);
	freopen("wiring.out", "w", stdout);
    cin >> n >> m >> k1 >> a >> b;
	a--;
	b--;
	vector<psi> colorTypes;	
	for (int i = 0; i < k1; i++) {
		string s;
		cin >> s;
		colorTypes.pb({s, i});
	}
	sort(colorTypes.begin(), colorTypes.end(), cmp);
	for (int i = 0; i < m; i++) {
		int x, y;
		string s;
		cin >> x >> y >> s;
		x--;
		y--;
		int index;
		for (int i = 0; i < k1; i++) {
			if (colorTypes[i].first == s) {
				index = i;
				break;
			}
		}
		edges.pb({x, y, index});
	}	
	floydWarshall();
	string path = colorNums[a][b];
	int colorCounts[6]{};
	for (int i = 0; i < path.length(); i++) {
		int num = stoi(string(1, path[i]));
		colorCounts[colorTypes[num].second]++;
	}
	for (int i = 0; i < k1; i++) {
		cout << colorCounts[i] << nl;
	}
}
