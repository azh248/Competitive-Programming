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

bool cmp(pii a, pii b) {
    if (a.pA == b.pA) return (a.pB < b.pB);
    return a.pA < b.pA;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
        vector<pii> points;
        for (int i = 0; i < 4; i++) {
            int x, y; cin >> x >> y;
            points.pb({x, y});
        }
        sort(points.begin(), points.end(), cmp);
        cout << (points[1].pB - points[0].pB) * (points[2].pA - points[1].pA) << nl;
	}	
}
