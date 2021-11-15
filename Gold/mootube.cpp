/*
ID: azh248
LANG: C++
TASK:mootube 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back
#define long long long

int n, q;
vector<vector<int> > sides; // sides[i] = {relevance of connection, video1, video2}
vector<vector<int> > queries; // queries[i] = {value of K, video, query number}
int ans[100000]; // ans[i] = answer to ith query

struct DSU {
	vector<int> p;
	void init(int n) { p = vector<int>(n, -1); }
	int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
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

bool cmp(vector<int> a, vector<int> b) {
	return a[0] > b[0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
    cin >> n >> q;
	// sort video connections by relevance, sort queries by k keeping track of
	// which query is which, as you go down the values of k add the video
	// connections that are relevant
	for (int i = 0; i < n - 1; i++) { 
		int a, b, r;
		cin >> a >> b >> r;
        vector<int> add{r, a - 1, b - 1};
		sides.pb(add);
	}
	for (int i = 0; i < q; i++) {
		int k, v;
		cin >> k >> v;
        vector<int> add{k, v - 1, i};
		queries.pb(add);
	}
	sort(sides.begin(), sides.end(), cmp);
	sort(queries.begin(), queries.end(), cmp);
    int currentSide = 0;
    DSU dsu;
	dsu.init(n);
	for (int i = 0; i < q; i++) {
        while (currentSide < n - 1 && sides[currentSide][0] >= queries[i][0]) {
			dsu.unite(sides[currentSide][1], sides[currentSide][2]);
            currentSide++;
		}
        ans[queries[i][2]] = dsu.size(queries[i][1]);
	}
    for (int i = 0; i < q; i++) {
        cout << ans[i] - 1 << nl;
    }
}
