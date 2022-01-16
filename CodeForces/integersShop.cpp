#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

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

int t;
vector<int> arr[100000];

class cmp1 {
  public:
	bool operator()(vector<int> a, vector<int> b) { 
		if (a[0] == b[0]) {
			return a[2] < b[2];
		}
		return a[0] < b[0]; 
	}
};

class cmp2 {
  public:
	bool operator()(vector<int> a, vector<int> b) {
		if (a[1] == b[1]) {
			return a[2] > b[2];
		}
		return a[1] < b[1];
	}
};

class cmp3 {
  public:
	bool operator()(vector<int> a, vector<int> b) {
		if (a[1] - a[0] == b[1] - b[0]) {
			return a[2] > b[2];
		}
		return (a[1] - a[0]) < (b[1] - b[0]);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			arr[i] = vector<int>(3);
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		}
		// set<vector<int>, cmp1> minSet;
		// set<vector<int>, cmp2> maxSet;
		// set<vector<int>, cmp3> lenSet;
		int minNum = arr[0][0];
		vector<int> minL = arr[0];
		int maxNum = arr[0][1];
		vector<int> maxR = arr[0];
		int longestLength = arr[0][1] - arr[0][0];
		vector<int> longest = arr[0];
		cout << longest[2] << nl;
		for (int i = 1; i < n; i++) {
			if (arr[i][0] < minNum) {
				minNum = arr[i][0];
				minL = arr[i];
			} else if (arr[i][0] == minNum) {
				if (arr[i][2] < minL[2]) {
					minL = arr[i];
				}
			}
			if (arr[i][1] > maxNum){
				maxNum = arr[i][1];
				maxR = arr[i];
			} else if (arr[i][1] == maxNum) {
				if (arr[i][2] < maxR[2]) {
					maxR = arr[i];
				}
			}
			if (arr[i][1] - arr[i][0] > longestLength) {
				longestLength = arr[i][1] - arr[i][0];
				longest = arr[i];
			} else if (arr[i][1] - arr[i][0] == longestLength) {
				if (arr[i][2] < longest[2]) {
					longest = arr[i];
				}
			}
			// minSet.insert(arr[i]);
			// maxSet.insert(arr[i]);
			// lenSet.insert(arr[i]);
			// vector<int> leastL = (*minSet.begin());
			// vector<int> greatestR = (*--maxSet.end());
			// vector<int> longest = *(--lenSet.end());
			int cost = minL[2] + maxR[2];
			if (longest[0] == minL[0] && longest[1] == maxR[1]) {
				cost = min(cost, longest[2]);
			}
			cout << cost << nl;
		}
	}
}
