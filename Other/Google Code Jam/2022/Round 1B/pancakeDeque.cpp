#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define F0R1(i, a) for (int i = 1; i <= (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i = a; i > 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())
#define S0RT(arr, n) sort(arr, arr + n)

#define pA first
#define pB second
#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		int n; cin >> n;
		deque<int> dq;
		FOR(i, 0, n) {
			int num; cin >> num;
			dq.pb(num);
		}
		int maxPancake = 0;
		int numPaid = 0;
		while (dq.size() > 0) {
			if (dq.front() < dq.back()) {
				if (dq.front() >= maxPancake) {
					maxPancake = dq.front();
					numPaid++;
				}
				dq.pop_front();
			} else {
				if (dq.back() >= maxPancake) {
					maxPancake = dq.back();
					numPaid++;
				}
				dq.pop_back();
			}
		}
		cout << "Case #" << t1 << ": " << numPaid << nl;		
	}	
}