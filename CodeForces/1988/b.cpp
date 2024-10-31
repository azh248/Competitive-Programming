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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n; cin >> n;
        string a; cin >> a;
        int arr[n];
        FOR(i, 0, n) {
            arr[i] = a[i] - '0';
        }
        vector<int> clean;
        FOR(i, 0, n) {
            if (arr[i] == 0) {
                continue;
            } else {
                if (i > 0 && arr[i - 1] == 0) {
                    clean.pb(0);
                }
                clean.pb(1);
            }
        }
        if (arr[n - 1] == 0) {
            clean.pb(0);
        }
        int currOnes = 0;
        int currZeros = 0;
        int k = clean.size();
        FOR(i, 0, k) {
            if (clean[i] == 1) {
                currOnes++;
            } else {
                currZeros++;
            }
            if (currOnes == currZeros + 1 && currOnes != 1) {
                currOnes = 1;
                currZeros = 0;
            }
        }
        if (currZeros >= currOnes) {
            cout << "NO" << nl;
        } else {
            cout << "YES" << nl;
        }
        // int currOnes = 0;
        // int currZeros = 0;
        // FOR(i, 0, n) {
        //     if (arr[i] == 1) {
        //         currOnes++;
        //     } else {
        //         currZeros++;
        //         if (currZeros >= currOnes) {
        //             currZeros = 0;
        //             currOnes = 0;
        //         } else {
        //             currZeros--;
        //             currOnes++;
        //         }
        //     }
        // }
        // bool works = true;
        // for (int i = n - 1; i >= 0; i--) {
        //     if (arr[i] == 1) {
        //         currOnes++;
        //     } else {
        //         currZeros++;
        //         if (currZeros >= currOnes) {
        //             cout << "NO" << nl;
        //             works = false;
        //             break;
        //         } else {
        //             currZeros--;
        //             currOnes++;
        //         }
        //     }
        // }
        // if (works) {
        //     cout << "YES" << nl;
        // }
	}	
}
