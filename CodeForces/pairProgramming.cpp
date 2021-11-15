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
		int k, n, m; cin >> k >> n >> m;
		int nDirecs[100];
		int mDirecs[100];
		for (int i = 0; i < n; i++) {
			cin >> nDirecs[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> mDirecs[i];
		}
		int nPointer = 0;
		int mPointer = 0;
		vector<int> direcs;
		bool worksOverall = true;
		while (nPointer < n && mPointer < m) {
			bool works = false;
			if (nDirecs[nPointer] == 0) {
				direcs.pb(0);
				nPointer++;
				k++;
				works = true;
			} else if (nDirecs[nPointer] <= k) {
				direcs.pb(nDirecs[nPointer]);
				nPointer++;
				works = true;
			}
			if (mDirecs[mPointer] == 0) {
				direcs.pb(0);
				mPointer++;
				k++;
				works = true;
			} else if (mDirecs[mPointer] <= k) {
				direcs.pb(mDirecs[mPointer]);
				mPointer++;
				works = true;
			}
			if (!works) {
				worksOverall = false;
				break;
			}
		}
		if (!worksOverall) {
			cout << -1 << nl;
			continue;
		}
		while (nPointer < n) {
			if (nDirecs[nPointer] == 0) {
				direcs.pb(0);
				nPointer++;
				k++;
			} else if (nDirecs[nPointer] <= k) {
				direcs.pb(nDirecs[nPointer]);
				nPointer++;
			} else {
				worksOverall = false;
				break;
			}
		} 
		if (!worksOverall) {
			cout << -1 << nl;
			continue;
		}
		while (mPointer < m) {
			if (mDirecs[mPointer] == 0) {
				direcs.pb(0);
				mPointer++;
				k++;
			} else if (mDirecs[mPointer] <= k) {
				direcs.pb(mDirecs[mPointer]);
				mPointer++;
			} else {
				worksOverall = false;
				break;
			}
		}
		if (!worksOverall) {
			cout << -1 << nl;
		} else {
			for (int i : direcs) {
				cout << i << " ";
			}
			cout << nl;
		}
	}
}
