#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;  

#define MOD 1000000007
#define nl "\n"
#define pb push_back
#define long long long

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 0; t1 < t; t1++) {
		int n;
		cin >> n;
		indexed_set s;
		ll inversions = 0;
		for (int i = 0; i < n; i++) {
			ll num;
			cin >> num;
			s.insert(num);
			inversions += i - s.order_of_key(num);
		}
		cout << inversions << nl;
	}	
}