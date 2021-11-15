#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

unordered_set<int> adjLists1[26];

vector<int> adjLists[26];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		string s1;
		cin >> s1;
		if (s1.length() == 1) {
			cout << "YES" << nl << "abcdefghijklmnopqrstuvwxyz" << nl;
			continue;
		}
		for (int i = 0; i < 26; i++) {
			adjLists[i].clear();
			adjLists1[i].clear();
		}
		for (int i = 0; i < s1.length() - 1; i++) {
			adjLists1[s1[i + 1] - 'a'].insert(s1[i] - 'a');
			adjLists1[s1[i] - 'a'].insert(s1[i + 1] - 'a');
		}
		bool works = true;
		for (int i = 0; i < 26; i++) {
			for (int j : adjLists1[i]) {
				adjLists[i].pb(j);
			}
			if (adjLists[i].size() > 2) {
				cout << "NO" << nl;
				works = false;
				break;
			}
		}
		if (!works) {
			continue;
		}
		int count = 0;
		for (int i = 0; i < 26; i++) {
			if (adjLists[i].size() == 1) {
				count++;
			}
		}
		if (count != 2) {
			cout << "NO" << nl;
			continue;
		}
		string s = "";
		int node;
		for (int i = 0; i < 26; i++) {
			if (adjLists[i].size() == 1) {
				node = i;
				break;
			}
		}
		unordered_set<int> visited;
		visited.insert(node);
		int orig = node;
		while (true) {
			s += string(1, node + 'a');
			if (node != orig && adjLists[node].size() == 1) {
				break;
			}
			for (int i : adjLists[node]) {
				if (visited.count(i) == 0) {
					node = i;
					visited.insert(i);
				} 
			}
		}	
		for (int i = 0; i < 26; i++) {
			if (adjLists[i].size() == 0) {
				s += string(1, i + 'a');
			}
		}
		cout << "YES" << nl << s << nl;
	}	
}