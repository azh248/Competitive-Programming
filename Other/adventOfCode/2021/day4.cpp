#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define pA first
#define pB second
#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
int boards[1000][5][5];
bool marked[1000][5][5]{};

int main() {
	freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int ind = 0;
	int var;
	while (cin >> var) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (i == 0 && j == 0) {
					boards[ind][0][0] = var;
				} else {
					cin >> boards[ind][i][j];
				}
			}
		}
		ind++;
	}
	set<int> working;
	for (int i = 0; i < s.length(); i += 3) {
		int num = 10 * (s[i] - '0') + (s[i + 1] - '0');
		cout << num << " ";
		for (int j = 0; j < ind; j++) {
			for (int k = 0; k < 5; k++) {
				for (int l = 0; l < 5; l++) {
					if (boards[j][k][l] == num) {
						marked[j][k][l] = true;
					}
				}
			}
			for (int k = 0; k < 5; k++) {
				bool works = true;
				for (int l = 0; l < 5; l++) {
					if (!marked[j][k][l]) {
						works = false;
					}
				}
				if (works) {
					working.insert(j);
				}
				if (working.size() == ind) {
					int unmarked = 0;
					cout << nl;
					for (int n = 0; n < 5; n++) {
						for (int m = 0; m < 5; m++) {
							if (!marked[j][n][m]) {
								unmarked += boards[j][n][m];
							}
							cout << boards[j][n][m] << " ";
						}
						cout << nl;
					}
					cout << num * unmarked << nl;
					return 0;
				}
			}
			for (int k = 0; k < 5; k++) {
				bool works = true;
				for (int l = 0; l < 5; l++) {
					if (!marked[j][l][k]) {
						works = false;
					}
				}
				if (works) {
					working.insert(j);
				}
				if (working.size() == ind) {
					int unmarked = 0;
					for (int n = 0; n < 5; n++) {
						for (int m = 0; m < 5; m++) {
							if (!marked[j][n][m]) {
								unmarked += boards[j][n][m];
							}
						}
					}
					cout << num * unmarked << nl;
					return 0;
				}
			}
		}
	}
}