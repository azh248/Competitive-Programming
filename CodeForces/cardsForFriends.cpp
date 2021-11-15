#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 1000000007
#define nl "\n"
#define pub push_back
#define pob pop_back

int pow2(int num) {
	int ret = 0;
	while (num % 2 == 0) {
		ret++;
		num /= 2;
	}
	return ret;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
		int w, h, n;
		cin >> w >> h >> n;
		if (pow(2, (long)(pow2(w) + pow2(h))) >= n) {
			cout << "YES" << nl;
		} else {
			cout << "NO" << nl;
		}
    }
}
