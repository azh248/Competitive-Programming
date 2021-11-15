#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;

vector<int> interactions[200000];

bool cmp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

struct DSU {
	vector<int> vec;
	ll scores[100000]; // keeps track of the sum of T scores in each clique's leader
	set<int> cliques; // contains the leaders of all cliques
	int get(int x) { 
		return vec[x] < 0 ? x : vec[x] = get(vec[x]);
	}
	int size(int x) {
		return -1 * vec[get(x)]; 
	}
	bool unite(int x, int y, int score) {
		x = get(x); 
		y = get(y); 
		if (x == y) {
			return false;
		}
		if (vec[x] > vec[y]) {
			swap(x, y);
		}
		vec[x] += vec[y];
		vec[y] = x;
		cliques.erase(y);
		scores[x] += scores[y];
		scores[x] += score;
		return true;
	}
};


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		vector<int> vec;
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		vec.pb(a);
		vec.pb(b);
		vec.pb(c);
		interactions[i] = vec;
	}	
	sort(interactions, interactions + m, cmp);
	DSU dsu;
	dsu.vec = vector<int>(n, -1);  
	for (int i = 0; i < n; i++) {
		dsu.cliques.insert(i);
	}
	int index = 0;
	for (int i = 1; i <= n; i++) {  
		if (index < m) {
			while (interactions[index][2] <= i) {
				// process interaction
				dsu.unite(interactions[index][0], interactions[index][1], interactions[index][2]);

				index++;
				if (index >= m) {
					break;
				}
			}
		}
		ll product = 1;
		for (int i : dsu.cliques) {
			product *= (dsu.scores[dsu.get(i)] + dsu.size(i));
			product %= MOD;
		}
		cout << product << nl;
	}
}
