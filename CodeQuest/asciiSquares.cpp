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
bool arr[500][500];

int main() {
	freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		FOR(i, 0, 500) {
			FOR(j, 0, 500) {
				arr[i][j] = false;
			}
		}
		int n; cin >> n;
		string a;
		getline(std::cin, a);
		FOR(i, 0, n) {
			string s;
			getline(std::cin, s);
			if (i == 0) {
				FOR(j, 0, s.length()) {
					if (s[j] == '_') {
						arr[0][j/2] = true;
					}
					arr[0][(int)(((double)s.length() + 1)/2)] = true;
				}
			} else {
				for (int j = 0; j < s.length() - 2; j += 2) {
					if (s[j] == '|' && s[j + 1] == '_') {
						arr[i][j/2] = true;
					} else if (s[j] == ' ' && s[j + 1] == '_') {
						arr[i][j/2] = true;	
					} else if (j > 0 && s[j - 2] == '_' && s[j - 1] == ' ' && s[j] == ' ' && s[j + 1] == ' ') {
						arr[i][j/2] = true;
					}
				}
				if ((s[s.length() - 1] == '|' && s[s.length() - 2] == '_')) {
					arr[i][(s.length() - 1)/2] = true;
				} else if (s[s.length() - 1] == '_') {
					arr[i][(s.length() - 1)/2] = true;
					arr[i][(s.length())/2] = true;
				}
			}
		}
		FOR(i, 0, n) {
			FOR(j, 0, 15) {
				if (arr[i][j]) {
					cout << "A";
				} else {
					cout << " ";
				}
			}
			cout << nl;
		}
		int sqs = 0;
		FOR(i, 0, n) {
			FOR(j, 0, 200) {
				if (arr[i][j]) {
					for (int inc = 1; inc <= n + 5; inc++) {
						if (arr[i + inc][j + inc] && arr[i + inc][j] && arr[i][j + inc]) {
							sqs++;
						}
					}
				}
			}
		}
		cout << sqs << nl;
	}	
}
