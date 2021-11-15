#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<pii> acs;
		for (int i = 0; i < k; i++) {
			ll num;
			cin >> num;
			acs.pb({num - 1, -1});
		}
		for (int i = 0; i < k; i++) {
			ll num;
			cin >> num;
			acs[i].second = num;
		}
		sort(acs.begin(), acs.end());
		multiset<ll> left;
		multiset<ll> right;
		for (int i = 0; i < k; i++) {
			int num = acs[i].second + acs[i].first;
			right.insert(acs[i].second + acs[i].first);
		}
		int acNum = 0;
		for (int i = 0; i < n; i++) {
			if (right.size() == 0) {
				cout << *left.begin() + i << " ";
			} else if (left.size() == 0) {
				cout << *right.begin() - i << " ";
			} else {
				int num = *right.begin() - i;
				int num1 = *left.begin() + i;
				cout << min(*right.begin() - i, *left.begin() + i) << " ";
			}
			if (acNum < k && acs[acNum].first == i) {
				right.erase(right.find(acs[acNum].second + acs[acNum].first));
				left.insert(acs[acNum].second - acs[acNum].first);
				acNum++;
			}
		}
		cout << nl;
	}
}
