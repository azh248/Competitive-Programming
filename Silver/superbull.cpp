/*
ID:azh248
LANG:C++
TASK:superbull 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n;
int arr[2000];

vector<pii> adjLists[2000];
bool visited[2000];
int len[2000];

class cmpNodes {
  public:
	bool operator()(pii a, pii b) { return a.second > b.second; }
};

ll prims() {
	priority_queue<pii, vector<pii>, cmpNodes> nodes;
	nodes.push({0, 0});
	ll minWeight = 0;
	memset(len, 1e9, sizeof(len));
	while (!nodes.empty()) {
		int nextNode = nodes.top().first;
		int weight = nodes.top().second;
		nodes.pop();
		if (visited[nextNode] || weight < len[nextNode]) {
			continue;
		}
		visited[nextNode] = true;
		minWeight += weight;
		for (pii i : adjLists[nextNode]) {
			int neighbor = i.first;
			int neighborWeight = i.second;
			if (neighborWeight < len[neighbor] && !visited[neighbor]) {
				len[neighbor] = neighborWeight;
				nodes.push({neighbor, neighborWeight});
			}
		}
	}
	return minWeight;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("superbull.in", "r", stdin);
	freopen("superbull.out", "w", stdout);
    cin >> n;
	// maximal spanning tree
	for (int i = 0; i < n; i++) {
		cin >> arr[i];	
	}	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			adjLists[i].pb({j, -(arr[i]^arr[j])});
			adjLists[j].pb({i, -(arr[i]^arr[j])});
		}
	}
	cout << -prims() << nl;
}
