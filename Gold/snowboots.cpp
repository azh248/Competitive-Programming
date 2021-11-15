/*
ID:azh248
LANG:C++
TASK:snowboots 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

int n, b;
vector<int> boots[100000];
pii tiles[100000];
int tileDepths[100000];
int indices[100000];
int depth[100000];
int nextWorking[100000]; // next valid snow tile after this tile
int prevWorking[100000]; // previous valid snow tile before this tile
int maxDist = 0;

bool cmp(vector<int> a, vector<int> b) {
	return a[0] > b[0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		cin >> depth[i];		
	}
	for (int i = 0; i < b; i++) {
		int x, y; cin >> x >> y;
		boots[i].pb(x);
		boots[i].pb(y);
		boots[i].pb(i);
	}
	sort(boots, boots + b, cmp);
	vector<int> working;
	for (int i = 0; i < n; i++) {
		if (boots[0][0] >= depth[i]) {
			if (working.size() > 0) {
				nextWorking[working[working.size() - 1]] = i;
				prevWorking[i] = working[working.size() - 1];
				maxDist = max(maxDist, i - prevWorking[i]);
			} 
			working.pb(i);
		} 
	}
	int results[100000];
	results[boots[0][2]] = (maxDist <= boots[0][1]);
	for (int i = 0; i < n; i++) {
		pii x;
		x.first = depth[i];
		x.second = i;
		tiles[i] = x;
	}
	sort(tiles, tiles + n);
	for (int i = 0; i < n; i++) {
		tileDepths[i] = tiles[i].first;
		indices[i] = tiles[i].second;
	}
	for (int i = 1; i < b; i++) {
		int failingTile = upper_bound(tileDepths, tileDepths + n, boots[i][0]) - tileDepths;
		for (int j = failingTile; j < n; j++) {
			if (tileDepths[j] > boots[i - 1][0] || tileDepths[j] <= boots[i][0]) {
				break;
			}
			int k = indices[j];
			if (k != 0 && k != n - 1) {
				nextWorking[prevWorking[k]] = nextWorking[k];
				prevWorking[nextWorking[k]] = prevWorking[k];
				maxDist = max(maxDist, nextWorking[k] - prevWorking[k]);
			}
		}
		results[boots[i][2]] = (maxDist <= boots[i][1]);
	}
	for (int i = 0; i < b; i++) {
		cout << results[i] << nl;
	}
}
