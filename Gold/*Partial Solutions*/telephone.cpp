/*
ID: azh248
LANG: C++
TASK: telephone 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

int n, k;

vector<int> breedTransmits[50]; // breedTransmits[i] contains all breeds that breed i can transmit to
int breeds[50000]; // breeds[i] contains the breed of the ith cow
vector<int> cows[50]; // cows[i] contains the cows that belong to the ith breed

class cmp {
	public:
		bool operator()(pii a, pii b) {
			return a.second > b.second;
		}
};

int dist[50000];
bool visited[50000]{};
void dijkstra() {
	for (int i = 0; i < n; i++) {
		dist[i] = 1e18;
		visited[i] = false;
	}
	dist[0] = 0;
	priority_queue<pii, vector<pii>, cmp> cowQueue;
	cowQueue.push({0, 0}); 
	while (!cowQueue.empty()) { 
		int cow = cowQueue.top().first; 
		int distFromStart = cowQueue.top().second;
		cowQueue.pop();
		if (visited[cow]) {
			continue;
		}
		visited[cow] = true;
		for (int breed : breedTransmits[breeds[cow]]) { // all breeds that this cow can travel to
			for (int nextCow : cows[breed]) { // the cows that this cow can travel to in each breed
				int distance = abs(nextCow - cow);
				if (distFromStart + distance < dist[nextCow]) {
					dist[nextCow] = distFromStart + distance;
					visited[nextCow] = false;
					cowQueue.push({nextCow, dist[nextCow]}); // adds the neighbor cow and its distance to be processed later
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int breed;
		cin >> breed;
		breed--;
		cows[breed].pb(i);
		breeds[i] = breed;
	}
	for (int i = 0; i < k; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < k; j++) {
			if (s[j] == '1') {
				breedTransmits[i].pb(j);
			}
		}
	}
	dijkstra();
	if (!visited[n - 1]) {
		cout << -1 << nl;
		return 1;
	}
	cout << dist[n - 1] << nl;
}
