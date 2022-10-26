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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int cost = 0;
	int prev;
	cin >> prev;
	for (int i = 1; i < n; i++) {
		int next;
		cin >> next;
		cost += (next > prev) ? (2 * (next - prev)) : (prev - next);
		prev = next;
	}
	cout << cost << nl;
}
