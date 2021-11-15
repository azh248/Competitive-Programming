#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, l;
pii moves[100002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> n;
	moves[0] = {0, 1};
	for (int i = 1; i <= n; i++) {
		cin >> moves[i].first >> moves[i].second;		
	}	
	moves[n + 1] = {l, 1e9};
	sort(moves, moves + n + 2);
	int minimum[100002];
	minimum[n + 1] = moves[n + 1].first + moves[n + 1].second;
	for (int i = n; i > 0; i--) {
		minimum[i] = min(minimum[i + 1], moves[i].first + moves[i].second);
	}
	int maximum[100002];
	maximum[0] = 1;
	for (int i = 1; i <= n + 1; i++) {
		maximum[i] = min(maximum[i - 1] + moves[i].first - moves[i - 1].first, minimum[i] - moves[i].first);
	}
	int maxSpeed = 0;
	for (int i = 0; i < n; i++) {
		maxSpeed = max(maxSpeed, max(maximum[i], maximum[i + 1]) + (moves[i + 1].first - moves[i].first - abs(maximum[i + 1] - maximum[i]))/2);
	}
	maxSpeed = max(maxSpeed, maximum[n] + (l - moves[n].first));
	cout << maxSpeed << nl;
}
