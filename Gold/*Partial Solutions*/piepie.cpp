#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, d;
int pies[400000];
pii bessieSorted[100000];
int bessieSortedTasty[100000];
int bessieSortedIndex[100000];
pii elsieSorted[100000];
int elsieSortedTasty[100000];
int elsieSortedIndex[100000];

int minDistTo0[400000];

unordered_set<int> visited;
map<int, int> dist; // distance from starting node
vector<int> zeroes;

int bfs(int root) {
	dist.clear();
	queue<pii> bfsQueue;
	visited.insert(root);
	bfsQueue.push({root, -1});
	dist.insert(make_pair(root, 0));
	while (!bfsQueue.empty()) {
		int node = bfsQueue.front().first;
		int parent = bfsQueue.front().second;
		bfsQueue.pop();
		if (pies[node] == 0 && node != root) {
			continue;
		}
		// if the pie's percepted value is 0, we can stop because it's always
		// optimal to start from that one instead -- this brings time complexity
		// down to O(n)
		if (node % 2 == 1) { // bessie's turn to gift a pie, we know her percepted value of elsie's pie
			int possiblePie = lower_bound(bessieSortedTasty, bessieSortedTasty + n, pies[node - 1] - d) - bessieSortedTasty;
			dist.insert(make_pair(node - 1, (*dist.find(parent)).second + 1));
			minDistTo0[node - 1] = min(minDistTo0[node - 1], (*dist.find(node - 1)).second);
			for (int i = possiblePie; i < n; i++) {
				if (bessieSortedTasty[i] > pies[node - 1]) {
					break; 
				} else if (bessieSortedIndex[i] * 2 + 2 * n == node - 1) {
					continue;
				}
				int neighbor = bessieSortedIndex[i] * 2 + 2 * n;
				if (visited.count(neighbor) == 0) {
					visited.insert(neighbor);
					if ((*dist.find(node - 1)).second <= minDistTo0[node - 1]) {
						bfsQueue.push({neighbor, node - 1});
					}
				}
			}
		} else { // elsie's turn to gift a pie, we know her percepted value of bessie's pie
			int possiblePie = lower_bound(elsieSortedTasty, elsieSortedTasty + n, pies[node + 1] - d) - elsieSortedTasty;
			dist.insert(make_pair(node + 1, (*dist.find(parent)).second + 1));
			minDistTo0[node + 1] = min(minDistTo0[node + 1], (*dist.find(node + 1)).second);
			for (int i = possiblePie; i < n; i++) {
				if (elsieSortedTasty[i] > pies[node + 1]) {
					break;
				} else if (elsieSortedIndex[i] * 2 + 1 == node + 1) {
					continue;
				}
				int neighbor = elsieSortedIndex[i] * 2 + 1;
				if (visited.count(neighbor) == 0) {
					visited.insert(neighbor);
					if ((*dist.find(node + 1)).second <= minDistTo0[node + 1]) {
						bfsQueue.push({neighbor, node + 1});
					}
				}
			}
		}
	}
	return visited.size();
}

int main() {
	freopen("piepie.in", "r", stdin);
	freopen("piepie.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> d;
	for (int i = 0; i < 2 * n; i++) {
		cin >> pies[2 * i] >> pies[2 * i + 1];
		if (pies[2 * i] == 0) {
			zeroes.pb(2 * i);
		}
		if (pies[2 * i + 1] == 0) {
			zeroes.pb(2 * i + 1);
		}
	}
	for (int i = 0; i < n; i++) {
		bessieSorted[i].first = pies[2 * i + 2 * n];
		bessieSorted[i].second = i;
	}
	for (int i = 0; i < n; i++) {
		elsieSorted[i].first = pies[2 * i + 1];
		elsieSorted[i].second = i;
	}
	sort(bessieSorted, bessieSorted + n);
	sort(elsieSorted, elsieSorted + n);

	for (int i = 0; i < n; i++) {
		bessieSortedTasty[i] = bessieSorted[i].first;
		bessieSortedIndex[i] = bessieSorted[i].second;
		elsieSortedTasty[i] = elsieSorted[i].first;
		elsieSortedIndex[i] = elsieSorted[i].second;
	}

	for (int i = 0; i < 400000; i++) {
		minDistTo0[i] = 1e9;
	}
	for (int i : zeroes) {
		bfs(i);
		visited.clear();
	}
	for (int i = 0; i < n; i++) {
		if (minDistTo0[2 * i] == 1e9) {
			cout << -1 << nl;
		} else {
			cout << minDistTo0[2 * i] << nl;
		}
	}
}
