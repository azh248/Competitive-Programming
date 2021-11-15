/*
ID: azh248
LANG: C++
TASK: barn1
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 1000000007
#define F0R(j, n) for (int i = j; i < n; i++)
#define nl endl
#define pub push_back
#define pob pop_back

int m, s, c;
vector<int> distancesBetweenCows;
vector<int> cows;

int main() {
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
    cin >> m >> s >> c;
	F0R(0, c) {
		int stall;
		cin >> stall;
		cows.pub(stall);
	}
	sort(cows.begin(), cows.end());
	F0R(1, c) {
		distancesBetweenCows.pub(cows[i] - cows[i - 1] - 1);
	}
	sort(distancesBetweenCows.begin(), distancesBetweenCows.end());

	int boards = c;
	int coveredStalls = c;
	for (int i : distancesBetweenCows) {
		if (boards > m) {
			coveredStalls += i;
			boards--;
		} else {
			break;
		}
	}
	cout << coveredStalls << nl;
}
