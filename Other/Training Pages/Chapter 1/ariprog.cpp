/*
ID:azh248
LANG:C++
TASK:ariprog 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n, m;

bool biSquare[125000]{};

int maxLength(int start, int difference) {
	if (start > 2*m*m || !biSquare[start]) {
		return 0;
	} 
	int len = maxLength(start + difference, difference) + 1;
	return len;
}

bool cmp1(pii a, pii b) {
	return a.first < b.first;
}
bool cmp2(pii a, pii b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
    cin >> n >> m;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			biSquare[i*i + j*j] = true;
		}
	}
	vector<pii> workingPairs;
	for (int i = 0; i <= 2*m*m; i++) {
		for (int j = 1; j <= (2*m*m - i)/n + 5; j++) {
			if (maxLength(i, j) >= n) {
				workingPairs.pb({i, j});
			}
		}
	}
	sort(workingPairs.begin(), workingPairs.end(), cmp1);
	sort(workingPairs.begin(), workingPairs.end(), cmp2);
	if (workingPairs.size() == 0) {
		cout << "NONE" << nl;
	}
	for (pii i : workingPairs) {
		cout << i.first << " " << i.second << nl;
	}
}
