/*
ID:azh248
LANG:C++
TASK:hayfeast 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

ll n, m;
pii hayBales[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("hayfeast.in", "r", stdin);
	freopen("hayfeast.out", "w", stdout);
    cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> hayBales[i].first >> hayBales[i].second;		
	}	
	int l = 0;
	int r = -1;
	ll minSpice = 1e18;
	multiset<ll> spices;
	ll flavor = 0;
	while (flavor < m) {
		r++;
		flavor += hayBales[r].first;
		spices.insert(hayBales[r].second);	
	}
	minSpice = *spices.rbegin();
	while (r < n - 1) {
		if (flavor - hayBales[l].first >= m){
			flavor -= hayBales[l].first;
			spices.erase(spices.find(hayBales[l].second));
			l++;
		} else {
			r++;
			flavor += hayBales[r].first;
			spices.insert(hayBales[r].second);
		}
		minSpice = min(minSpice, *spices.rbegin());
	}
	while (flavor >= m){
		minSpice = min(minSpice, *spices.rbegin());
		flavor -= hayBales[l].first;
		spices.erase(spices.find(hayBales[l].second));
		l++;
	}
	cout << minSpice << nl;
}
