#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

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
pii monsters[100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		FOR(i, 0, n) { cin >> monsters[i].pA; }
		FOR(i, 0, n) { cin >> monsters[i].pB; }
		vector<vector<ll> > events;
		FOR(i, 0, n) {
			events.pb({monsters[i].pA, 1, i}); // stop generating stuff for monster i
			events.pb({monsters[i].pA - monsters[i].pB + 1, 0, i}); // time we need to start generating stuff for monster i
		}
		SORT(events);
		unordered_set<int> currMonsters;
		ll totalCost = 0;
		int prevStart = 0;
		FOR(i, 0, events.size()) {
			vector<ll> event = events[i];
			if (currMonsters.size() == 0) {
				prevStart = event[0];
			}
			if (event[1] == 1) {
				currMonsters.erase(event[2]);
				if (currMonsters.size() == 0) {
					int curr = event[0];
					ll dist = (curr - prevStart + 1);
					totalCost += dist * (dist + 1) / 2;
				}
			} else {
				currMonsters.insert(event[2]);
			}
		}
		cout << totalCost << nl;
	}
}
