/*
ID:azh248
LANG:C++
TASK:mtime 
*/

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
pii arr[100000];

int main() {
	freopen("mtime.in", "r", stdin);
	freopen("mtime.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].pB >> arr[i].pA;
	}
	S0RT(arr, n);
	int start = 1e6 + 1;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i].pA < start) {
			start = arr[i].pA - arr[i].pB;
		} else {
			start -= arr[i].pB;
		}
	}
	cout << max(start, -1) << nl;
}
