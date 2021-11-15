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
		int count = 0;
		for (int i = 3; (i*i + 1)/2 <= n; i += 2) {
			count++;
		}	
		cout << count << nl; 
	}	
}