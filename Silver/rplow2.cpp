#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int x, y, n;
// these arrays store the edge, as well as if it's a leading edge (0) or a closing edge (1)
vector<int> verticalEdges[2000];
pii horizontalEdges[2000];
ll overlapCount[2001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> x >> y >> n;
	for (int i = 0; i < n; i++) {
		int x1, x2;
		cin >> x1 >> horizontalEdges[2 * i].first >> x2 >> horizontalEdges[2 * i + 1].first;
		horizontalEdges[2 * i + 1].first++;
		x2++;
		verticalEdges[2 * i].pb(x1);
		verticalEdges[2 * i].pb(0);
		verticalEdges[2 * i].pb(horizontalEdges[2 * i].first);
		verticalEdges[2 * i].pb(horizontalEdges[2 * i + 1].first);	
		verticalEdges[2 * i].pb(2 * i);
		horizontalEdges[2 * i].second = 2 * i;
		verticalEdges[2 * i + 1].pb(x2);
		verticalEdges[2 * i + 1].pb(1);	
		verticalEdges[2 * i + 1].pb(horizontalEdges[2 * i].first);
		verticalEdges[2 * i + 1].pb(horizontalEdges[2 * i + 1].first);	
		verticalEdges[2 * i + 1].pb(2 * i + 1);
		horizontalEdges[2 * i + 1].second = 2 * i + 1;
	}	
	sort(verticalEdges, verticalEdges + 2 * n);
	sort(horizontalEdges, horizontalEdges + 2 * n);
	map<pii, int> horizontalIndex;
	for (int i = 0; i < 2 * n; i++) {
		horizontalIndex.insert({horizontalEdges[i], i});
	}
	ll overlapArea = 0;
	for (int i = 0; i < 2 * n - 1; i++) {
		if (verticalEdges[i][1] == 0) {
			int upper = (*horizontalIndex.find({verticalEdges[i][3], verticalEdges[i][4] + 1})).second;
			int lower = (*horizontalIndex.find({verticalEdges[i][2], verticalEdges[i][4]})).second;
			for (int j = lower; j < upper; j++) {
				overlapCount[j]++;
			}
		} else {
			int upper = (*horizontalIndex.find({verticalEdges[i][3], verticalEdges[i][4]})).second;
			int lower = (*horizontalIndex.find({verticalEdges[i][2], verticalEdges[i][4] - 1})).second;
			for (int j = lower; j < upper; j++) {
				overlapCount[j]--;
			}
		}
		for (int j = 0; j < 2 * n - 1; j++) {
			overlapArea += (ll) (verticalEdges[i + 1][0] - verticalEdges[i][0]) * (ll) (horizontalEdges[j + 1].first - horizontalEdges[j].first) * (overlapCount[j] > 0);
		}
	}
	cout << overlapArea << nl;
}
