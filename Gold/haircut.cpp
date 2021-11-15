/*
ID:azh248
LANG:C++
TASK:haircut 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
int earliestOccurrence[100000];

int inversionBIT[100000]; // 1-indexed

// update prefix sums at a specified index and add a value
void inversionUpdate(int ind, int val) {
	ind++; // makes it 1-indexed
	while (ind <= n) {
		inversionBIT[ind] += val;
		ind += (ind & -ind); // makes it so that ind is now the next node
							 // responsible for our updated one
	}
}

int inversionGet(int ind) {
	ind++; // makes it 1-indexed
	int ret = 0;
	while (ind > 0) {
		ret += inversionBIT[ind];
		ind -= (ind & -ind); // repeatedly remove last "1" bit; all of these
							 // nodes make up our query
	}
	return ret;
}

bool cmp(pii a, pii b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

ll arr1[100000]; 
ll ret[100001]{};

int main() {
	freopen("haircut.in", "r", stdin);
	freopen("haircut.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<pii> arr;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		arr.pb(pii(num, i));
	}
	sort(arr.begin(), arr.end());
	ll inversionSum = 0;
	for (int i = n - 1; i >= 0; i--) { // we go through from high to low, at each time counting the number of indices before this one
									   // which are guaranteed to be greater than this one
		ll inversions = inversionGet(arr[i].second - 1); // we can just sort it so that when the values are equal we start with the last index so we never count an equal as an inversion
		inversionSum += inversions;
		inversionUpdate(arr[i].second, 1);
		arr1[arr[i].first] += inversions;
	}
	
	for (int i = n - 1; i >= 0; i--) {
		ret[i] = ret[i + 1];
		ret[i] += arr1[i];
	}
	for (int i = 0; i < n; i++) {
		cout << inversionSum - ret[i] << nl;
	}
}