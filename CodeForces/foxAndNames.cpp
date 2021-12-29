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
vector<int> adj[26];
int topo[26]{};
int curr;
bool topovis[26]{};
bool onStack[26]{};
stack<int> currCycle;

bool topodfs(int node) { // returns whether there's a cycle
	topovis[node] = onStack[node] = true;
	for (int next : adj[node]) {
		if (onStack[next]) {
			return true;
		} else if (!topovis[next]) {
			if (topodfs(next)) {
				return true;
			}
		}
	}
	onStack[node] = false;
	topo[--curr] = node;
	return false;
}

bool toposort() {
	curr = 26;
	for (int i = 0; i < 26; i++) {
		if (!topovis[i]) {
			if (topodfs(i)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	string currStr;
	cin >> currStr;
	for (int i = 1; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < min(currStr.length(), s.length()); j++) {
			if (currStr[j] == s[j]) {
				if (j == min(currStr.length(), s.length()) - 1) {
					if (currStr.length() > s.length()) {
						cout << "Impossible" << nl;
						return 0;
					}
				}
			} else {
				adj[currStr[j] - 'a'].pb(s[j] - 'a');
				break;
			}
		}
		currStr = s;
	}
	if (toposort()) {
		cout << "Impossible" << nl;
		return 0;
	}
	for (int i = 0; i < 26; i++) {
		cout << ((char)(topo[i] + 97));
	}
	cout << nl;
}
