#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n" 
#define pub push_back
#define pob pop_back
#define long long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
		int n, x;
		cin >> n >> x;
		int arr[n];
		ll min = 0;
		ll max = 0;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
			min += arr[j];
			max += ceil((double) arr[j]/(double) x);
		} 
		min = ceil((double) min/(double) x);
		cout << min << " " << max << nl;
    }
}
