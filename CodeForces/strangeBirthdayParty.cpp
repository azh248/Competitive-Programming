#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pub push_back
#define pob pop_back
#define long long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int w = 0; w < t; w++) {
		int n, m;
		cin >> n >> m;
		deque<int> friends;
		int presents[m];
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			friends.pub(num - 1);
		} 
		for (int i = 0; i < m; i++) {
			cin >> presents[i];
		}
		sort(friends.begin(), friends.end());
		ll sum = 0;
		for (int i = 0; i < m; i++) {
			if (friends.size() == 0) {
				break;
			}
			while (friends.front() == i) {
				sum += presents[i];
				friends.pop_front();
				if (friends.size() == 0) {
					break;
				}
			}
			if (friends.size() == 0) {
				break;
			}
			sum += presents[i];
			friends.pop_back();
		}
		cout << sum << nl;
	}
}
