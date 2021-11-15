#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back
#define long long long

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int tcaseNum = 0; tcaseNum < t; tcaseNum++) {
		int n; 
		cin >> n;
		string b;
		cin >> b;
		string a = "";
		string d = "";
		for (int i = 0; i < n; i++) {
			int num = stoi(string(1, b[i])); 
			if (a.empty()) {
				a += to_string(1);
				d += to_string(num + 1);
			} else {
				int prevNum = stoi(string(1, d[i - 1]));
				if (num == prevNum - 1) {
					a += to_string(0);
					d += to_string(num);
				} else if (num == prevNum - 2) {
					a += to_string(1);
					d += to_string(num + 1);
				} else if (num == prevNum) {
					a += to_string(1);
					d += to_string(num + 1);
				} else if (num == prevNum + 1) {
					a += to_string(1);
					d += to_string(num + 1);
				}
			}
		}
		cout << a << nl;
	}
}
