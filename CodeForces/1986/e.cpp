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
#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

bool cmp(pii a, pii b) {
    if (a.pB == b.pB) {
        return a.pA < b.pA;
    }
    return a.pB < b.pB;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
        ll arr[n];
        F0R(i, n) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        vector<pii> arr1;
        FOR(i, 0, n) {
            if (i == n - 1) {
                arr1.pb(pii(arr[i], arr[i] % k));
                continue;
            } else if (arr[i] == arr[i + 1]) {
                i++;
                continue;
            } else {
                arr1.pb(pii(arr[i], arr[i] % k));
            }
        }
        sort(arr1.begin(), arr1.end(), cmp);
        ll sum = 0;
        bool worked = true;
        bool single = false;
        if (n % 2 == 0) { // deactivate single failsafe if n is even
            single = true;
        }
        ll currDig = -1;
        ll oddDig = -1;
        ll cnt = 0;
        int delInd = -1;
        if (n % 2 == 1) {
            FOR(i, 0, arr1.size() + 1) {
                if (i == 0) {
                    cnt = 1;
                    currDig = arr1[i].pB;
                } else if ((i == arr1.size() || arr1[i].pB != currDig) && cnt % 2 == 1) {
                    if (delInd != -1) {
                        cout << -1 << nl;
                        worked = false;
                        break;
                    }
                    oddDig = arr1[i - 1].pB;
                    if (cnt == 1) {
                        delInd = i - 1;
                        cnt = 1;
                        currDig = arr1[i].pB;
                        continue;
                    }
                    ll prefixDiffs[n + 2];
                    ll suffixDiffs[n + 2];
                    F0R(j, n + 2) {
                        prefixDiffs[j] = 0;
                        suffixDiffs[j] = 0;
                    }
                    int ind1 = i - cnt;
                    int ind2 = i - 1;
                    suffixDiffs[ind2 + 1] = 0;
                    for (int j = ind2 - 1; j >= ind1; j -= 2) {
                        suffixDiffs[j] = abs((arr1[j + 1].pA - arr1[j].pA)/k) + suffixDiffs[j + 2];
                    }
                    prefixDiffs[ind1 + 1] = (abs(arr1[ind1 + 1].pA - arr1[ind1].pA))/k;
                    for (int j = ind1 + 3; j < ind2; j += 2) {
                        prefixDiffs[j] = abs((arr1[j].pA - arr1[j - 1].pA)/k) + prefixDiffs[j - 2];
                    }
                    ll minSum = 1e18;

                    // cout << "prefix diffs: " << ind1 << " " << ind2 << nl;
                    // FOR(j, ind1, ind2 + 1) {
                    //     cout << prefixDiffs[j] << " ";
                    // }
                    // cout << nl;
                    // cout << "suffix diffs: " << ind1 << " " << ind2 << nl;
                    // FOR(j, ind1, ind2 + 1) {
                    //     cout << suffixDiffs[j] << " ";
                    // }
                    // cout << nl;

                    for (int j = ind1; j <= ind2; j += 2) {
                        if (j == ind1) {
                            if (suffixDiffs[j + 1] < minSum) {
                                delInd = j;
                                minSum = suffixDiffs[j + 1];
                            }
                        } else if (j == ind2) {
                            if (prefixDiffs[j - 1] < minSum) {
                                delInd = j;
                                minSum = prefixDiffs[j - 1];
                            }
                        } else {
                            if (prefixDiffs[j - 1] + suffixDiffs[j + 1] < minSum) {
                                delInd = j;
                                minSum = prefixDiffs[j - 1] + suffixDiffs[j + 1];
                            }
                        }
                    }
                    currDig = arr1[i].pB;
                    cnt = 1;
                } else if (arr1[i].pB != currDig) {
                    cnt = 1;
                    currDig = arr1[i].pB;
                } else {
                    cnt++;
                }
            }
        }
        // cout << "del dig: " << delInd << " " << arr1[delInd].pA << nl;
        if (!worked) {
            continue;
        }
        FOR(i, 0, arr1.size()) {
            if (i == delInd) {
                continue;
            } else if (i == arr1.size() - 1) {
                cout << -1 << nl;
                worked = false;
                break;
            }
            if (i + 1 == delInd) {
                if (arr1[i].pB == arr1[i + 1].pB && arr1[i].pB == arr1[i + 2].pB) {
                    sum += abs((arr1[i + 2].pA - arr1[i].pA) / k);
                    i += 2;
                    continue;
                } else {
                    cout << -1 << nl;
                    worked = false;
                    break;
                }
            }
            if (arr1[i].pB == arr1[i + 1].pB) {
                sum += abs((arr1[i + 1].pA - arr1[i].pA) / k);
                i++;
            } else {
                cout << -1 << nl;
                worked = false;
                break;
            }
        }
        if (!worked) {
            continue;
        }
        cout << sum << nl;
	}	
}
