/*
ID:azh248
LANG:C++
TASK:sight 
*/

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

int n, r;
pii arr[50000];
set<double> angles;

struct vec {	 // vector from one point to another
	double x, y; // name: `vec' is different from STL vector
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(pii a, pii b) { // convert 2 points to vector from a->b
	return vec(b.pA - a.pA, b.pB - a.pB);
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(pii a, pii o, pii b) { // angle aob in rad
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

bool works[100000]{};
int main() {
	freopen("sight.in", "r", stdin);
	freopen("sight.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].pA >> arr[i].pB;
	}
	vector<vector<double>> points;
	for (int i = 0; i < n; i++) {
		double x = arr[i].pA;
		double y = arr[i].pB;
		double d = hypot(x, y);
		double horizontalDisplacement = atan2(y, x) * 180 / M_PI;
		double angle = acos(r / d) * (180 / M_PI);
		double top = angle + horizontalDisplacement;
		double bottom = -angle + horizontalDisplacement;
		if (bottom < 0) {
			points.pb({bottom + 360, 0, (double)i});
			points.pb({top + 360, 1, (double)i});
			works[i] = true;
		} else {
			points.pb({bottom, 0, (double)i});
			points.pb({top, 1, (double)i});
			points.pb({bottom + 360, 0, (double)i});
			points.pb({top + 360, 1, (double)i});
		}
	}

	sort(points.begin(), points.end());

	int cnt = 0;
	int sum = 0;
	for (auto i : points) {
		if (i[1]) {
			if (i[0] < 360 || works[(int)i[2]]) {
				cnt--;
			}
		} else {
			sum += cnt;
			if (i[0] < 360 || works[(int)i[2]]) {
				cnt++;
			}
		}
	}

	cout << sum << nl;
}