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

int n, m;
vector<int> adj[300000];
bool topovis[300000]{};
bool onStack[300000]{};

bool topodfsCycle(int node) { // returns whether there's a cycle
	topovis[node] = onStack[node] = true;
	for (int next : adj[node]) {
		if (onStack[next]) {
			return true;
		} else if (!topovis[next]) {
			if (topodfsCycle(next)) {
				return true;
			}
		}
	}
	onStack[node] = false;
	return false;
}

bool toposortCycle() {
	for (int i = 0; i < n; i++) {
		if (!topovis[i]) {
			if (topodfsCycle(i)) {
				return true;
			}
		}
	}
	return false;
}

int dp[300000][26]; // dp[i][j] = max number of letter j
int letter[300000];

int maxCnt(int node, int focusLetter) {
	if (dp[node][focusLetter] != -1) {
		return dp[node][focusLetter];
	}
	int cnt = 0;
	for (int next : adj[node]) {
		cnt = max(cnt, maxCnt(next, focusLetter));
	}
	if (letter[node] == focusLetter) {
		cnt++;
	}
	dp[node][focusLetter] = cnt;
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	string s;
	cin >> s; 
	for (int i = 0; i < n; i++) {
		letter[i] = s[i] - 'a';
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
	}
	if (toposortCycle()) {
		cout << -1 << nl;
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	int val = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			val = max(val, maxCnt(i, j));
		}
	}
	cout << val << nl;
}
