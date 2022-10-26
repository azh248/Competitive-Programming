#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define F0R1(i, a) for (int i = 1; i <= (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i = a; i > 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())
#define S0RT(arr, n) sort(arr, arr + n)

#define pA first
#define pB second
#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	// freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int h, w, c; cin >> h >> w >> c;
		string dummy;
		getline(cin, dummy);
		double x1, y1;
		vector<pii> grid;
		vector<pii> towers;
		vector<int> index;
		FOR(i, 0, h) {
			string s;
			getline(cin, s);
			FOR(j, 0, s.size()) {
				if (s[j] == '#') {
					grid.pb(pii(h - i, j));
				} else if (s[j] != ' '){
					if (s[j] == '0') {
						y1 = h - i - 0.5;
						x1 = j + 0.5;
					} else {
						towers.pb(pii(h - i, j));
						index.pb(s[j] - '0');
					}
				}
			}
		}
		vector<int> working;
		int curr = 0;
		for (pii tower : towers) {
			double y = tower.pA - 0.5;
			double x = tower.pB + 0.5;
			double lineSlope = (double)(y - y1) / (x - x1);
			double lineIntercept = y1 - lineSlope * x1;
			bool works = true;
			for (pii gridPoint : grid) {
				double y2 = gridPoint.pA;
				double x2 = gridPoint.pB;
				double x3 = gridPoint.pB + 1;
				if ((y2 > lineSlope * x2 + lineIntercept && x2 <= max(x, x1) + 0.5000001 && x2 >= min(x, x1) - 0.5000001) || (y2 > lineSlope * x3 + lineIntercept && x3 <= max(x, x1) + 0.5000001 && x3 >= min(x, x1) - 0.5000001)) {
					works = false;
					break;
				}
			}
			if (works) {
				working.pb(curr);
			}
			curr++;
		}
		if (working.size() == 0) {
			cout << "No viable locations" << nl;
			continue;
		} else {
			vector<int> totalWorking;
			for (int i : working) {
				totalWorking.pb(index[i]);
			}
			SORT(totalWorking);
			for (int i : totalWorking) {
				if (i == totalWorking[0]) {
					cout << i;
				} else {
					cout << " " << i;
				}
			}
			cout << nl;
		}
	}	
}
