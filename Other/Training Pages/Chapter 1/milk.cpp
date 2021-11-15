/*
ID: azh248
LANG: C++
TASK: milk
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 1000000007
#define F0R(j, n) for (int i = j; i < n; i++)
#define nl endl
#define pub push_back
#define pob pop_back

int n, m;
vector<pair<int, int> > farmers;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    cin >> n >> m;
    F0R(0, m) {
		int price, amount;
		cin >> price >> amount;
		farmers.pub({price, amount});
	}
	sort(farmers.begin(), farmers.end(), cmp);
	int cost = 0;
	for (pair<int, int> i : farmers) {
		if (i.second > n) {
			cost += (n) * i.first;
			break;
		} else {
			n -= i.second;
			cost += i.second * i.first;
		}
	}
	cout << cost << nl;
}
