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

int n, m, k, q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k >> q;
    set<int> roads[m + 5];
	for (int i = 0; i < k; i++) {
		int a, b, y; cin >> a >> b >> y;
        a--;
        b--;
        FOR(j, a, b) {
            roads[j].insert(y);
        }
	}
    FOR(i, 0, q) {
        // sort
        pii p1, p2;
        cin >> p1.pA >> p1.pB >> p2.pA >> p2.pB;
        if (p1.pA > p2.pA) {
            swap(p1, p2);
        }
        p1.pA--;
        p2.pA--;
        bool possible = true;
        for (int j = p1.pA; j < p2.pA; j++) {
            if (roads[j].size() == 0) {
                possible = false;
                break;
            }
            auto ptr = roads[j].lower_bound(min(p1.pB, p2.pB));
            if (ptr == roads[j].end()) {
                possible = false;
                break;
            }
            int firstRoad = *(ptr);
            if (firstRoad > max(p1.pB, p2.pB)) {
                possible = false;
                break;
            }
        }
        if (possible) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
    }
}
