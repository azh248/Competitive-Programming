/*
ID:azh248
LANG:C++
TASK:crazy 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, c;

struct vec { // vector from one point to another
	double x, y; // name: `vec' is different from STL vector
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(pii a, pii b) { // convert 2 points to vector from a->b
	return vec(b.first - a.first, b.second - a.second);
}

double cross(vec a, vec b) { // may overflow, watch out
	return a.x * b.y - a.y * b.x; 
} 

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(pii p, pii q, pii r) { 
	return cross(toVec(p, q), toVec(p, r)) > 0; 
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }


double angle(pii a, pii o, pii b) {  // angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); 
}

bool inPolygon(pii pt, const vector<pii> &P) { // make sure the first vertex is equal to the last vertex
	if ((int)P.size() == 0) {
		return false;
	}
	double sum = 0;
	for (int i = 0; i < (int)P.size() - 1; i++) {
		if (ccw(pt, P[i], P[i + 1])) {
			sum += angle(P[i], pt, P[i + 1]); // left turn, counterclockwise
		} else {
			sum -= angle(P[i], pt, P[i + 1]); // right turn, clockwise
		}
	} 
	return fabs(fabs(sum) - 2 * acos(-1.0)) < 1e-9;
}

int visFences[1000];
int beginning[1000];
pair<pii, pii> fences[1000];
map<pii, vector<int>> beginnings;
pii cows[1000];
int polygonIndex = 0;
vector<string> masks;
vector<pii> polygons[1001];

bool cmp(pii a, pii b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	freopen("crazy.in", "r", stdin);
	freopen("crazy.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		pii point1, point2;
		cin >> point1.first >> point1.second >> point2.first >> point2.second;
		fences[i] = {point1, point2};
		if (beginnings.find(point1) != beginnings.end()) {
			beginnings[point1].pb(i);
		} else {
			beginnings.insert({point1, {i}});
		}
		if (beginnings.find(point2) != beginnings.end()) {
			beginnings[point2].pb(i);
		} else {
			beginnings.insert({point2, {i}});
		}
	}
	for (int i = 0; i < c; i++) {
		pii nextCow;
		cin >> nextCow.first >> nextCow.second;
		cows[i] = nextCow;
	}
	for (int i = 0; i < n; i++) {
		if (!visFences[i]) {
			visFences[i] = true;
			pii currEnd = fences[i].second;
			vector<pii> currPolygon;
			pii prevCurrEnd = fences[i].first;
			currPolygon.pb(currEnd);
			while (currEnd.first != fences[i].first.first || currEnd.second != fences[i].first.second) {
				int newFence1 = beginnings[currEnd][0];
				int newFence2 = beginnings[currEnd][1];
				visFences[newFence1] = true;
				visFences[newFence2] = true;
				if ((fences[newFence1].first != prevCurrEnd && fences[newFence1].first != currEnd) || (fences[newFence1].second != prevCurrEnd && fences[newFence1].second != currEnd)) {
					if (fences[newFence1].first != prevCurrEnd && fences[newFence1].first != currEnd) {
						prevCurrEnd = currEnd;
						currEnd = fences[newFence1].first;
					} else {
						prevCurrEnd = currEnd;
						currEnd = fences[newFence1].second;
					}
				} else {
					if (fences[newFence2].first != prevCurrEnd && fences[newFence2].first != currEnd) {
						prevCurrEnd = currEnd;
						currEnd = fences[newFence2].first;
					} else {
						prevCurrEnd = currEnd;
						currEnd = fences[newFence2].second;
					}
				}
				currPolygon.pb(currEnd);
			}
			for (int j = 0; j < currPolygon.size(); j++) {
				polygons[polygonIndex].pb(currPolygon[j]);
			}
			polygons[polygonIndex].pb(currPolygon[0]);
			polygonIndex++;
		}
	}
	for (int i = 0; i < c; i++) {
		string mask = "";
		for (int j = 0; j < polygonIndex; j++) {
			if (inPolygon(cows[i], polygons[j])) {
				mask += "1";
			} else {
				mask += "0";
			}
		}
		masks.pb(mask);
	}
	sort(masks.begin(), masks.end());
	int largestCommunity = 0;
	for (int i = 0; i < masks.size(); i++) {
		int community = 1;
		for (int j = i + 1; j < masks.size(); j++) {
			if (masks[i] == masks[j]) {
				community++;
			} else {
				i = j - 1;
				break;
			}
		}
		largestCommunity = max(largestCommunity, community);
	}
	cout << largestCommunity << nl;;
}