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
	int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
	cout << (b2 - a2)/(b1 - a1) << nl;
}