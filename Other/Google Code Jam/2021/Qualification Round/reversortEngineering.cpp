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
	for (int t1 = 1; t1 <= t; t1++) {
		int n, c;
		cin >> n >> c;
		cout << "Case #" << t1 << ": ";
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			arr.pb(i + 1);
		}
		bool works = false;
		vector<int> arr2 = arr;
		int cost1 = 0;
		for (int i = 0; i < n - 1; i++) {
			int minNum = 1e9;
			int minIndex = -1;
			for (int k = i; k < n; k++) {
				if (arr2[k] < minNum) {
					minNum = arr2[k];
					minIndex = k;
				}
			}
			for (int j = 0; j <= (minIndex - i)/2; j++) {
				int num = arr2[i + j];
				arr2[i + j] = arr2[minIndex - j];
				arr2[minIndex - j] = num;
			}
			cost1 += minIndex - i + 1;
		}
		if (cost1 == c) {
			for (int i = 0; i < n; i++) {
				cout << arr2[i] << " ";
			}
			works = true;
			cout << nl;
			continue;
		}
		while (next_permutation(arr.begin(), arr.end())) {
			vector<int> arr1 = arr;
			int cost = 0;
			for (int i = 0; i < n - 1; i++) {
				int minNum = 1e9;
				int minIndex = -1;
				for (int k = i; k < n; k++) {
					if (arr1[k] < minNum) {
						minNum = arr1[k];
						minIndex = k;
					}
				}
				for (int j = 0; j <= (minIndex - i)/2; j++) {
					int num = arr1[i + j];
					arr1[i + j] = arr1[minIndex - j];
					arr1[minIndex - j] = num;
				}
				cost += minIndex - i + 1;
			}
			if (cost == c) {
				for (int i = 0; i < n; i++) {
					cout << arr[i] << " ";
				}
				works = true;
				cout << nl;
				break;
			}
		}
		if (!works) {
			cout << "IMPOSSIBLE" << nl;
		}
	}	
}
