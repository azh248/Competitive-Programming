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
		ll n;
		cin >> n;
		vector<ll> arr;
		ll arrSum = 0;
		for (int i = 0; i < n; i++) {
			ll num;
			cin >> num;
			arr.pb(num);
			arrSum += num;
		}
		ll arrAverage = arrSum/n;
		// every element can be either the floor of average or floor of average + 1
		ll arrAverageCount = n - (arrSum - n * arrAverage); 
		ll arrAveragePlus1Count = n - arrAverageCount;
		cout << arrAverageCount * arrAveragePlus1Count << nl;
	}
}
