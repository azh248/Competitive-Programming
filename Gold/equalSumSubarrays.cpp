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
ll arr[505];
ll pre[505];
pair<ll, pair<int, int>> preDiff[255000];
ll minDiff[505];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
        cin >> arr[i];
	}
    pre[0] = 0;
    for (int i = 0; i < n; i++) {
        pre[i + 1] = arr[i];
        pre[i + 1] += pre[i];
    }
    int cnt = 0;
    for (int i = 0; i < n + 1; i++) {
        for (int j = i + 1; j < n + 1; j++) {
            preDiff[cnt++] = pair<ll, pii>(pre[j] - pre[i], pii(i, j));
        }
    }
    sort(preDiff, preDiff + cnt);

    for (int i = 0; i < n + 1; i++) {
        minDiff[i] = 1e18;
    }

    for (int i = preDiff[0].pB.pA + 1; i <= preDiff[0].pB.pB; i++) {
        if (i > preDiff[1].pB.pB || i < preDiff[1].pB.pA + 1) {
            minDiff[i] = preDiff[1].pA - preDiff[0].pA;
        }
    }
    // for (int i = 0; i < cnt - 1; i++) {
    //     for (int j = preDiff[i + 1].pB.pA + 1; j <= preDiff[i + 1].pB.pB; j++) {
    //         if (j > preDiff[i].pB.pB || j < preDiff[i].pB.pA + 1) {
    //             minDiff[j] = min(minDiff[j], preDiff[i + 1].pA - preDiff[i].pA);
    //         }
    //     }
    // }
    for (int i = 0; i < cnt; i++) {
        for (int k = i + 1; k < min(i + 5, cnt); k++) {
            for (int j = preDiff[k].pB.pA + 1; j <= preDiff[k].pB.pB; j++) {
                if (j > preDiff[i].pB.pB || j < preDiff[i].pB.pA + 1) {
                    minDiff[j] = min(minDiff[j], preDiff[k].pA - preDiff[i].pA);
                }
            }
            for (int j = preDiff[i].pB.pA + 1; j <= preDiff[i].pB.pB; j++) {
                if (j > preDiff[k].pB.pB || j < preDiff[k].pB.pA + 1) {
                    minDiff[j] = min(minDiff[j], preDiff[k].pA - preDiff[i].pA);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << minDiff[i] << nl;
    }
}
