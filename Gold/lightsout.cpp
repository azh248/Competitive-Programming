/*
ID:azh248
LANG:C++
TASK:lightsout 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n;
pii points[201];

int main() {
	freopen("lightsout.in", "r", stdin);
	freopen("lightsout.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
	// construct array starting and ending with the exit node, with 0 for exit node, -1 for 90 degree, -2 for -270 degree, and whatver edge lengths there are -- 
	// then find the minimum length unique sequence starting from each even index (node) (do this by keeping a multiset of lists of array values and make sure 
	// there's only one occurence of the list)
	for (int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
	}
	points[n] = points[0];
	int arr[400]; // for nodes, if the value is 1 then you're turning right, if it's 2 you're turning left
	arr[0] = 0;
	arr[1] = abs(points[1].first - points[0].first + points[1].second - points[0].second);
	for (int i = 1; i < n - 1; i++) {
		arr[2 * i + 1] = abs(points[i + 1].first - points[i].first + points[i + 1].second - points[i].second);
		if (points[i + 1].first > points[i].first) {
			if (points[i - 1].second < points[i].second) {
				arr[2 * i] = 1;
			} else {
				arr[2 * i] = 2;
			}
		} else if (points[i + 1].first < points[i].first) {
			if (points[i - 1].second < points[i].second) {
				arr[2 * i] = 2;
			} else {
				arr[2 * i] = 1;
			}
		} else if (points[i + 1].second > points[i].second) {
			if (points[i - 1].first < points[i].first) {
				arr[2 * i] = 2;
			} else {
				arr[2 * i] = 1;
			}
		} else {
			if (points[i - 1].first < points[i].first) {
				arr[2 * i] = 1;
			} else {
				arr[2 * i] = 2;
			}
		}
	}
	multiset<vector<int>> sequences;
	for (int i = 0; i < n; i++) {
		vector<int> seq;
		for (int j = i; j < n; j++) {
			seq.pb(arr[2 * j]);
			sequences.insert(seq);
			seq.pb(arr[2 * j + 1]);
		}
	}
	int dist[201];
	dist[0] = 0;
	dist[n] = 0;
	for (int i = 1; i < n; i++) {
		dist[i] = dist[i - 1] + abs(points[i - 1].first - points[i].first + points[i - 1].second - points[i].second);
	}
	for (int i = n - 1; i >= 1; i--) {
		dist[i] = min(dist[i], dist[i + 1] + abs(points[i + 1].first - points[i].first + points[i + 1].second - points[i].second));
	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		int cost = 0;
		vector<int> seq;
		int jEnd = n;
		for (int j = i; j < n; j++) {
			seq.pb(arr[2 * j]);
			if (sequences.count(seq) == 1) {
				jEnd = j;
				break;
			}
			cost += abs(points[j + 1].first - points[j].first + points[j + 1].second - points[j].second);
			seq.pb(arr[2 * j + 1]);
		}
		ans = max(ans, cost + dist[jEnd] - dist[i]);
	}
	cout << ans << nl;
}
