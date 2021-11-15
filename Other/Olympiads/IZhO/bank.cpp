#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;

bool visited[(1 << 20)]{};
bool dp[(1 << 20)];

int salariesFilled[(1 << 20)];
int lastSalaryMoney[(1 << 20)];

int salaries[20];
int banknotes[20];

bool canPaySalaries(int mask) {
	if (mask == (1 << m) - 1) { // all banknotes have been used 
		return (salariesFilled[mask] == n);
	} else if (visited[mask]) {
		return dp[mask];
	}
	visited[mask] = true;
	int filled = salariesFilled[mask];
	int money = lastSalaryMoney[mask];
	for (int i = 0; i < m; i++) {
		if (!(mask & (1 << i))) { // banknote not in mask, we can try putting it in
			if (money + banknotes[i] == salaries[filled] && filled == n - 1) {
				dp[mask] = true;
				return true;
			} else if (money + banknotes[i] <= salaries[filled]) {
				if (canPaySalaries(mask + (1 << i))) {
					dp[mask] = true;
					return true;
				}
			} 
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> salaries[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> banknotes[i];
	}
	for (int mask = 0; mask < (1 << m); mask++) {
		// we need to precalculate the number of salaries that each mask will fill, and the remaining money that will be put towards filling the next salary
		// it's assumed that each salary is able to be perfectly filled, as this is the only case in which we're using the precalculated values
		int sum = 0;
		salariesFilled[mask] = 0;
		for (int i = 0; i < m; i++) {
			if (mask & (1 << i)) {
				sum += banknotes[i];
			}
		}
		for (int i = 0; i < n; i++) {
			if (salaries[i] > sum) {
				lastSalaryMoney[mask] = sum;
				break;
			} else {
				sum -= salaries[i];
				salariesFilled[mask]++;
			}
		}
	}
	cout << (canPaySalaries(0) ? "YES" : "NO") << nl;
}
