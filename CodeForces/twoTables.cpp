#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		ll W, H, a1, b1, a2, b2, w, h;
		cin >> W >> H >> a1 >> b1 >> a2 >> b2 >> w >> h;
		ll yDist1 = b1;
		ll yDist2 = H - b2;
		ll xDist1 = a1;
		ll xDist2 = W - a2;
		if ((w + (a2 - a1) > W && h + (b2 - b1) > H)){
			cout << -1 << nl;
			continue;
		}
		ll minDisplacement = -1;
		if (w + (a2 - a1) <= W) {
			int distNeeded = w;
			if (distNeeded <= xDist1 || distNeeded <= xDist2) {
				minDisplacement = 0;
			} else {
				minDisplacement = min(distNeeded - xDist1, distNeeded - xDist2);
			}
		}
		if (h + (b2 - b1) <= H) {
			int distNeeded = h;
			if (minDisplacement == -1) {
				if (distNeeded <= yDist1 || distNeeded <= yDist2) {
					minDisplacement = 0;
				} else {
					minDisplacement = min(distNeeded - yDist1, distNeeded - yDist2);
				}
			} else {
				if (distNeeded <= yDist1 || distNeeded <= yDist2) {
					minDisplacement = 0;
				} else {
					minDisplacement = min(minDisplacement, min(distNeeded - yDist1, distNeeded - yDist2));
				}
			}
		}
		cout << minDisplacement << nl;
	}
}