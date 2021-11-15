/*
ID:azh248
LANG:C++
TASK:squares 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, k;
pii squares[50000];

struct cmp {
	bool operator()(pii a, pii b) {
		return a.second < b.second;
	}
};

int overlap(pii a, pii b) {
	int x, y;
	if (a.first < b.first) {
		x = (a.first + k - b.first);
	} else {
		x = (b.first + k - a.first);
	}
	if (a.second < b.second) {
		y = (a.second + k - b.second);
	} else {
		y = (b.second + k - a.second);
	}
	return x * y;
}

int main() {
	freopen("squares.in", "r", stdin);
	freopen("squares.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		squares[i] = {a, b};
	}
	sort(squares, squares + n);	
	vector<int> overlapping;
	int lag = 0;
	set<pii, cmp> interval;
	for (int i = 0; i < n; i++) {
		interval.insert(squares[i]);
		while (squares[i].first - squares[lag].first >= k) {
			interval.erase(squares[lag]);
			lag++;
		}
		if (interval.lower_bound(squares[i]) != interval.begin()) {
			if (squares[i].second - (*prev(interval.lower_bound(squares[i]))).second < k) {
				overlapping.pb(overlap(squares[i], *prev(interval.lower_bound(squares[i]))));
			}
		} if (interval.upper_bound(squares[i]) != interval.end()) {
			if ((*interval.upper_bound(squares[i])).second - squares[i].second < k) {
				overlapping.pb(overlap(squares[i], *interval.upper_bound(squares[i])));
			}
		} 
	}
	if (overlapping.size() == 0) {
		cout << 0 << nl;
	} else if (overlapping.size() > 1) {
		cout << -1 << nl;
	} else {
		cout << overlapping[0] << nl;
	}
}
