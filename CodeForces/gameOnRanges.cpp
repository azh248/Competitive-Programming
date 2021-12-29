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

bool cmp(vector<int> a, vector<int> b) {
	if ((a[1] - a[0]) == (b[1] - b[0])) {
		return (a[0] < b[0]);
	} else {
		return ((a[1] - a[0]) > (b[1] - b[0]));
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> arr[1000];
		pii origArr[1000];
		FOR(i, 0, n) {
			vector<int> temp(3);
			cin >> temp[0] >> temp[1];
			origArr[i].pA = temp[0];
			origArr[i].pB = temp[1];
			temp[0]--;
			temp[1]--;
			temp[2] = i;
			arr[i] = temp;
		}
		sort(arr, arr + n, cmp);
		int removed[1000]; // number that was chosen at each range
		FOR(i, 0, n) {
			int lastAppearance = -1; // place before this number disappeared since Bob chose it
			FOR(j, 0, n) {
				if (i >= arr[j][0] && i <= arr[j][1]) {
					lastAppearance = max(lastAppearance, j);
				}
			}
			removed[arr[lastAppearance][2]] = i;
		}
		FOR(i, 0, n) {
			cout << origArr[i].pA << " " << origArr[i].pB << " " << removed[i] + 1 << nl;
		}
		cout << nl;
	}
}
