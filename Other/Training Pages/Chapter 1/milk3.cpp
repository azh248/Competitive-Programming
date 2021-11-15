/*
ID:azh248
LANG:C++
TASK:milk3 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int aCap, bCap, cCap;

set<int> amounts;

bool visited[21][21][21];

void findAmounts(int a, int b, int c) {
	if (visited[a][b][c]) {
		return;
	}
	// try pouring all of them
	if (a == 0) {
		amounts.insert(c);
	}
	visited[a][b][c] = true;
	findAmounts(min(a + b, aCap), max(a + b - aCap, 0), c);
	findAmounts(max(a + b - bCap, 0), min(a + b, bCap), c);
	findAmounts(min(a + c, aCap), b, max(a + c - aCap, 0));
	findAmounts(max(a + c - cCap, 0), b, min(a + c, cCap));	
	findAmounts(a, min(b + c, bCap), max(b + c - bCap, 0));
	findAmounts(a, max(b + c - cCap, 0),  min(b + c, cCap));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
    cin >> aCap >> bCap >> cCap;
	findAmounts(0, 0, cCap);
	for (int i : amounts) {
		if (i != *amounts.rbegin()) {
			cout << i << " ";
		} else {
			cout << i << nl;
		}
	}
}
