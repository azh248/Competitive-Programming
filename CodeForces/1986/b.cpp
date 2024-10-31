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
		int n, m; cin >> n >> m;
        ll arr[n][m];
        F0R(i, n) {
            F0R(j, m) {
                cin >> arr[i][j];
            }
        }
        ll newArr[n][m];
        F0R(i, n) {
            F0R(j, m) {
                // check if currnet element is greater than all neighboring elements
                bool isGreater = true;
                ll maxElement = 0;
                if (i > 0) {
                    maxElement = max(maxElement, arr[i - 1][j]);
                    if (arr[i][j] <= arr[i - 1][j]) {
                        isGreater = false;
                    }
                }
                if (i < n - 1) {
                    maxElement = max(maxElement, arr[i + 1][j]);
                    if (arr[i][j] <= arr[i + 1][j]) {
                        isGreater = false;
                    }
                }
                if (j > 0) {
                    maxElement = max(maxElement, arr[i][j - 1]);
                    if (arr[i][j] <= arr[i][j - 1]) {
                        isGreater = false;
                    }
                }
                if (j < m - 1) {
                    maxElement = max(maxElement, arr[i][j + 1]);
                    if (arr[i][j] <= arr[i][j + 1]) {
                        isGreater = false;
                    }
                }
                if (isGreater) {
                    newArr[i][j] = maxElement;
                } else {
                    newArr[i][j] = arr[i][j];
                }
            }
        }
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                cout << newArr[i][j] << " ";
            }
            cout << nl;
        }
	}	
}
