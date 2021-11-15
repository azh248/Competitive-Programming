/*
ID:azh248
LANG:C++
TASK:lines 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
pii points[200];

int main() {
	freopen("lines.in", "r", stdin);
	freopen("lines.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
	}
	set<double> slopes;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (points[i].first == points[j].first) {
				slopes.insert(1e9);
			} else if (points[i].second == points[j].second) {
				slopes.insert(0);
			} else {
				slopes.insert((double)(points[j].second - points[i].second)/(double)(points[j].first - points[i].first));
			}
		}
	}
	cout << slopes.size() << nl;
}