/*
ID:azh248
LANG:C++
TASK:skilevel 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

int n, m, t;
int arr[500][500];
vector<int> startingPoints;
vector<vector<int> > edges;
vector<int> p;
vector<int> minWeight;

struct DSU {
	void init(int n) { 
		p = vector<int>(n, -1); 
		minWeight = vector<int>(n, 1e9);
	}
	int get(int x) { 
		if (p[x] < 0) {
			return x;
		} else {
			int num = get(p[x]);
			return num;
		}
	}
	int getMinWeight(int x) {
		while (minWeight[x] == 1e9) {
			x = p[x];
		}
		return minWeight[x];
	}
	bool sameSet(int x, int y) { return get(x) == get(y); }
	int size(int x) { return -1 * p[get(x)]; }
	bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) {
			return false;
		}
		if (p[x] > p[y]) {
			swap(x, y);
		}
		p[x] += p[y];
		p[y] = x;
		return true;
	}
};

int main() {
	freopen("skilevel.in", "r", stdin);
	freopen("skilevel.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool start;
			cin >> start;
			if (start) {
				startingPoints.pb(i * m + j);
			}
		}
	}
	DSU dsu;
	dsu.init(n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num = i * m + j;
			if (i > 0) {
				edges.pb({abs(arr[i][j] - arr[i - 1][j]), num, num - m});
			}
			if (j > 0) {
				edges.pb({abs(arr[i][j] - arr[i][j - 1]), num, num - 1});
			}
			if (i < n - 1) {
				edges.pb({abs(arr[i][j] - arr[i + 1][j]), num, num + m});
			}
			if (j < m - 1) {
				edges.pb({abs(arr[i][j] - arr[i][j + 1]), num, num + 1});
			}
		}
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++) {
		int a = edges[i][1]; 
		int b = edges[i][2];
		a = dsu.get(a);
		b = dsu.get(b);
		if ((dsu.size(a) < t) && (dsu.size(a) + dsu.size(b) >= t)) {
			minWeight[a] = edges[i][0];
		}
		if ((dsu.size(b) < t) && (dsu.size(a) + dsu.size(b) >= t)) {
			minWeight[b] = edges[i][0];
		}
		dsu.unite(a, b);
	}
	ll difficultySum = 0;
	for (int i : startingPoints) {
		difficultySum += dsu.getMinWeight(i);
	}
	cout << difficultySum << nl;
}
