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

int t, n;
ll k;
ll arr[200000];
ll arr1[200000];
ll reversePsums[200000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		ll arrSum = 0;
		FOR(i, 0, n) {
			cin >> arr[i];
			arr1[i] = arr[i];
			arrSum += arr[i];
		}
		if (arrSum <= k) {
			cout << 0 << nl;
			continue;
		}
		S0RT(arr1, n);
		reverse(arr1, arr1 + n);
		reversePsums[0] = arr1[0];
		FOR(i, 1, n) {
			reversePsums[i] = reversePsums[i - 1] + arr1[i];
		}
		ll minNum = arr1[n - 1];
		ll minSteps = (arrSum - k);
		FOR(i, 0, n - 1) {
			// take the minimum number, then find how many times you need to subtract 1 from it
			// to make it so that the array sum is <= k when you set the biggest (i + 1) numbers
			// to the minimum number
			ll currSteps = i + 1; // set all numbers from 0 to i to the smallest number after subtracting
			ll newMinNum;
			if (((k - arrSum + reversePsums[i] + minNum) % (i + 2)) == 0) {
				newMinNum = ((k - arrSum + reversePsums[i] + minNum) / (i + 2));
			} else {
				newMinNum = floor(((double)(k - arrSum + reversePsums[i] + minNum))/((double)(i + 2)));
			}
			if (newMinNum > minNum) {
				newMinNum = minNum;
			}
			currSteps += minNum - newMinNum;
			minSteps = min(minSteps, currSteps);
		}
		cout << minSteps << nl;
	}
}
