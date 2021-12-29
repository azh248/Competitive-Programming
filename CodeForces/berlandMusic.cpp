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
int arr[200000];
int newArr[200000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		FOR(i, 0, n) { cin >> arr[i]; }
		string s;
		cin >> s;
		ll cost = 0;
		vector<pii> ones;
		int curr = n;
		FOR(i, 0, n) {
			if (s[i] == '1') {
				ones.pb(pii(arr[i], i));
				curr--;
			}
		}
		SORT(ones);
		for (pii i : ones) {
			newArr[i.second] = curr++;
		}
		vector<pii> zeroes;
		FOR(i, 0, n) {
			if (s[i] == '0') {
				zeroes.pb(pii(arr[i], i));
			}
		}
		SORT(zeroes);
		int curr1 = 0;
		for (pii i : zeroes) {
			newArr[i.second] = curr1++;
		}
		FOR(i, 0, n) { cout << newArr[i] + 1 << " "; }
		cout << nl;
	}
}
