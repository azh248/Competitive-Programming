/*
ID:azh248
LANG:C++
TASK:mincross 
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
int s[100005]; // breed at position i on left side
int s2[100005];
int pos2[100005]; // breed at position i on left side
int pos[100005];

int BIT1[100000];

void update1(int ind, int val) {
	while (ind <= n) {
		BIT1[ind] += val;
		ind += (ind & -ind);
	}
}

int get1(int ind) {
	int ret = 0;
	while (ind > 0) {
		ret += BIT1[ind];
		ind -= (ind & -ind);
	}
	return ret;
}

int main() {
	freopen("mincross.in", "r", stdin);
	freopen("mincross.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		pos2[s[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> s2[i];
		pos[s2[i]] = i;
	}

	// do algorithm with s andpos1 
	ll crossings1 = 0;
	ll crossings2 = 0;
	for (int i = 1; i <= n; i++) {
		int num = get1(pos[s[i]]);
		int num1 = i - 1 - num;
		update1(pos[s[i]], 1);
		crossings2 += num1;
	}
	crossings1 = crossings2;
	ll minCrossingsOverall = min(crossings1, crossings2);
	for (int i = n; i > 1; i--) {
		int front1 = pos[s[i]];
		int front2 = pos2[s2[i]];
		crossings1 += front1;
		crossings1 -= (n - front1 + 1);
		crossings2 += front2;
		crossings2 -= (n - front2 + 1);
		minCrossingsOverall = min(minCrossingsOverall, crossings1);
		minCrossingsOverall = min(minCrossingsOverall, crossings2);
	}
	cout << minCrossingsOverall << nl;
}
