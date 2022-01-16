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

int main() {
	freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll x = 0;
	ll y = 0;
	ll aim = 0;
	string s;
	int num;
	while (cin >> s >> num) {
		if (s == "forward") {
			x+=num;
			aim += y * num;
		} else if (s == "down") {
			y+=num;
		} else {
			y-=num;
		}
	}
	cout << (x * aim) << nl;
}