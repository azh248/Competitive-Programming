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

int n;

int main() {
	freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> curr(3);
	cin >> curr[0] >> curr[1] >> curr[2];
	int cnt = 0;
	for (int i = 3; i < 2000; i++) {
		int curr1;
		cin >> curr1;
		if (curr1 > curr[0]) {
			cnt++;
		}
		curr[0] = curr[1];
		curr[1] = curr[2];
		curr[2] = curr1;
	}
	cout << cnt << nl;
}
