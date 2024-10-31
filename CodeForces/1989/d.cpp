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

int n, m, k;

bool cmp(pii a, pii b) {
    if (a.pA == b.pA) {
        return a.pB < b.pB;
    }
    return a.pA < b.pA;
}

ll dp[1000005];
vector<pii> weaponsTemp;
vector<pii> weapons;

int weaponNum[1000005];

ll maxXp(int ingots) {
    if (ingots <= 0) {
        return 0;
    }
    if (dp[ingots] != -1) {
        return dp[ingots];
    }
    ll ans = 0;
    // speed this up by precomputing which weapon we should forge for each ingot count
    int weapon = weaponNum[ingots];
    if (weapon == -1) {
        return 0;
    }
    int ingotsOrig = ingots;
    int forges = int((ingots - weapons[weapon].pB) / weapons[weapon].pA);
    ingots -= forges * weapons[weapon].pA;
    if (ingots >= weapons[weapon].pB) {
        ingots -= weapons[weapon].pA;
        forges++;
    }
    ans = forges * 2 + maxXp(ingots);
    dp[ingotsOrig] = ans;
    return dp[ingotsOrig];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
    int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int c[m];
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        weaponsTemp.pb({a[i] - b[i], a[i]}); // cost to craft/melt, requirement to craft
    }
    sort(weaponsTemp.begin(), weaponsTemp.end(), cmp); // cost ascending, requirement ascending
    int ans = 0;
    sort(c, c + m);
    // clean up weapons array. for pairs x and y, if x.pA <= y.pA and x.pB <= y.pB, remove y
    // this is because if x is better than y in both aspects, then x is better than y
    // if x is better in one aspect and worse in the other, then keep both
    int minReq = 1e9;
    for (int i = 0; i < weaponsTemp.size(); i++) {
        if (weapons.empty() || weaponsTemp[i].pB < minReq) {
            weapons.pb(weaponsTemp[i]);
            minReq = min(minReq, weaponsTemp[i].pB);
        }
    }
    reverse(weapons.begin(), weapons.end());
    k = weapons.size();

    int currWeapon = -1;
    FOR(i, 0, 1e6 + 5) {
        if (currWeapon == k - 1) {
            weaponNum[i] = k - 1;
        }
        while (i >= weapons[currWeapon + 1].pB && currWeapon < k - 1) {
            currWeapon++;
        }
        weaponNum[i] = currWeapon;
    }

    // dp on the max experience we can get from each ingot count. we don't need to do dp on
    // ingot counts > 1e6 because the requirement for forging is at most 1e6, so we're gonna
    // forge the same weapon for everything greater than that
    ll totalXp = 0;

    FOR(i, 0, 1e6 + 5) {
        dp[i] = -1;
    }

    // cout << maxXp(9) << nl;

    FOR(i, 0, m) {
        ll xp = 0;
        if (c[i] > weapons[k - 1].pB) {
            int forges = int((c[i] - weapons[k - 1].pB) / weapons[k - 1].pA);
            xp += forges * 2;
            c[i] -= forges * weapons[k - 1].pA;
            if (c[i] > weapons[k - 1].pB) {
                xp += 2;
                c[i] -= weapons[k - 1].pA;
            }
        }
        xp += maxXp(c[i]);
        totalXp += xp;
    }

    cout << totalXp << nl;
}
