/*
ID:azh248
LANG:C++
TASK:split 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n;

pii points[50000];

bool cmp1(pii a, pii b) {
	return a.first < b.first;
}

bool cmp2(pii a, pii b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
    cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
	}	
	pii forwardHeight[n];
	pii backwardHeight[n];
	sort(points, points + n, cmp2);
	forwardHeight[0] = {points[0].first, points[0].first};
	backwardHeight[n - 1] = {points[n - 1].first, points[n - 1].first};
	for (int i = 1; i < n; i++) {
		forwardHeight[i].first = min(forwardHeight[i - 1].first, points[i].first);
		forwardHeight[i].second = max(forwardHeight[i - 1].second, points[i].first);
	}
	for (int i = n - 2; i >= 0; i--) {
		backwardHeight[i].first = min(backwardHeight[i + 1].first, points[i].first);
		backwardHeight[i].second = max(backwardHeight[i + 1].second, points[i].first);
	}
	ll minArea = 1e18;
	for (int i = 0; i < n - 1; i++) {
		minArea = min(minArea, (ll)(points[i].second - points[0].second) * (ll)(forwardHeight[i].second - forwardHeight[i].first) + (ll)(points[n - 1].second - points[i + 1].second) * (ll)(backwardHeight[i + 1].second - backwardHeight[i + 1].first));
	}
	pii forwardWidth[n];
	pii backwardWidth[n];
	sort(points, points + n, cmp1);
	forwardWidth[0] = {points[0].second, points[0].second};
	backwardWidth[n - 1] = {points[n - 1].second, points[n - 1].second};
	for (int i = 1; i < n; i++) {
		forwardWidth[i].first = min(forwardWidth[i - 1].first, points[i].second);
		forwardWidth[i].second = max(forwardWidth[i - 1].second, points[i].second);
	}
	for (int i = n - 2; i >= 0; i--) {
		backwardWidth[i].first = min(backwardWidth[i + 1].first, points[i].second);
		backwardWidth[i].second = max(backwardWidth[i + 1].second, points[i].second);
	}
	for (int i = 0; i < n - 1; i++) {
		minArea = min(minArea, (ll)(points[i].first - points[0].first) * (ll)(forwardWidth[i].second - forwardWidth[i].first) + (ll)(points[n - 1].first - points[i + 1].first) * (ll)(backwardWidth[i + 1].second - backwardWidth[i + 1].first));
	}
	cout << (backwardWidth[0].second - backwardWidth[0].first) * (points[n - 1].first - points[0].first) - minArea << nl;
}
