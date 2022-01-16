#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define pA first
#define pB second
#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
pair<pii, pii> arr[500];
int mark[1000][1000]{};

int main() {
	freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int ind = 0;
	string s;
	while (cin >> s) {
		int num = 0;
		bool comma = false;
		for (int i = 0; i < s.length(); i++) {
			num *= 10;
			num += (s[i] - '0');
			if (!comma && (s[i + 1] == ',')) {
				comma = true;
				arr[ind].pA.pA = num;
				num = 0;
				i++;
			}
		}
		arr[ind].pA.pB = num;
		string bruh;
		cin >> bruh;
		string s1;
		cin >> s1;
		num = 0;
		comma = false;
		for (int i = 0; i < s1.length(); i++) {
			num *= 10;
			num += (s1[i] - '0');
			if (!comma && (s1[i + 1] == ',')) {
				comma = true;
				arr[ind].pB.pA = num;
				num = 0;
				i++;
			}
		}
		arr[ind].pB.pB = num;
		if (!((arr[ind].pB.pA == arr[ind].pA.pA) || (arr[ind].pB.pB == arr[ind].pA.pB) || (abs(arr[ind].pB.pB - arr[ind].pA.pB) == abs(arr[ind].pA.pA - arr[ind].pB.pA)))) {
			continue;
		}
		ind++;
	}
	cout << arr[1].pA.pA << " " << arr[1].pA.pB << " " << arr[1].pB.pA << " " << arr[1].pB.pB << " " << nl;
	for (int i = 0; i < ind; i++) {
		if (arr[i].pA.pA == arr[i].pB.pA) {
			int small = min(arr[i].pA.pB, arr[i].pB.pB);
			int large = max(arr[i].pA.pB, arr[i].pB.pB);
			for (int j = small; j <= large; j++) {
				mark[arr[i].pA.pA][j]++;
			}
		} else if (arr[i].pA.pB == arr[i].pB.pB) {
			int small = min(arr[i].pA.pA, arr[i].pB.pA);
			int large = max(arr[i].pA.pA, arr[i].pB.pA);
			for (int j = small; j <= large; j++) {
				mark[j][arr[i].pB.pB]++;
			}
		} else {
			if (arr[i].pA.pB >= arr[i].pB.pB) {
				if (arr[i].pA.pA >= arr[i].pB.pA) {
					for (int j = 0; j <= (arr[i].pA.pB - arr[i].pB.pB); j++) {
						mark[arr[i].pB.pA + j][arr[i].pB.pB + j]++;
					}
				} else {
					for (int j = 0; j <= (arr[i].pA.pB - arr[i].pB.pB); j++) {
						mark[arr[i].pA.pA + j][arr[i].pA.pB - j]++;
					}
				}
			} else {
				if (arr[i].pA.pA > arr[i].pB.pA) {
					for (int j = 0; j <= (arr[i].pB.pB - arr[i].pA.pB); j++) {
						mark[arr[i].pA.pA - j][arr[i].pA.pB + j]++;
					}
				} else {
					for (int j = 0; j <= (arr[i].pB.pB - arr[i].pA.pB); j++) {
						mark[arr[i].pA.pA + j][arr[i].pA.pB + j]++;
					}
				}
			}
		}
		// for (int j = min(arr[i].pA.pA, arr[i].pB.pA); j <= max(arr[i].pA.pA, arr[i].pB.pA); j++) {
		// 	for (int k = min(arr[i].pA.pB, arr[i].pB.pB); k <= max(arr[i].pA.pB, arr[i].pB.pB); k++) {
		// 		assert(((arr[i].pB.pA - arr[i].pA.pA) == 0) || ((arr[i].pB.pB - arr[i].pA.pB) == 0));
		// 		mark[j][k]++;
		// 	}
		// }
	}
	int num = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if (mark[i][j] >= 2) {
				num++;
			}
		}
	}
	cout << num << nl;
}