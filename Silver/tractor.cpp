/*
ID:azh248
LANG:C++
TASK:tractor 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n;
int arr[500][500];

unordered_set<int> visited;
int componentSize = 0;

void ff(int i, int j, int prevHeight, int cost) {
    if (i < 0 || i >= n || j < 0 || j >= n)
        return; // if outside grid
    if (abs(arr[i][j] - prevHeight) > cost)
        return; // wrong color
    if (visited.count(i * n + j) > 0)
        return;           // already visited this square
    visited.insert(i * n + j); // mark current square as visited
	componentSize++;
    // recursively call floodfill for neighboring squares
    ff(i, j + 1, arr[i][j], cost);
    ff(i, j - 1, arr[i][j], cost);
    ff(i - 1, j, arr[i][j], cost);
    ff(i + 1, j, arr[i][j], cost);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("tractor.in", "r", stdin);
	freopen("tractor.out", "w", stdout);
    cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}	
	int ans = -1;
	int l = 0;
	int r = 1e6;
	while (l <= r) {
		ll mid = (r + l)/2;
		bool works = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ff(i, j, arr[i][j], mid);
				if (componentSize >= ceil(n * n/2)) {
					works = true;
				}
				componentSize = 0;
			}
		}
		visited.clear();
		if (works) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << nl;
}
