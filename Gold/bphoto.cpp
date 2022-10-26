/*
ID:azh248
LANG:C++
TASK:bphoto 
*/

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

int n;

int BITL[100001];

void updateL(int ind, int val) {
	ind++;
	while (ind <= n) {
		BITL[ind] += val;
		ind += (ind & -ind);
	}
}

int getL(int ind) {
	ind++;
	int ret = 0;
	while (ind > 0) {
		ret += BITL[ind];
		ind -= (ind & -ind);
	}
	return ret;
}

int BITR[100001];

void updateR(int ind, int val) {
	ind++;
	while (ind <= n) {
		BITR[ind] += val;
		ind += (ind & -ind);
	}
}

int getR(int ind) {
	ind++;
	int ret = 0;
	while (ind > 0) {
		ret += BITR[ind];
		ind -= (ind & -ind);
	}
	return ret;
}

vector<pii> heights;
int ind[100001];

int main() {
	freopen("bphoto.in", "r", stdin);
	freopen("bphoto.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		updateR(i, 1);
		int num;
		cin >> num;
		heights.pb({num, i});
	}
	SORT(heights);
	reverse(heights.begin(), heights.end());
	FOR(i, 0, n) { ind[heights[i].pB] = i; }
	int cnt = 0;
	FOR(i, 0, n) {
		updateR(ind[i], -1);
		if ((getL(ind[i]) == 0 && getR(ind[i]) != 0) || ((((double)(getR(ind[i])) / getL(ind[i])) > 2) || (((double)(getR(ind[i])) / getL(ind[i])) < 0.5))) {
			cnt++;
		}
		updateL(ind[i], 1);
	}
	cout << cnt << nl;
}
