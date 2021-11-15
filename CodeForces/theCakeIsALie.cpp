#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int n, m, k; 

bool dp[101][101][10001];
bool visited[101][101][10001];

bool canSpend(int x, int y, int money) {
	if (x < 1 || y < 1 || money < 0) {
		return false; 
	} else if (x == 1 && y == 1) {
		return (money == 0);
	} else if (visited[x][y][money]) {
		return dp[x][y][money];
	}
	bool works = (canSpend(x - 1, y, money - y)) || (canSpend(x, y - 1, money - x));
	dp[x][y][money] = works;
	visited[x][y][money] = true;
	return works;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(visited, false, sizeof(visited));
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		if (canSpend(n, m, k)) {
			cout << "YES" << nl;
		} else {
			cout << "NO" << nl;
		}
	}	
}