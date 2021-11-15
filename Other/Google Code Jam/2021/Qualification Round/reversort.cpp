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
	for (int i1 = 1; i1 <= t; i1++) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int cost = 0;
		for (int i = 0; i < n - 1; i++) {
			int minNum = 1e9;
			int minIndex = -1;
			for (int k = i; k < n; k++) {
				if (arr[k] < minNum) {
					minNum = arr[k];
					minIndex = k;
				}
			}
			for (int j = 0; j <= (minIndex - i)/2; j++) {
				int num = arr[i + j];
				arr[i + j] = arr[minIndex - j];
				arr[minIndex - j] = num;
			}
			cost += minIndex - i + 1;
		}
		cout << "Case #" << i1 << ": " << cost << nl;		
	}	
}
