/*
ID:azh248
LANG:C++
TASK:crowded 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, d;
pii cows[100000];

struct cmp {
	bool operator()(pii a, pii b) {
		return a.second < b.second;
	}
};

int main() {
	freopen("crowded.in", "r", stdin);
	freopen("crowded.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> cows[i].first >> cows[i].second;		
	}	
	sort(cows, cows + n);
	int lag = 0;
	set<pii, cmp> intervalL;
	set<pii, cmp> intervalR;
	int crowded = 0;
	int front = 0;
	for (int i = 0; i < n; i++) {
		while (front < n && cows[front].first - cows[i].first <= d) {
			intervalR.insert(cows[front]);
			front++;
		}
		while (cows[i].first - cows[lag].first > d) {
			intervalL.erase(cows[lag]);
			lag++;
		}
		intervalR.erase(cows[i]);
		if (intervalL.size() > 0 && (*--intervalL.end()).second >= 2 * cows[i].second && intervalR.size() > 0 && (*--intervalR.end()).second >= 2 * cows[i].second) {
			crowded++;
		}
		intervalL.insert(cows[i]);
	}
	cout << crowded << nl;
}
