#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;
multiset<int> candies[100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		candies[a].insert(b);
	}
	for (int i = 0; i < n; i++) {
		int currStation = i;
		multiset<int> newCandies[100];
		for (int i = 0; i < n; i++) {
			newCandies[i] = candies[i];
		}
		int lastStation = n;
		int deliveredCandies = 0;
		int deliveryTime = 0;
		while (true) {
			if (lastStation == currStation) {
				if (deliveredCandies == m) {
					break;
				} else {
					lastStation = n;
				}
			}
			if (newCandies[currStation].size() != 0) {
				if (newCandies[currStation].lower_bound(currStation) != newCandies[currStation].begin() && *(--newCandies[currStation].lower_bound(currStation)) < currStation) {
					int newLastStation = *(--newCandies[currStation].lower_bound(currStation));
					if (lastStation > currStation) {
						lastStation = newLastStation;
					} else {
						lastStation = max(lastStation, newLastStation);
					}
					newCandies[currStation].erase(--newCandies[currStation].lower_bound(currStation));
					deliveredCandies++;
				} else {
					int newLastStation = *(--newCandies[currStation].end());
					if (lastStation > currStation) {
						if (lastStation == n) {
							lastStation = newLastStation;
						}
						lastStation = max(lastStation, newLastStation);
					}
					newCandies[currStation].erase(--newCandies[currStation].end());
					deliveredCandies++;
				}
			}
			deliveryTime++;
			currStation++;
			currStation %= n;
		}
		cout << deliveryTime << " ";
	}
	cout << nl;
}