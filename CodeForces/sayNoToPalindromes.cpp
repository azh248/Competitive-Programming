#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;
string s;
int sChars[200000];

int main() {
	// freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> s;	
	for (int i = 0; i < n; i++) {
		sChars[i] = s[i] - 'a';
	}
	// try all permutations of abc, since a non-palindromic string has to just be a permutation of abc repeated
	// then, we can just keep a psum of the total cost up to each index
	int costs[200000][6]; // psum for each permutation
	vector<int> abc;
	abc.pb(0);
	abc.pb(1);
	abc.pb(2);
	int permutationCounter = 0;
	do {
		costs[0][permutationCounter] = ((sChars[0] == abc[0]) ? 0 : 1);
		for (int i = 1; i < n; i++) {
			costs[i][permutationCounter] = ((sChars[i] == abc[i % 3]) ? 0 : 1) + costs[i - 1][permutationCounter];
		}
		permutationCounter++;
	} while (next_permutation(abc.begin(), abc.end()));
	for (int i = 0; i < m; i++) {
		int l, r; cin >> l >> r; l--; r--;
		int minCost = 1e9;
		for (int j = 0; j < 6; j++) {
			if (l == 0) {
				minCost = min(minCost, costs[r][j]);
			} else {
				minCost = min(minCost, costs[r][j] - costs[l - 1][j]);
			}
		}
		cout << minCost << nl;
	}
	// for (int i = 0; i < 6; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << costs[j][i] << " ";
	// 	}
	// 	cout << nl;
	// }
}