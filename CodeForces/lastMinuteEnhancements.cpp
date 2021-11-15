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
		int arr[n];
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		arr[n - 1]++;
		for (int j = n - 2; j >= 0; j--) {
			if (arr[j + 1] - arr[j] > 1) {
				arr[j]++;
			}
		}
		unordered_set<int> uniqueElements;
		for (int j = 0; j < n; j++) {
			uniqueElements.insert(arr[j]);
		}
		cout << uniqueElements.size() << nl;
    }
}
