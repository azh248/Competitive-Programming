/*
ID:azh248
LANG:C++
TASK:portals 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define nl "\n"; 
#define pb push_back

int n;

int cost[100000];
int locations[200000];

struct DSU {
	vector<int> p;
	void init(int n) { 
		p = vector<int>(n, -1); 
	}
	int get(int x) { 
		return p[x] < 0 ? x : p[x] = get(p[x]);
	}
	bool sameSet(int x, int y) {
		return get(x) == get(y);
	}
	int size(int x) {
		return -1 * p[get(x)]; 
	}
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

int portals[100000][4];

vector<vector<int> > edges;

bool cmp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

struct DSU1 {
	vector<int> p;
	void init(int n) { p = vector<int>(n, -1); }
	int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); }
	bool sameSet(int x, int y) { return get(x) == get(y); }
	int size(int x) { return -1 * p[get(x)]; }
	bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) {
			return false;
		}
		if (p[x] > p[y])
			swap(x, y);
		p[x] += p[y];
		p[y] = x;
		return true;
	}
};

ll kruskals() { 
	sort(edges.begin(), edges.end(), cmp);
	DSU1 dsu;
	dsu.init(2 * n);
	ll weight = 0;
	for (int i = 0; i < edges.size(); i++) {
		vector<int> edge = edges[i];
		if (dsu.sameSet(edge[0], edge[1])) {
			continue;
		}
		dsu.unite(edge[0], edge[1]);
		weight += edge[2];
	}
	return weight;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cost[i] >> portals[i][0] >> portals[i][1] >> portals[i][2] >> portals[i][3]; portals[i][0]--; portals[i][1]--; portals[i][2]--; portals[i][3]--;
	}	
	DSU dsu;
	dsu.init(2 * n);
	vector<int> linked[200000];
	for (int i = 0; i < n; i++) {
		linked[portals[i][0]].pb(i);
		linked[portals[i][1]].pb(i);	
		linked[portals[i][2]].pb(i + n);
		linked[portals[i][3]].pb(i + n);
	}
	for (int i = 0; i < 2 * n; i++) {
		dsu.unite(linked[i][0], linked[i][1]);
	}

	// for (int i = 0; i < 2 * n; i++) {
	// 	cout << dsu.p[i] << " ";
	// }
	// now everything has been linked together and the connected components have been established, now we just have to link together the connected components
	for (int i = 0; i < n; i++) {
		edges.pb({dsu.get(i), dsu.get(i + n), cost[i]});
	}
	cout << kruskals() << nl;
}
