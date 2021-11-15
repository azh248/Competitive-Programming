/*
ID:azh248
LANG:C++
TASK:unitedCowsOfFarmerJohn
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define nl "\n";
#define pb push_back

int n;

int arr[200000];

void merge(vector<int> segTree[], int node) {
    int l1 = segTree[2 * node].size();
    int l2 = segTree[2 * node + 1].size();
    int i = 0;
	int j = 0;

    while (i < l1 && j < l2) {
        if (segTree[2 * node][i] > segTree[2 * node + 1][j]) {
            segTree[node].pb(segTree[2 * node + 1][j]);
            j++;
        } else {
            segTree[node].pb(segTree[2 * node][i]);
            i++;
        }
    }

    while (i < l1) {
        segTree[node].pb(segTree[2 * node][i]);
        i++;
    }

    while (j < l2) {
        segTree[node].pb(segTree[2 * node + 1][j]);
        j++;
    }
    return;
}
  
void build(vector<int> segTree[], int* arr, int a, int b, int node) {
    if (a == b) {
        segTree[node].pb(arr[a]);
        return;
    }
    int mid = (a + b) / 2;
    build(segTree, arr, a, mid, 2 * node);
    build(segTree, arr, mid + 1, b, 2 * node + 1);
    merge(segTree, node);
    return;
}

int query(vector<int> segTree[], int node, int a, int b, int l, int r) {
    if (a > r || b < l) {
        return 0;
    } if (a >= l && b <= r) {
        return segTree[node].end() - upper_bound(segTree[node].begin(), segTree[node].end(), r);
	}
    int mid = (a + b) / 2;
	// merge 
    int query1 = query(segTree, 2 * node, a, mid, l, r);
    int query2 = query(segTree, 2 * node + 1, mid + 1, b, l, r);
    return query1 + query2;
}
  
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];		
	}
	// the number of pairs of leaders is just the number of distinct numbers after any l that are before the next occurrence of l
	// we can use a merge segtree to find the distinct numbers in a range (l, r) in o(logn) time
    int nextOccurrence[200000];
    vector<int> segTree[4*n];

    unordered_map<int, int> map1;

    for (int i = n - 1; i >= 0; i--) {
        if (map1[arr[i]] == 0) {
            nextOccurrence[i] = n;
            map1[arr[i]] = i;
        } else {
            nextOccurrence[i] = map1[arr[i]];
            map1[arr[i]] = i;
        }
    }
    build(segTree, nextOccurrence, 0, n - 1, 1);
  
	ll count = 0;
	int mostRecent[200000]; // most recent occurrence of each number
	memset(mostRecent, -1, sizeof(mostRecent));

	for (int i = n - 1; i >= 0; i--) {
		if (mostRecent[arr[i]] != -1) {
			count += query(segTree, 1, 0, n - 1, i, mostRecent[arr[i]] - 1) - 1;
		} else {
			count += query(segTree, 1, 0, n - 1, i + 1, n - 1);
		}
		mostRecent[arr[i]] = i;
	}
	cout << count << nl;
}
