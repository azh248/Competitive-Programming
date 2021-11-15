#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int d, p, c, f, s;

int dist[220][220];

int floydWarshall() {
	int maxDist = 0;
	for (int k = 0; k < c; k++) {
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < c; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				if (i == s) {
					maxDist = max(maxDist, -dist[i][j]);
				}
			}
		}
	}
	for (int i = 0; i < c; i++) {
		if (dist[i][i] < 0) {
			return -1;
		}
	}
	return maxDist;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> d >> p >> c >> f >> s;
	s--;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			dist[i][j] = 1e9;
		}
	}
	for (int i = 0; i < p; i++) {
		int a, b; cin >> a >> b; a--; b--;
		dist[a][b] = -d;
	}
	for (int i = 0; i < f; i++) {
		int j, k, t; cin >> j >> k >> t; j--; k--;
		dist[j][k] = min(dist[j][k], -(d - t));
	}
	cout << d + floydWarshall() << nl;
}
