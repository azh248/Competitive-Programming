/*
ID:azh248
LANG:C++
TASK:ttravel 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n";
#define pb push_back

int n;
int parent[80000];
int id[80000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	id[0] = -1;
	for (int i = 1; i <= n; i++) {
		char ch; cin >> ch;
		if (ch == 'a') {
			int num;
			cin >> num;
			parent[i] = i - 1;
			id[i] = num;
		} else if (ch == 's') {
			parent[i] = parent[parent[i - 1]];
			id[i] = id[parent[i - 1]];
		} else {
			int num; cin >> num;
			parent[i] = parent[num - 1];
			id[i] = id[num - 1];
		}
		
		cout << id[i] << nl;
	}
}
