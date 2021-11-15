#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, w;
pii changes[50000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; a--;
		changes[i] = {a, b};
	}
	int minBuildings = 0;	
	set<int> buildings;
	for (int i = 0; i < n; i++) {
		if (buildings.count(changes[i].second) == 0 && changes[i].second != 0) {
			buildings.insert(changes[i].second);
			minBuildings++;
		}
		buildings.erase(buildings.upper_bound(changes[i].second), buildings.end()); 
	}
	cout << minBuildings << nl;
}
