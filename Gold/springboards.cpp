/*
ID:azh248
LANG:C++
TASK:boards 
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

int n;
int d;
map<int, int> currBoards;
pair<pii, pair<int, bool>> boards[200000];
int minDist[200000];

int main() {
	freopen("boards.in", "r", stdin);
	freopen("boards.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> d >> n;
	currBoards[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> boards[2 * i].pA.pA >> boards[2 * i].pA.pB >> boards[2 * i + 1].pA.pA >> boards[2 * i + 1].pA.pB;
		boards[2 * i].pB = {i, false};
		boards[2 * i + 1].pB = {i, true};
	}
	sort(boards, boards + 2 * n);
	for (int i = 0; i < 2 * n; i++) {
		if (!boards[i].pB.pB) {
			minDist[boards[i].pB.pA] = boards[i].pA.pA + boards[i].pA.pB + (*prev(currBoards.upper_bound(boards[i].pA.pB))).pB;
		} else {
			int dist = minDist[boards[i].pB.pA] - boards[i].pA.pA - boards[i].pA.pB;
			auto it = prev(currBoards.upper_bound(boards[i].pA.pB));
			if ((*it).pB <= dist) {
				continue;
			} else {
				it++;
				while ((it != currBoards.end()) && ((*it).pB > dist)) {
					currBoards.erase(it++);
				}
				currBoards[boards[i].pA.pB] = dist;
			}
		}
	}
	cout << (*currBoards.rbegin()).pB + 2 * d << nl;
}
