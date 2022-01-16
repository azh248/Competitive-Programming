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
int n, m;
vector<int> seq2[10][10]; // [i][j] = whether a phone substring {i, j} exists; if so the l, r, i
vector<int> seq3[10][10][10]; // [i][j][k] = whether a phone substring {i, j, k} exists; if so the l, r, i

int dp[1000];
int nextInd[1000];
vector<int> segment[1000];
int arr[1000];

bool canSplit(int ind) {
	if (ind >= m){
		return true;
	} if (dp[ind] != -1) {
		return dp[ind];
	} else if (ind == m - 1) {
		return false;
	}
	if (seq2[arr[ind]][arr[ind + 1]][0] != -1 && canSplit(ind + 2)) {
		nextInd[ind] = ind + 2;
		segment[ind] = seq2[arr[ind]][arr[ind + 1]];
	} else if (ind < m - 2 && seq3[arr[ind]][arr[ind + 1]][arr[ind + 2]][0] != -1 && canSplit(ind + 3)) {
		nextInd[ind] = ind + 3;
		segment[ind] = seq3[arr[ind]][arr[ind + 1]][arr[ind + 2]];
	} else {
		dp[ind] = 0;
		return false;
	}
	dp[ind] = 1;
	return true;
}

int main() {
	// freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		FOR(i, 0, 10) {
			FOR(j, 0, 10) {
				seq2[i][j] = {-1};
				FOR(k, 0, 10) {
					seq3[i][j][k] = {-1};
				}
			}
		}
		memset(dp, -1, sizeof(dp));
		FOR(i, 0, n) {
			// take consecutive indices in the number and update seq2 and seq3 accordingly
			string s;
			cin >> s;
			FOR(j, 0, m - 2) {
				seq2[s[j] - '0'][s[j + 1] - '0'] = {j, j + 1, i};
				seq3[s[j] - '0'][s[j + 1] - '0'][s[j + 2] - '0'] = {j, j + 2, i};
			}
			seq2[s[m - 2] - '0'][s[m - 1] - '0'] = {m - 2, m - 1, i};
		}
		string s;
		cin >> s;
		FOR(i, 0, m) { arr[i] = s[i] - '0'; }
		if (!canSplit(0)) {
			cout << -1 << nl;
		} else {
			vector<vector<int>> segments;
			int curr = 0;
			while (curr != m) {
				segments.pb(segment[curr]);
				curr = nextInd[curr];
			}
			cout << segments.size() << nl;
			for (vector<int> i : segments) {
				cout << i[0] + 1 << " " << i[1] + 1 << " " << i[2] + 1 << nl;
			}
		}
	}
}
