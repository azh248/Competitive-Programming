/*
ID:azh248
LANG:C++
TASK:ccski 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, m;
int arr[500][500];
bool waypoint[500][500];
bool visited[500][500];
int waypointsReached = 0;
int waypointCount = 0;

void ff(int i, int j, int prevHeight, int d) {
    if (i < 0 || i >= n || j < 0 || j >= m)
        return; // if outside grid
    if (abs(arr[i][j] - prevHeight) > d)
        return; // wrong color
    if (visited[i][j])
        return;           // already visited this square
    visited[i][j] = true; // mark current square as visited
	if (waypoint[i][j]) {
		waypointsReached++;
	}
    // recursively call floodfill for neighboring squares
    ff(i, j + 1, arr[i][j], d);
    ff(i, j - 1, arr[i][j], d);
    ff(i - 1, j, arr[i][j], d);
    ff(i + 1, j, arr[i][j], d);
}


int main() {
	freopen("ccski.in", "r", stdin);
	freopen("ccski.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> waypoint[i][j];
			if (waypoint[i][j]) {
				waypointCount++;
			}
		}
	}	
	int l = 0;
	int r = 1e9;
	int ans = l - 1;
	while (l <= r) {
		ll mid = (r + l)/2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = false;
			}
		}
		bool works = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (waypoint[i][j]) {
					ff(i, j, arr[i][j], mid);
					if (waypointsReached == waypointCount) {
						works = true;
					}
					waypointsReached = 0;
					break;
				}
			}
		}
		if (works) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << nl;
}
