#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back
#define long long long

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("cables.in", "r", stdin);
	freopen("cables.out", "w", stdout);
    cin >> n;
	vector<vector<int> > devices;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		devices.pb({x, y, z});
	}	
	int totalDist = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			totalDist += abs(devices[i][0] - devices[j][0]) + abs(devices[i][1] - devices[j][1]) + abs(devices[i][2] - devices[j][2]);
		}
	}
	cout << totalDist << nl;
}
