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

int n, q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
    ll trustSum = 0;
    ll trusts[n];
    FOR(i, 0, n) {
        cin >> trusts[i];
        trustSum += trusts[i];
    }
    S0RT(trusts, n);
    int pointer = 0;
    ll subtractSum = 0;
    while (pointer < n && trusts[pointer] == 0) {
        pointer++;
    }
    ll prefixSums[n + 1];
    prefixSums[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        prefixSums[i] = prefixSums[i + 1] + trusts[i];
    }
	for (int i = 0; i < q; i++) {
        cout << n - pointer << " " << prefixSums[pointer] - subtractSum * (n - pointer) << nl;
        int num; cin >> num;
        subtractSum += num;
        while (pointer < n && trusts[pointer] <= subtractSum) {
            pointer++;
        }
	}
}
