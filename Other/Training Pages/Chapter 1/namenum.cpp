/*
ID: azh248
LANG: C++
TASK: namenum
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 1000000007
#define F0RI(a, n) for (int i = a; i < n; i++)
#define F0RJ(a, n) for (int j = a; j < n; j++)
#define F0RK(a, n) for (int k = a; k < n; k++)
#define nl endl
#define pub push_back
#define pob pop_back

ll id;
unordered_map<char, int> touchTone = {{'A', 2}, {'B', 2}, {'C', 2}, {'D', 3}, {'E', 3}, {'F', 3}, {'G', 4}, {'H', 4}, {'I', 4}, {'J', 5}, {'K', 5}, {'L', 5}, {'M', 6}, {'N', 6}, {'O', 6}, {'P', 7}, {'R', 7}, {'S', 7}, {'T', 8}, {'U', 8}, {'V', 8}, {'W', 9}, {'X', 9}, {'Y', 9}};
vector<ll> workingIDs;
vector<string> workingNames;

int main() {
	ifstream dict ("dict.txt");
	while (true) {
		string name;
		dict >> name;
		ll workingID = 0;
		F0RI(0, name.length()) {
			workingID += pow(10, name.length() - i - 1) * touchTone[name[i]];
		}
		workingIDs.pub(workingID);
		workingNames.pub(name);
		if (name == "ZYTA") {
			break;
		}
	}
	
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    cin >> id;

	bool worked = false;

	F0RI(0, workingIDs.size()) {
		if (workingIDs[i] == id) {
			cout << workingNames[i] << nl;
			worked = true;
		}
	}
	if (!worked) {
		cout << "NONE" << nl;
	}
}
