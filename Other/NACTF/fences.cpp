#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define F0R1(i, a) for (int i = 1; i <= (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i = a; i > 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())
#define S0RT(arr, n) sort(arr, arr + n)

#define pA first
#define pB second
#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t, n, m, f, c;
pll fences[100000];
int cowFence[100000];
int barnFence[100000];
pll cows[100002];
pll barns[100000];
vector<int> fenceBarns[100000];
vector<int> fenceCows[100000];

ll dist(pll a, pll b) { return (abs(a.pA - b.pA) + abs(a.pB - b.pB)); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m >> f >> c;
		for (int i = 0; i < f; i++) {
			fenceBarns[i].clear();
			fenceCows[i].clear();
			cin >> fences[i].pA >> fences[i].pB;
		}
		for (int i = 1; i <= n; i++) {
			cin >> cows[i].pA >> cows[i].pB;
		}
		for (int i = 0; i < m; i++) {
			cin >> barns[i].pA >> barns[i].pB;
		}
		cows[0] = pll(min(cows[1].pA, min(fences[0].pA, barns[0].pA)) - 1, cows[1].pB);
		n++;
		cows[n] = pll(max(cows[n - 1].pA, max(fences[f - 1].pA, barns[m - 1].pA)) + 1, cows[n - 1].pB);
		n++;
		int fenceInd = 0;
		for (int i = 0; i < n; i++) {
			while (fenceInd < f && cows[i].pA >= fences[fenceInd].pA) {
				fenceInd++;
			}
			fenceInd--;
			if (fenceInd >= f) {
				for (int j = i; j < n; j++) {
					cowFence[j] = -1;
				}
				break;
			}
			if (fenceInd == -1 || cows[i].pA > fences[fenceInd].pB) {
				if (fenceInd == -1) {
					fenceInd = 0;
				}
				cowFence[i] = -1;
			} else {
				cowFence[i] = fenceInd;
				fenceCows[fenceInd].pb(i);
			}
		}
		fenceInd = 0;
		for (int i = 0; i < m; i++) {
			while (fenceInd < f && barns[i].pA >= fences[fenceInd].pA) {
				fenceInd++;
			}
			fenceInd--;
			if (fenceInd >= f) {
				break;
			}
			if (fenceInd == -1 || barns[i].pA > fences[fenceInd].pB) {
				if (fenceInd == -1) {
					fenceInd = 0;
				}
				continue;
			} else {
				fenceBarns[fenceInd].pb(i);
			}
		}
		multiset<ll> left;
		multiset<ll> right;
		ll minDistCW = 1e18;
		ll minDistCCW = 1e18;
		ll verticalFenceChange = 0;
		ll horizontalFenceChange = 0;
		int currFence = -1;
		int currBarn = 0;
		unordered_set<int> removedBarns;

		for (int i = 0; i < m; i++) {
			right.insert(dist(cows[0], barns[i]));
		}

		// maintain distances to barns above left, right, and current fence
		// left and right update as we go along; when you're going to barns
		for (int i = 0; i < n; i++) {
			// move barns from one side to another
			while (currBarn < m && barns[currBarn].pA <= cows[i].pA) {
				if (!removedBarns.count(currBarn)) {
					right.erase(right.find(dist(cows[0], barns[currBarn])));
					left.insert(dist(cows[n - 1], barns[currBarn]));
				}
				currBarn++;
			}

			if (cowFence[i] != currFence) {
				if (currFence == -1) { // entering a new fence, we need to
										// initialize the sets
					for (int j = 0; j < fenceBarns[cowFence[i]].size(); j++) {
						int barn = fenceBarns[cowFence[i]][j];
						removedBarns.insert(barn);
						if (barns[barn].pA <= cows[i].pA) { // we can find it in the left set
							left.erase(left.find(dist(barns[barn], cows[n - 1])));
						} else { // we can find it in the right set
							right.erase(right.find(dist(barns[barn], cows[0])));
						}
						minDistCW = min(minDistCW, dist(cows[i], pll(fences[cowFence[i]].pA, c)) + dist(pll(fences[cowFence[i]].pA, c), barns[barn]));
						minDistCCW = min(minDistCCW, dist(cows[i], pll(fences[cowFence[i]].pB, c)) + dist(pll(fences[cowFence[i]].pB, c), barns[barn]));
					}
				} else if (cowFence[i] == -1) { // leaving the current
												// fence, remove all the
												// elements in the sets and add
					for (int j = 0; j < fenceBarns[cowFence[i - 1]].size(); j++) {
						int barn = fenceBarns[cowFence[i - 1]][j];
						left.insert(dist(barns[barn], cows[n - 1]));
					}
					removedBarns.clear();
					verticalFenceChange = 0;
					horizontalFenceChange = 0;
					minDistCW = 1e18;
					minDistCCW = 1e18;
				} else {
					// changing fences
					for (int j = 0; j < fenceBarns[cowFence[i - 1]].size(); j++) {
						int barn = fenceBarns[cowFence[i - 1]][j];
						left.insert(
							dist(barns[barn], cows[n - 1]));
					}
					removedBarns.clear();
					verticalFenceChange = 0;
					horizontalFenceChange = 0;
					minDistCW = 1e9;
					minDistCCW = 1e9;
					for (int j = 0; j < fenceBarns[cowFence[i]].size(); j++) {
						int barn = fenceBarns[cowFence[i]][j];
						removedBarns.insert(barn);
						if (barns[barn].pA <= cows[i].pA) { // we can find it in the left set
							left.erase(left.find(dist(barns[barn], cows[n - 1])));
						} else { // we can find it in the right set
							right.erase(right.find(dist(barns[barn], cows[0])));
						}
						minDistCW = min(minDistCW, dist(cows[i], pll(fences[cowFence[i]].pA, c)) + dist(pll(fences[cowFence[i]].pA, c), barns[barn]));
						minDistCCW = min(minDistCCW, dist(cows[i], pll(fences[cowFence[i]].pB, c)) + dist(pll(fences[cowFence[i]].pB, c), barns[barn]));
					}
				}
			} 
			currFence = cowFence[i];
			ll rightChange = cows[i].pB - cows[0].pB + cows[i].pA - cows[0].pA;
			ll leftChange = cows[i].pB - cows[n - 1].pB + cows[n - 1].pA - cows[i].pA;
			if (i != 0 && i != n - 1) {
				if (left.size() == 0 && right.size() == 0) {
					cout << min(minDistCCW - horizontalFenceChange -
										verticalFenceChange,
									minDistCW + horizontalFenceChange -
										verticalFenceChange)
						 << nl;
				} else if (right.size() == 0) {
					cout << min(*left.begin() - leftChange,
								min(minDistCCW - horizontalFenceChange -
										verticalFenceChange,
									minDistCW + horizontalFenceChange -
										verticalFenceChange)) 
						 << nl;
				} else if (left.size() == 0) {
					cout << min(*right.begin() - rightChange,
								min(minDistCCW - horizontalFenceChange -
										verticalFenceChange,
									minDistCW + horizontalFenceChange -
										verticalFenceChange))
						 << nl;
				} else {
					cout << min(min(*right.begin() - rightChange,
								*left.begin() - leftChange),
							min(minDistCCW - horizontalFenceChange - verticalFenceChange,
								minDistCW + horizontalFenceChange - verticalFenceChange)) << nl;
				}
			}
			if (cowFence[i] != -1) {
				if (i < n - 1) {
					horizontalFenceChange += cows[i + 1].pA - cows[i].pA;
					verticalFenceChange += cows[i + 1].pB - cows[i].pB;
				}
			}
		}
	}
}
