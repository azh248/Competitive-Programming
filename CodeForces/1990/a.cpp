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
        int arr[n];
        FOR(i, 0, n) {
            cin >> arr[i];
        }
        sort(arr, arr + n, greater<int>());
        int currNum = arr[0];
        int currCount = 1;
        bool works = false;
        FOR(i, 1, n) {
            if (arr[i] == currNum) {
                currCount++;
            } else {
                if (currCount % 2 == 1) {
                    cout << "YES" << nl;
                    works = true;
                    break;
                }
                currNum = arr[i];
                currCount = 1;
            }
        }
        if (!works) {
            if (currCount % 2 == 1) {
                cout << "YES" << nl;
            } else {
                cout << "NO" << nl;
            }
        }
	}	
}
