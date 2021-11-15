#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, t;
bool blocked[30][30];
bool visited[30][30];
bool barrier[30][30];
pii virusLoc;

void ff(int i, int j, int dist) {
	if (i < 0 || i >= n || j < 0 || j >= n)
		return; // if outside grid
	if (blocked[i][j])
		return; // wrong color
	if (visited[i][j])
		return;			  // already visited this square
	if (dist == t + 1) {
		barrier[i][j] = true;
	}
	visited[i][j] = true; // mark current square as visited
	// recursively call floodfill for neighboring squares
	ff(i, j + 1, dist + 1);
	ff(i, j - 1, dist + 1);
	ff(i - 1, j, dist + 1);
	ff(i + 1, j, dist + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '#') {
				blocked[i][j] = true;
			} else if (s[j] == 'Z') {
				virusLoc = pii(i, j);
			}
		}
	}
	ff(virusLoc.first, virusLoc.second, 0);
	int barriers = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (barrier[i][j]) {
				barriers++;
			}
		}
	}
	cout << barriers << nl;
}