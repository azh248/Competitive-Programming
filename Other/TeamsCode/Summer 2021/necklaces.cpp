#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	multiset<int> cuts;
	for (int i = 0; i < m; i++) {
		char c;
		int num;
		cin >> c >> num; num--;
		if (c == 'R') {
			cuts.insert(num);
		} else {
			if (cuts.size() == 0) {
				cout << n << nl;
				continue;
			}
			auto it = cuts.lower_bound(num);
			if (it == cuts.begin()) {
				cout << (*it + 1) << nl;
			} else if (it == cuts.end()) {
				cout << (n - *--it - 1) << nl;
			} else {
				cout << (*it - *--it) << nl;
			}
		}
	}
}