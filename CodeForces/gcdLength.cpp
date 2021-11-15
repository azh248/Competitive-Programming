#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;
 
#define MOD 1000000007
#define nl "\n"
#define pb push_back
 
int t;

int powAB(int a, int b) {
	int ret = 1;
	for (int i = 0; i < b; i++) {
		ret *= a;
	}
	return ret;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		int numA = powAB(10, c - 1);	
		while (log10(numA) + 1 < a) {
			numA *= 2;
		}
		int numB = (powAB(10, b - c) + 1) * powAB(10, c - 1);
		cout << numA << " " << numB << nl;
	}	
}