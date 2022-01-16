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
bool vis[10000];
int arr[10000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		FOR(i, 0, n) { vis[i] = false; }
		int cycleFront = 0;
		int prev = -1;
		set<int> curr;
		FOR(i, 0, n) { curr.insert(i); }
		while (curr.size() > 0) {
			int val = -1;
			if (prev == -1) {
				while (val != cycleFront) {
					cout << "? " << cycleFront + 1 << nl;
					cout.flush();
					cin >> val;
					val--;
				}
				vis[val] = true;
				prev = val;
			} else {
				cout << "? " << cycleFront + 1 << nl;
				cout.flush();
				cin >> val;
				val--;
				if (vis[val]) {
					arr[prev] = val;
					curr.erase(val);
					cycleFront = *(curr.begin());
					prev = -1;
					continue;
				}
				vis[val] = true;
				arr[prev] = val;
				curr.erase(val);
				prev = val;
			}
		}
		arr[prev] = cycleFront;
		cout << "! ";
		FOR(i, 0, n) { cout << arr[i] + 1 << " "; }
		cout << nl;
		cout.flush();
	}
}
