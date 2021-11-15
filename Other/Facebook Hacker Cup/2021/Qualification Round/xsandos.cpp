#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		int n; cin >> n;
		int grid[50][50];
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < n; j++) {
				if (s[j] == '.') {
					grid[i][j] = 0;
				} else if (s[j] == 'X'){
					grid[i][j] = 1;
				} else {
					grid[i][j] = 2;
				}
			}
		}
		map<int, int> minXsPlaced;
		for (int i = 0; i < n; i++) {
			int xsPlaced = 0;
			bool works = true;
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) {
					xsPlaced++;
				} else if (grid[i][j] == 2) {
					works = false;
					break;
				}
			}
			if (!works) {
				continue;
			}
			if (minXsPlaced.find(xsPlaced) == minXsPlaced.end()) {
				minXsPlaced.insert({xsPlaced, 1});
			} else {
				minXsPlaced[xsPlaced]++;
			}
		}
		for (int j = 0; j < n; j++) {
			int xsPlaced = 0;
			bool works = true;
			for (int i = 0; i < n; i++) {
				if (grid[i][j] == 0) {
					xsPlaced++;
				} else if (grid[i][j] == 2) {
					works = false;
					break;
				}
			}
			if (!works) {
				continue;
			}
			if (minXsPlaced.find(xsPlaced) == minXsPlaced.end()) {
				minXsPlaced.insert({xsPlaced, 1});
			} else {
				minXsPlaced[xsPlaced]++;
			}
		}
		for (int i = 0; i < n; i++) { 
			int empty = 0;
			int emptyLoc = -1;
			bool works = true;
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0){
					empty++;
					emptyLoc = j;
				} else if (grid[i][j] == 2) {
					works = false;
					break;
				}
			}
			if (!works) {
				continue;
			}
			if (empty == 1) {
				int empty1 = 0;
				bool works = true;
				for (int i1 = 0; i1 < n; i1++) {
					if (grid[i1][emptyLoc] == 0){
						empty1++;
					} else if (grid[i1][emptyLoc] == 2) {
						works = false;
						break;
					}
				}
				if (works && empty1 == 1) {
					minXsPlaced[1]--;
				}
			}
		}
		if (minXsPlaced.size() == 0) {
			cout << "Case #" << t1 << ": " << "Impossible" << nl;
			continue;
		}
		cout << "Case #" << t1 << ": " << (*minXsPlaced.begin()).first << " " << (*minXsPlaced.begin()).second << nl;
	}
}