/*
ID:
LANG:C++
TASK:sleepy 
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
int arr[100000];
int BIT[100000];

void update(int ind, int val) {
	ind++;
	while (ind <= n) {
		BIT[ind] += val;
		ind += (ind & -ind);
	}
}

int get(int ind) {
	ind++;
	int ret = 0;
	while (ind > 0) {
		ret += BIT[ind];
		ind -= (ind & -ind);
	}
	return ret;
}

int main() {
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i]--;
	}
	set<int> suffix;
	int prev = n + 1;
	int last;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] < prev) {
			suffix.insert(arr[i]);
			update(arr[i], 1);
			prev = arr[i];
			last = i;
		} else {
			break;
		}
	}
	cout << last << nl;
	for (int i = 0; i < last; i++) {
		int num = last - 1 - i;
		num += get(arr[i]);
		update(arr[i], 1);
		if (i != last - 1) {
			cout << num << " ";
		} else {
			cout << num;
		}
		suffix.insert(arr[i]);
	}
	cout << nl;
}
