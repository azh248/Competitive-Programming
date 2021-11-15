#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 1000000007
#define nl "\n"
#define pub push_back
#define pob pop_back

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int twoCount = 0;
		int oneCount = 0;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (num == 1) {
				oneCount++;
			} else {
				twoCount++;
			}
		}
		if ((twoCount % 2 == 0 && oneCount % 2 == 0) || (twoCount % 2 == 1 && oneCount % 2 == 0 && oneCount >= 2)) {
			cout << "YES" << nl;
		} else {
			cout << "NO" << nl;
		}
	}
}
