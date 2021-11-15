#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	freopen("traffic_control_input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		int n, m, a, b; cin >> n >> m >> a >> b;
		if (a < (n + m - 1) || b < (n + m - 1)) {
			cout << "Case #" << t1 << ": " << "Impossible" << nl;
			continue;
		} else {
			cout << "Case #" << t1 << ": " << "Possible" << nl;
		}
		cout << (a - (n + m - 2)) << " ";
		for (int i = 1; i < m - 1; i++) {
			cout << 1 << " ";
		}
		cout << (b - (n + m - 2)) << nl;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << 1 << " ";
			}
			cout << nl;
		}
	}
}