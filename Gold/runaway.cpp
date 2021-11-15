/*
ID:azh248
LANG:C++
TASK:runaway 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, ll>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

ll n, l;

vector<pii> adjLists[200000];
ll diffPastures[200000];

pair<multiset<ll>, ll> pastures(int node, int par) {
	if (adjLists[node].size() == 1 && node != 0) {
		diffPastures[node] = 1;
		return make_pair(multiset<ll>({0}), 0);
	}
	pair<multiset<ll>, ll> currPastures;
	currPastures.first.insert(0);
	currPastures.second = 0;
	for (pii i : adjLists[node]) {
		if (i.first != par) {
			pair<multiset<ll>, ll> neighborPastures = pastures(i.first, node);
			neighborPastures.second += i.second;
			if (neighborPastures.first.size() > currPastures.first.size()) {
				swap(neighborPastures, currPastures);
			}
			for (ll j : neighborPastures.first) {
				currPastures.first.insert(j - currPastures.second + neighborPastures.second);
			}
		}
	}
	auto it = currPastures.first.upper_bound(l - currPastures.second);
	while (currPastures.first.size() > 0 && it != currPastures.first.end()) {
		auto it1 = it;
		it1++;
		currPastures.first.erase(it);
		it = it1;
	}
	diffPastures[node] = currPastures.first.size();;
	return currPastures;
}

int main() {
	freopen("runaway.in", "r", stdin);
	freopen("runaway.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l;
	for (int i = 1; i < n; i++) {
		int a; cin >> a; a--;
		ll len; cin >> len;
		adjLists[i].pb(pii(a, len));
		adjLists[a].pb(pii(i, len));
	}
	pastures(0, -1);
	for (int i = 0; i < n; i++) {
		cout << diffPastures[i] << nl;
	}
}
