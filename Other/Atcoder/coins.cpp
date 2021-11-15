#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back
#define double long double

int n;
double p[3000];

double dp[3000][3000];

double headsTails(int heads, int tails) {
	if (heads + tails == n) {
		return (heads > tails) ? (double)1 : (double)0;
	} else if (dp[heads][tails] != -1) {
		return dp[heads][tails];
	}
	double probability = headsTails(heads + 1, tails) * (double)p[heads + tails] + headsTails(heads, tails + 1) * ((double)1 - p[heads + tails]);
	dp[heads][tails] = probability;
	return probability;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < 3000; i++) {
		for (int j = 0; j < 3000; j++) {
			dp[i][j] = -1;
		}
	}
	cout << fixed << setprecision(10) << headsTails(0, 0) << nl;
}
