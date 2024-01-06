#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pli = pair<ll, int>;

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
#define nl "\n"
#define pb push_back

int n;
ll h[2005];
multiset<pli> slopes[2005];
bool sees[2005][2005];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out1.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
        cin >> h[i];
	}	
    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
        }
    }
    int visibleSum = 0;
    // find initial sum of visibles
    FOR(i, 0, n) {
        ll maxSlope = -1e18;
        FOR(j, i + 1, n) {
            ll newSlope = (ll)(((double)(h[j] - h[i]) / (j - i)) * 1e8);
            bool canSee = false;
            if (newSlope >= maxSlope) {
                maxSlope = newSlope;
                visibleSum++;
                canSee = true;
            }
            slopes[i].insert({newSlope, j});
            sees[i][j] = canSee;
        }
    }

    int q;
    cin >> q;

    bool couldSee[2005];
    bool canSee[2005];
    FOR(i, 0, q) {
        int a;
        ll b;
        cin >> a >> b;
        a--;
        // cout << visibleSum << nl;

        // update all the mountains to the left who can now see this mountain

        // remove all the mountains to the left that could see this mountain before
        ll reverseMaxSlope = 1e18;
        for (int j = a - 1; j >= 0; j--) {
            ll newSlope = (ll)(((double)(h[a] - h[j]) / (a - j))*1e8);
            if (newSlope <= reverseMaxSlope) {
                visibleSum--;
                reverseMaxSlope = newSlope;
                couldSee[j] = true;
            } else {
                couldSee[j] = false;
            }
        }
        // cout << visibleSum << nl;

        // add all the mountains to the left that can now see this mountain
        h[a] += b;
        reverseMaxSlope = 1e18;
        for (int j = a - 1; j >= 0; j--) {
            ll newSlope = (ll)(((double)(h[a] - h[j]) / (a - j))*1e8);
            if (newSlope <= reverseMaxSlope) {
                visibleSum++;
                reverseMaxSlope = newSlope;
                canSee[j] = true;
            } else {
                canSee[j] = false;
            }
        }
        h[a] -= b;

        // update all the mountains that had visibility to a mountain after this one blocked by this mountain

        FOR(j, 0, a) {
            ll currSlope = (ll)(((double)(h[a] - h[j]) / (a - j))*1e8);
            auto it = slopes[j].find({currSlope, a});
            ll newSlope = ((double)(h[a] + b - h[j]) / (a - j))*1e8;
            it++;
            while (it != slopes[j].end()) {
                if ((*it).pA < newSlope && (*it).pB > a && sees[j][(*it).pB]) { // mountain j can no longer see past the mountain at it because it's blocked by mountain a
                    visibleSum--;
                    sees[j][(int)(*it).pB] = false;
                    it++;
                } else if ((*it).pA >= newSlope) {
                    break;
                } else {
                    it++;
                }
            }

            slopes[j].erase(slopes[j].find({currSlope, a})); // might not have to do this again -- can optimize
            slopes[j].insert({newSlope, a});
            sees[j][a] = canSee[j];
        }
        // cout << visibleSum << nl;


        // update all the mountains to the right that this mountain can now see

        // remove all the mountains to the right that this mountain could see before
        ll maxSlopeUpdatedMountain = -1e18;
        FOR(j, a + 1, n) {
            ll newSlope = (ll)(((double)(h[j] - h[a]) / (j - a))*1e8);
            if (newSlope >= maxSlopeUpdatedMountain) {
                visibleSum--;
                maxSlopeUpdatedMountain = newSlope;
            }
        }
        // cout << visibleSum << nl;

        // add all the mountains to the right that this mountain can now see
        slopes[a].clear();
        maxSlopeUpdatedMountain = -1e18;
        h[a] += b;
        FOR(j, a + 1, n) {
            ll newSlope = (ll)(((double)(h[j] - h[a]) / (j - a))*1e8);
            // how to update the # of mountains this mountain can now see?
            bool canSee = false;
            if (newSlope >= maxSlopeUpdatedMountain) {
                visibleSum++;
                maxSlopeUpdatedMountain = newSlope;
                canSee = true;
            }
            slopes[a].insert({newSlope, j});
            sees[a][j] = canSee;
        }
        cout << visibleSum << nl;
        // cout << nl;
    }
}
