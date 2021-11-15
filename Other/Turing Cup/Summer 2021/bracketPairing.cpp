#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, p;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> p;
	cin >> s;
	multiset<int> positions;
	int pairs[100000];
	for (int i = 0; i < n; i++) {
		if (s[i] == '{') {
			positions.insert(i);
		} else {
			int num = *--positions.end();
			pairs[num] = i;
			pairs[i] = num;
			positions.erase(--positions.end());
		}
	}
	cout << pairs[p - 1] + 1 << nl;
}