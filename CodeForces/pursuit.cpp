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
		int n; cin >> n;
		vector<int> points1(n);
		vector<int> points2(n);
		for (int i = 0; i < n; i++) {
			cin >> points1[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> points2[i];
		}
		sort(points1.begin(), points1.end());
		sort(points2.begin(), points2.end());
		int points1Sum = 0;
		int points2Sum = 0;
		for (int i = n/4; i < n; i++) {
			points1Sum += points1[i];
			points2Sum += points2[i];
		}
		if (points1Sum >= points2Sum) {
			cout << 0 << nl;
			continue;
		}
		int moves = 0;

		int n1 = n;
		int pointer2 = n/4 - 1;

		while (true) {
			n1++;
			points1Sum += 100;
			moves++;
			if (n1 % 4 == 0) {
				points1Sum -= points1[n1/4 - 1];
			} else {
				if (pointer2 < 0) {
					points2Sum += 0;
				} else {
					points2Sum += points2[pointer2];
					pointer2--;
				}
			}
			if (points1Sum >= points2Sum) {
				cout << moves << nl;
				break;
			}
		}
	}
}