#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	int l = 1;
	int r = n;
	cout << "? " << l << " " << r << nl;
	cout.flush();
	int max;
	int leftMax;
	int rightMax;
	cin >> max;
	while (r - l > 1) {
		if (l == (l + r - 1) / 2) {
			leftMax = -1;
		} else {
			cout << "? " << l << " " << (l + r - 1) / 2 << nl;
			cout.flush();
			cin >> leftMax;
		}
		if (r == (l + r - 1) / 2 + 1) {
			rightMax = -1;
		} else {
			cout << "? " << ((l + r - 1) / 2) + 1 << " " << r << nl;
			cout.flush();
			cin >> rightMax;
		}
		if (leftMax == max) {
			r = (l + r - 1) / 2;
		} else if (rightMax == max) {
			l = ((l + r - 1) / 2) + 1;
		} else {
			if (max >= ((l + r - 1) / 2) + 1) {
				r = (l + r - 1) / 2;
				max = leftMax;
			} else {
				l = ((l + r - 1) / 2) + 1;
				max = rightMax;
			}
		}
	}
	if (l == r) {
		cout << "! " << l << nl;
		cout.flush();
	} else {
		cout << "? " << l << " " << r << nl;
		cout.flush();
		int num;
		cin >> num;
		cout << "! " << (num == l ? r : l) << nl;
		cout.flush();
	} 
}
