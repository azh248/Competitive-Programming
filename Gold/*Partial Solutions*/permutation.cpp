/*
ID:azh248
LANG:C++
TASK:permutation 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define nl "\n"; 
#define pb push_back

int n;

pii arr[40];

int orientation(pii p, pii q, pii r) {
    int val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

bool doIntersect(pii p1, pii q1, pii p2, pii q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
  
    if (o1 != o2 && o3 != o4)
        return true;
  
    return false; 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;		
	}	
	ll working = 0;
	sort(arr, arr + n);                 
	for (int a = 0; a < 1; a++) {
		vector<pair<pii, pii> > lineSegments;
		lineSegments.pb({arr[0], arr[1]});
		lineSegments.pb({arr[1], arr[2]});
		lineSegments.pb({arr[0], arr[2]});
		for (int i = 3; i < n; i++) {
			int workingSegments = 0;
			vector<pair<pii, pii> > lines;
			for (int j = 0; j < i; j++) {
				bool works = true;
				for (auto k : lineSegments) {
					if (k.first != arr[i] && k.second != arr[i] && k.first != arr[j] && k.second != arr[j]) {
					if (k.first == arr[i]) {

					} else if (k.second == arr[i]) {
						if (doIntersect(k.first, k.second, arr[i], arr[j])) {
						works = false;
					}	
					}
					if (doIntersect(k.first, k.second, arr[i], arr[j])) {
						works = false;
					}
					}
				}
				if (works) {
					workingSegments++;
					lines.pb({arr[i], arr[j]});
				}
			}
			for (auto i : lines) {
				lineSegments.pb(i);
			}
			if (workingSegments != 3) {
				break;
			} else {
				if (i == n - 1) {
					working++;
				}
				continue;
			}
		}
	}
	while (next_permutation(arr, arr + n)) {
		vector<pair<pii, pii> > lineSegments;
		lineSegments.pb({arr[0], arr[1]});
		lineSegments.pb({arr[1], arr[2]});
		lineSegments.pb({arr[0], arr[2]});
		for (int i = 3; i < n; i++) {
			int workingSegments = 0;
			vector<pair<pii, pii> > lines;
			for (int j = 0; j < i; j++) {
				bool works = true;
				for (auto k : lineSegments) {
					if (k.first != arr[i] && k.second != arr[i] && k.first != arr[j] && k.second != arr[j]) {
						if (doIntersect(k.first, k.second, arr[i], arr[j])) {
							works = false;
						}
					}
				}
				if (works) {
					workingSegments++;
					lines.pb({arr[i], arr[j]});
				}
			}
			for (auto i : lines) {
				lineSegments.pb(i);
			}
			if (workingSegments != 3) {
				break;
			} else {
				if (i == n - 1) {
					working++;
				}
				continue;
			}
		}
	}
	cout << working << nl;
}