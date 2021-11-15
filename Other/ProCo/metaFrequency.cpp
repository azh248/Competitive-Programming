#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int s, n, q;

bool cmp(pii a, pii b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> n;
	map<ll, ll> arr;
	for (int i = 0; i < n; i++) {
		ll student; cin >> student; student--;
		if (arr.count(student) > 0) {
			arr[student]++;
		} else {
			arr[student] = 1;
		}
	}
	vector<pii> lateStudents;	
	for (pii i : arr) {
		lateStudents.pb(i);
	}
	sort(lateStudents.begin(), lateStudents.end(), cmp);
	vector<pii> lateStudentsPSum;
	lateStudentsPSum.pb(lateStudents[0]);
	for (int i = 1; i < lateStudents.size(); i++) {
		lateStudentsPSum.pb({lateStudents[i].first, lateStudentsPSum[i - 1].second + lateStudents[i].second});
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		ll x;
		cin >> x;
		int l = 0;
		int r = lateStudentsPSum.size() - 1;
		ll ans = l - 1;
		while (l <= r) {
			int mid = (r + l)/2;
			if (lateStudentsPSum[mid].second <= x) {
				if (mid == lateStudentsPSum.size() - 1) {
					ans = s;
					break;
				} else {
					ans = max(ans, lateStudentsPSum[mid + 1].first);
				}
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		if (ans == -1) {
			ans = lateStudentsPSum[0].first;
		}
		cout << ans << nl;
	}
}
