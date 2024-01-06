#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

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
#define MOD (ll)1000000007
#define nl "\n"
#define pb push_back

int t;

ll findSquareSum(vector<pii> coordinates, int n) {
    ll xSquares = 0, ySquares = 0;
    ll xTot = 0, yTot = 0;
 
    ll distSum = 0;
 
    FOR(i, 0, n) {
        ll a = coordinates[i].pA;
        ll b = coordinates[i].pB;
 
        distSum += xSquares;
        distSum %= MOD;
        distSum -= (2 * ((xTot * a) % MOD)) % MOD;
        distSum += MOD;
        distSum %= MOD;
 
        distSum += (ll)i * ((a * a) % MOD);
        distSum %= MOD;
 
        xSquares += a * a;
        xSquares %= MOD;
        xTot += a;
        xTot %= MOD;
        distSum += ySquares;
        distSum %= MOD;
        distSum -= (2 * ((yTot * b) % MOD)) % MOD;
        distSum += MOD;
        distSum %= MOD;
        distSum += i * ((b * b) % MOD);
        distSum %= MOD;
 
        ySquares += b * b;
        ySquares %= MOD;
        yTot += b;
        yTot %= MOD;
    }
    return distSum;
}

int main() {
    freopen("b2_test.in", "r", stdin);
    freopen("b2_test.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
        int n;
        cin >> n;
        vector<pii> coordinates;
        F0R(i, n) {
            ll x, y;
            cin >> x >> y;
            coordinates.pb({x, y});
        }
        SORT(coordinates);
        ll distSumTrees = findSquareSum(coordinates, n);
        int q; cin >> q;
        vector<pii> queries;
        F0R(i, q) {
            ll x, y;
            cin >> x >> y;
            queries.pb({x, y});
        }
        ll distSumWells = findSquareSum(queries, q);
        vector<pii> allPoints;
        F0R(i, n) {
            allPoints.pb(coordinates[i]);
        }
        F0R(i, q) {
            allPoints.pb(queries[i]);
        }
        SORT(allPoints);
        ll distSumTotal = findSquareSum(allPoints, n + q);
        cout << "Case #" << t1 << ": " << (distSumTotal - distSumWells - distSumTrees + 3 * MOD) % MOD << nl;
	}	
}