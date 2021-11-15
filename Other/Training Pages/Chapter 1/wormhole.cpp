/*
ID:azh248
LANG:C++
TASK:wormhole 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n;

pii arr[12];

int paired[12];
int workingSolutions = 0;

bool works() {
	for (int i = 0; i < n; i++) {
		int i1 = paired[i];
		for (int j = 0; j < n; j++) {
			i1 = paired[i1];
			int wormhole = -1;
			int minX = 1e9;
			for (int k = 0; k < n; k++) {
				if (arr[k].second == arr[i1].second && arr[k].first > arr[i1].first && arr[k].first < minX) {
					minX = arr[k].first;
					wormhole = k;
				}
			}
			i1 = wormhole;
			if (wormhole == -1) {
				break;
			}
		}
		if (i1 != -1) {
			return true;
		}
	}
	return false;
}

void findPairings() {
	int unpaired = -1;
	for (int i = 0; i < n; i++) {
		if (paired[i] == -1) {
			unpaired = i;
			break;
		}
	}
	if (unpaired == -1) {
		workingSolutions += (works() ? 1 : 0);
		return;
	}
	for (int i = unpaired + 1; i < n; i++) {
		if (paired[i] == -1) {
			paired[i] = unpaired;
			paired[unpaired] = i;
			findPairings();
			paired[unpaired] = -1;
			paired[i] = -1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
    cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;		
	}
	memset(paired, -1, sizeof(paired));
	findPairings();
	cout << workingSolutions << nl;
}
