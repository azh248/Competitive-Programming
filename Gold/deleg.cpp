/*
ID:azh248
LANG:C++
TASK:deleg 
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
vector<int> adj[100000];

vector<int> factor(int num) { // returns all factors
	vector<int> factors;
	for (int i = 1; i * i <= num; i++) {
		if (num % i == 0) {
			factors.pb(i);
			if (i != num / i) {
				factors.pb(num / i);
			}
		}
	}
	SORT(factors);
	reverse(factors.begin(), factors.end());
	return factors;
}

int dfs(int node, int len, int par) {
	vector<int> lens;
	for (int i : adj[node]) {
		if (i != par) {
			int num = dfs(i, len, node);
			if (num == -1) {
				return -1;
			}
			num %= len;
			if (num == 0) {
				continue;
			}
			lens.pb(num);
		}
	}
	SORT(lens);
	if (lens.size() % 2 == 0) {
		for (int i = 0; i < lens.size() / 2; i++) {
			if ((lens[i] + lens[lens.size() - 1 - i]) != len) {
				return -1;
			} 
		}
		if (node == 0) {
			return 0;
		}
		return 1;
	} else {
		if (lens.size() == 1) {
			if (node == 0) {
				return 0;
			}
			return (lens[0] + 1) % len;
		}
		bool works1 = true;
		bool works2 = true;
		int remainder1 = -1;
		int remainder2 = -1;
		int pointer1 = 0;
		int pointer2 = lens.size() - 1;
		while (pointer1 < pointer2) {
			if ((lens[pointer1] + lens[pointer2]) == len) {
				pointer1++;
				pointer2--;
				continue;
			} else {
				if (remainder1 != -1) {
					works1 = false;
					break;
				} else {
					remainder1 = lens[pointer1];
					pointer1++;
				}
			}
		}
		pointer1 = 0;
		pointer2 = lens.size() - 1;
		while (pointer1 < pointer2) {
			if ((lens[pointer1] + lens[pointer2]) == len) {
				pointer1++;
				pointer2--;
				continue;
			} else {
				if (remainder2 != -1) {
					works2 = false;
					break;
				} else {
					remainder2 = lens[pointer2];
					pointer2--;
				}
			}
		}
		if (remainder1 == -1 && remainder2 == -1) {
			if (node == 0) {
				return 0;
			}
			return (lens[lens.size() / 2] + 1) % len;
		}
		if (works1 || works2) {
			if (works1) {
				if (node == 0) {
					return 0;
				}
				return (remainder1 + 1) % len;
			} else if (works2) {
				if (node == 0) {
					return 0;
				}
				return (remainder2 + 1) % len;
			} 
		} else {
			return -1;
		}
	}
	return -1;
}

bool arr[100000];

int main() {
	freopen("deleg.in", "r", stdin);
	freopen("deleg.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i : factor(n - 1)) {
		if (arr[i] == 1) {
			continue;
		}
		int num = dfs(0, i, -1);
		if (num % i == 0) {
			arr[i] = 1;
			for (int j : factor(i)) {
				arr[j] = 1;
			}
		}
	}
	for (int i = 1; i < n; i++) {
		cout << (arr[i] ? 1 : 0);
	}
	cout << nl;
}
