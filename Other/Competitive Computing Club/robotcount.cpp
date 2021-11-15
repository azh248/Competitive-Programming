#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back
#define long long long

int n, q;

bool cmp(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

int dist(vector<int> a, vector<int> b) {
	return abs(a[0] - b[0]) + abs(a[1] - b[1]) + abs(a[2] - b[2]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("robotcount.in", "r", stdin);
	freopen("robotcount.out", "w", stdout);
    cin >> n >> q;
	vector<vector<int> > devices;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		devices.pb({x, y, z});
	}	
	sort(devices.begin(), devices.end(), cmp);
	for (int i = 0; i < q; i++) {
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		int working = 0;
		vector<int> point1 = {x1, y1, z1};
		vector<int> point2 = {x2, y2, z2};
		for (auto i = 0; i < n; i++) {
			vector<int> vec = devices[i];
			if (dist(point2, vec) + dist(point1, vec) == dist(point1, point2)) {
				working++;
			}
		}	
		cout << working << nl;	
	}
}
