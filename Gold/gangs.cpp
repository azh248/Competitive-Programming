/*
ID:azh248
LANG:C++
TASK:gangs 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, m;
int members[100];

int initialMaxRemaining;

int maxRemaining(int currentGang, int currentGangCnt) {
	multiset<pii> currMembers;
	for (int i = 1; i < m; i++) {
		currMembers.insert({members[i], i});
	}
	for (int i = 0; i < n; i++) {
		pii nextGang = *--currMembers.end();
		if (nextGang.first == 0) {
			if (currentGang == 0) {
				return members[0] + currentGangCnt;
			} else {
				return members[0] - currentGangCnt;
			}
		}
		currMembers.erase(--currMembers.end());
		currMembers.insert(pii(nextGang.first - 1, nextGang.second));
		if (nextGang.second == currentGang) {
			currentGangCnt++;
		} else {
			if (currentGangCnt == 0) {
				currentGang = nextGang.second;
				currentGangCnt = 1;
			} else {
				currentGangCnt--;
			}
		}
	}
}

vector<int> minimalSeq() {
	vector<int> sequence;
	initialMaxRemaining = maxRemaining(-1, 0);
	if (initialMaxRemaining <= 0) {
		return {};
	}
	int currentGang = -1;
	int currentGangCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (members[j] > 0) {
				members[j]--;
				if (currentGang == j) {
					currentGangCnt++;
				} else {
					if (currentGangCnt == 0) {
						currentGang = j;
						currentGangCnt = 1;
					} else {
						currentGangCnt--;
					}
				}
				if (maxRemaining(currentGang, currentGangCnt) == initialMaxRemaining) {
					sequence.pb(j);
					break;
				} else {
					members[j]++;
					if (currentGang == j) {
						currentGangCnt--;
					} else {
						currentGangCnt++;
					}
				}
			}
		}
	}
	return sequence;
}

int main() {
	freopen("gangs.in", "r", stdin);
	freopen("gangs.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> members[i];
	}
	vector<int> sequence = minimalSeq();
	if (initialMaxRemaining <= 0) {
		cout << "NO" << nl;
		return 0;
	} 
	cout << "YES" << nl;
	cout << initialMaxRemaining << nl;
	for (int i : sequence) {
		cout << i + 1 << nl;
	}
}