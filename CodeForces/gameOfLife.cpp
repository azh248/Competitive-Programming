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
		int n, m;
		cin >> n >> m;

		string s; 
		cin >> s;

		vector<pii> ranges;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				ranges.pb({i - m, i + m});
			}
		}

		if (ranges.size() == 0) {
			cout << s << nl;
			continue;
		} else if (ranges.size() == 1) {
			string newS = "";
			for (int i = 0; i < n; i++) {
				newS += "0";
			}
			for (int i = max(ranges[0].first, 0); i <= min(ranges[0].second, n - 1); i++) {
				newS[i] = '1';
			}
			cout << newS << nl;
			continue;
		}

		vector<pii> actualRanges;

		for (int i = 0; i < ranges.size() - 1; i++) {
			if (ranges[i].second >= ranges[i + 1].first) {
				if ((ranges[i].second - ranges[i + 1].first) % 2 == 0) {
					int average = (ranges[i].second + ranges[i + 1].first)/2;
					if (i > 0) {
						actualRanges[actualRanges.size() - 1] = {max(ranges[i].first, actualRanges[actualRanges.size() - 1].first), average - 1};
					} else {
						actualRanges.pb({ranges[i].first, average - 1});
					}
					actualRanges.pb({average + 1, ranges[i + 1].second});
				} else {
					int average = (ranges[i].second + ranges[i + 1].first) / 2;
					if (i > 0) {
						actualRanges[actualRanges.size() - 1] = {max(ranges[i].first, actualRanges[actualRanges.size() - 1].first), average};
					} else {
						actualRanges.pb({ranges[i].first, average});
					}
					actualRanges.pb({average + 1, ranges[i + 1].second});
				}
			} else {
				if (i > 0) {
					actualRanges[actualRanges.size() - 1] = {max(ranges[i].first, actualRanges[actualRanges.size() - 1].first), ranges[i].second};
				} else {
					actualRanges.pb({ranges[i].first, ranges[i].second});
				}
				actualRanges.pb({ranges[i + 1].first, ranges[i + 1].second});
			}
		}

		int currIndex = -1;

		string newS = "";

		for (int i = 0; i < n; i++) {
			newS += "0";
		}

		for (int i = 0; i < actualRanges.size(); i++) {
			if (i < actualRanges.size() - 1) {
				if (min(actualRanges[i].second, n - 1) > currIndex) {
					for (int j = max(currIndex + 1, max(actualRanges[i].first, 0)); j <= min(actualRanges[i].second, n - 1); j++) {
						if (j < (actualRanges[i + 1].first + actualRanges[i + 1].second) / 2) {
							newS[j] = '1';
							currIndex = j;
						}
					}
				} 
			} else {
				if (min(actualRanges[i].second, n - 1) > currIndex) {
					for (int j = max(currIndex + 1, max(actualRanges[i].first, 0)); j <= min(actualRanges[i].second, n - 1); j++) {
						newS[j] = '1';
						currIndex = j;
					}
				}
			}
		}

		cout << newS << nl;
	}
}