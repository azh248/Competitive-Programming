#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	string s;
	cin >> s;
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (s[i] == s[j]) {
				count++;
			}
		}
	}	
	cout << count << nl;
}
