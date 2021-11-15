#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;

bool swamp[200][200]{};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("fortmoo.in", "r", stdin);
	freopen("fortmoo.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'X') {
				swamp[i][j] = true;
			}
		}
	}	
	int pre[200][200]; // pre[i][j] = number of blank spaces since the previous swampy spot in column j up to row i

	for (int j = 0; j < m; j++) {
		pre[0][j] = (swamp[0][j]) ? 0 : 1;
		for (int i = 1; i < n; i++) {
			pre[i][j] = (swamp[i][j]) ? 0 : (pre[i - 1][j] + 1);
		}
	}

	int maxArea = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) { // all possible vertical sliding windows
			int left = 0;
			int right = 1;
			while (right < m) {
				if (pre[j][left] <= j - i) {
					left++;
					right = max(right, left);
				} else if (pre[j][right] > j - i) {
					maxArea = max(maxArea, (j - i + 1) * (right - left + 1));
				} else if (pre[j][right] == 0) {
					left = right + 1;
					right = left;
				}
				right++;
			}
		}
	}	
	cout << maxArea << nl;
}
