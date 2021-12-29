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

int n1, n2, m1, m2;

vector<int> adj1[1000];
vector<int> adj2[1000];

bool vis1[1000][2000]{};
bool vis2[1000][2000]{};

bool dp1[1000][2000]{};
bool dp2[1000][2000]{};

bool canReach1(int curr, int steps) {
	if (curr == n1 - 1) {
		return (steps == 0);
	} else if (steps < 0) {
		return false;
	} else if (vis1[curr][steps]) {
		return dp1[curr][steps];
	}
	for (int next : adj1[curr]) {
		if (canReach1(next, steps - 1)) {
			vis1[curr][steps] = true;
			dp1[curr][steps] = true;
			return true;
		}
	}
	vis1[curr][steps] = true;
	dp1[curr][steps] = false;
	return false;
}

bool canReach2(int curr, int steps) {
	if (curr == n2 - 1) {
		return (steps == 0);
	} else if (steps < 0) {
		return false;
	} else if (vis2[curr][steps]) {
		return dp2[curr][steps];
	}
	for (int next : adj2[curr]) {
		if (canReach2(next, steps - 1)) {
			vis2[curr][steps] = true;
			dp2[curr][steps] = true;
			return true;
		}
	}
	vis2[curr][steps] = true;
	dp2[curr][steps] = false;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n1 >> n2 >> m1 >> m2;
	for (int i = 0; i < m1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj1[a].pb(b);
	}
	for (int i = 0; i < m2; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj2[a].pb(b);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int steps;
		cin >> steps;
		for (int j = 0; j <= steps; j++) {
			if (canReach1(0, j) && canReach2(0, steps - j)) {
				cout << "Yes" << nl;
				break;
			} else if (j == steps) {
				cout << "No" << nl;
			}
		}
	}
}
