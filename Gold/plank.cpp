#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
priority_queue<int, vector<int>, greater<int>> planks;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	ll cost = 0;
	for (int i = 0; i < n; i++) {
		int num; cin >> num; planks.push(num);
	}
	while (planks.size() > 1) {
		int a = planks.top();
		planks.pop();
		int b = planks.top();
		planks.pop();
		cost += a + b;
		planks.push(a + b);
	}
	cout << cost << nl;
}
