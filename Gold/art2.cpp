#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
int arr[100000];
vector<int> zeroes;
vector<int> appearances[100001];

int main() {
	freopen("art2.in", "r", stdin);
	freopen("art2.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];			
	}	
	zeroes.pb(-1);
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			zeroes.pb(i);
		} else {
			appearances[arr[i]].pb(i);
		}
	}
	zeroes.pb(n);
	queue<vector<int> > intervalQ;
	int maxRounds = 0; // maximum rounds across all disjoint intervals
	for (int i = 0; i < zeroes.size() - 1; i++) {
		int intervalStart = zeroes[i] + 1;
		int intervalEnd = zeroes[i + 1] - 1;
		intervalQ.push({intervalStart, intervalEnd, 0});
	}
	while (!intervalQ.empty()) {
		int start = intervalQ.front()[0];
		int end = intervalQ.front()[1];
		int rounds = intervalQ.front()[2];
		intervalQ.pop();
		if (start > end) {
			continue;
		}
		maxRounds = max(maxRounds, rounds + 1);
		if (appearances[arr[start]][0] < start || appearances[arr[start]][appearances[arr[start]].size() - 1] > end) {
			cout << -1 << nl;
			return 0;
		}
		for (int i = 0; i < appearances[arr[start]].size() - 1; i++) {
			if (appearances[arr[start]][i + 1] - appearances[arr[start]][i] != 1) {
				intervalQ.push({appearances[arr[start]][i] + 1, appearances[arr[start]][i + 1] - 1, rounds + 1});
			}
		}
		intervalQ.push({appearances[arr[start]][appearances[arr[start]].size() - 1] + 1, end, rounds});
	}
	cout << maxRounds << nl;
}
