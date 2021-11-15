/*
ID:azh248
LANG:C++
TASK:newbarn 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

int n;
pii diameterNodes[100000];
int root[100000];
int dist[100000];
vector<int> adjLists[100000];
int par[100000];
int anc[100000][18];

void findAncestors() {
	for (int i = 0; i < n; i++) {
		if (dist[i] != 0) {
			anc[i][0] = par[i];
		}
	}
	for (int j = 1; j <= 17; j++) {
		for (int i = 0; i < n; i++) {
			if (dist[i] != 0) {
				anc[i][j] = anc[anc[i][j - 1]][j - 1];
			}
		}
	}
}

int lca(int a, int b) {
	if (dist[a] > dist[b]) { // swap if a is further
		return lca(b, a);
	}
	if (dist[a] < dist[b]) { // find ancestor of b that's the same depth as a
		for (int k = 17; dist[b] != dist[a]; k--) {
			while (dist[b] - (1 << k) >= dist[a]) {
				b = anc[b][k];
			}
		}
	}
	for (int k = 17; k > 0; k--) {
		while (anc[a][k] != anc[b][k]) {
			a = anc[a][k];
			b = anc[b][k];
		}
	}
	while (a != b) {
		a = par[a];
		b = par[b];
	}
	return a;
}

int distance(int a, int b) {
	int ancestor = lca(a, b);
	return dist[a] + dist[b] - 2 * dist[ancestor];
}

int main() {
	freopen("newbarn.in", "r", stdin);
	freopen("newbarn.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int index = 0;
	vector<pii> queries;
	for (int i = 0; i < n; i++) {
		string type; cin >> type;
		int num; cin >> num;
		if (type == "B") {
			if (num == -1) {
				root[index] = index;
				diameterNodes[index] = {index, index};
				index++;
			} else {
				num--;
				dist[index] = dist[num] + 1;
				par[index] = num;
				root[index] = root[num];
				anc[index][0] = par[index];
				for (int i = 1; i <= 17; i++) {
					anc[index][i] = anc[anc[index][i - 1]][i - 1];
				}
				if (distance(index, diameterNodes[root[index]].first) > distance(diameterNodes[root[index]].first, diameterNodes[root[index]].second)) {
					if (distance(index, diameterNodes[root[index]].second) > distance(index, diameterNodes[root[index]].first)) {
						diameterNodes[root[index]].first = index;
					} else {
						diameterNodes[root[index]].second = index;
					}
				} else if (distance(index, diameterNodes[root[index]].second) > distance(diameterNodes[root[index]].first, diameterNodes[root[index]].second)) {
					diameterNodes[root[index]].first = index;
				}
				index++;
			}
		} else {
			num--;
			cout << max(distance(num, diameterNodes[root[num]].first), distance(num, diameterNodes[root[num]].second)) << nl;
		}
	}
}
