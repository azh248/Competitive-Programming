/*
ID:azh248
LANG:C++
TASK:circlecross 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
int BIT[100005]; // 1-indexed
int r[100005];
int l[100005];
bool vis[100005];

// update prefix sums at a specified index and add a value
void update(int ind, int val) {
	ind++; // makes it 1-indexed
	while (ind <= 2 * n) {
		BIT[ind] += val;
		ind += (ind & -ind); // makes it so that ind is now the next node responsible for our updated one
	}
}

int query(int ind) {
	ind++; // makes it 1-indexed
	int ret = 0;
	while (ind > 0) {
		ret += BIT[ind];
		ind -= (ind & -ind); // repeatedly remove last "1" bit; all of these nodes make up our query 
	}
	return ret;
}


int main() {
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> ids(2 * n);
	memset(l, -1, sizeof(l));
	for (int i = 0; i < 2 * n; i++) {
		cin >> ids[i];
		if (l[ids[i]] == -1) {
			l[ids[i]] = i;
		} else {
			r[ids[i]] = i;
		}
	}
	ll totalCrossing = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (!vis[ids[i]]) {
			vis[ids[i]] = true;
			totalCrossing += query(r[ids[i]]) - query(l[ids[i]] - 1);
			update(r[ids[i]], 1);
		} else {
			update(r[ids[i]], -1);
		}
	}
	cout << totalCrossing << nl;
}