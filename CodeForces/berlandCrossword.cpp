#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n, u, r, d, l;	
		cin >> n >> u >> r >> d >> l;
		bool works = false;
		for (int a = 0; a < 2; a++) {
			for (int b = 0; b < 2; b++) {
				for (int c = 0; c < 2; c++) {
					for (int e = 0; e < 2; e++) {
						if (works) {
							break;
						}
						int u1 = u;
						int r1 = r;
						int d1 = d;
						int l1 = l;
						if (a == 1) {
							u1--;
							l1--;
						} 
						if (b == 1) {
							u1--;
							r1--;
						} 
						if (c == 1) {
							r1--;
							d1--;
						}
						if (e == 1) {
							d1--;
							l1--;
						}
						if (u1 <= n - 2 && u1 >= 0 && r1 <= n - 2 && r1 >= 0 && d1 <= n - 2 && d1 >= 0 && l1 <= n - 2 && l1 >= 0) {
							works = true;
							break;
						}
					}
				}
			}
		}
		cout << (works ? "YES" : "NO") << nl;
	}	
}
