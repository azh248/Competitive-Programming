#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 1000000007
#define nl endl
#define pub push_back
#define pob pop_back

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		unordered_set<int> distances;
		int arr[n];

		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				distances.insert(arr[k] - arr[j]);
			}
		}
		cout << distances.size() << nl;
    }
}
