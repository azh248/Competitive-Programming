#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	int arr[100][100];
	vector<int> rows;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
		int currStreak = 0;
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				currStreak++;
			} else {
				if (currStreak != 0) {
					rows.pb(currStreak);
					currStreak = 0;
				}
			}
		}
		rows.pb(currStreak);
	}
	sort(rows.begin(), rows.end(), greater<int>());
	int sum = 0;
	for (int i = 0; i < k; i++) {
		if (i >= rows.size()) {
			break;
		}
		sum += rows[i];
	}
	cout << sum << nl;
}