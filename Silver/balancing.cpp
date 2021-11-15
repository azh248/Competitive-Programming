#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
vector<pii> coords;
vector<int> coordsX;
vector<int> coordsY;

int main() {
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		coords.pb({a, b});
		coordsX.pb(coords[i].first);
		coordsY.pb(coords[i].second);
	}	
	sort(coordsX.begin(), coordsX.end());
	sort(coordsY.begin(), coordsY.end());

	int topLeft = 0;
	int topRight = 0;
	int bottomLeft = 0;
	int bottomRight = 0;
	int smallestMaximumCows = coords.size();

	for (int y = coordsX.size() / 4; y < coordsX.size() * 2.5 / 4; y++) {
		for (int x = coordsY.size() / 4; x < coordsY.size() * 2.5 / 4; x++) {
			int yAxis = coordsX[y] + 1;
			int xAxis = coordsY[x] + 1;
			
			topLeft = 0;
			topRight = 0;
			bottomLeft = 0;
			bottomRight = 0;
			for (pii i : coords) {
				if ((i.first > yAxis) && (i.second > xAxis)) {
					topRight++;
				} else if ((i.first > yAxis) && (i.second < xAxis)) {
					topLeft++;
				} else if ((i.first < yAxis) && (i.second > xAxis)) {
					bottomRight++;
				} else if ((i.first < yAxis) && (i.second < xAxis)) {
					bottomLeft++;
				}
			}
			smallestMaximumCows = min(smallestMaximumCows, max(max(topLeft, topRight), max(bottomLeft, bottomRight)));
		}
	}
	cout << smallestMaximumCows << nl;
}
