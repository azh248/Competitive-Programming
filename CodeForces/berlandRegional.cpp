#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n; 
		cin >> n;
		pair<ll, ll> student[200000];
		vector<ll> uniStudents[200000];
		for (int i = 0; i < n; i++) {
			cin >> student[i].first;
			student[i].first--;
		}		
		for (int i = 0; i < n; i++) {
			cin >> student[i].second;
		}
		for (int i = 0; i < n; i++) {
			uniStudents[student[i].first].pb({student[i].second});
		}
		for (int i = 0; i < n; i++) {
			sort(uniStudents[i].begin(), uniStudents[i].end(), cmp);
		}
		ll sum[200000]{};
		for (int i = 0; i < n; i++) {
			vector<ll> prefixSum;
			for (int j = 0; j < uniStudents[i].size(); j++) {
				if (prefixSum.size() == 0) {
					prefixSum.pb(uniStudents[i][j]);
				} else {
					prefixSum.pb(uniStudents[i][j] + prefixSum[j - 1]);
				}
			}
			for (int j = 1; j <= n; j++) {
				if (j > uniStudents[i].size()) {
					break;
				}
				sum[j - 1] += prefixSum[uniStudents[i].size() - (uniStudents[i].size() % j) - 1];
			}
		}
		for (int i = 0; i < n; i++) {
			cout << sum[i] << " ";
		}
		cout << nl;
	}	
}