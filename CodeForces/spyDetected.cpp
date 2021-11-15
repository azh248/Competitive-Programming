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
	while (t--) {
		int n;
		cin >> n;
		int arr[100];
		int count[101]{};
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			count[arr[i]]++;
		}	
		for (int i = 0; i < n; i++) {
			if (count[arr[i]] == 1) {
				cout << i + 1 << nl;
				break; 
			}
		}
	}	
}
