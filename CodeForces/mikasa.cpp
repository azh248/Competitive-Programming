#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

string decToBase2(int num) {
	string ret = "";
	if (num == 0) {
		ret = "0";
	}
	while (num > 0) {
		ret += to_string(num % 2);
		num /= 2;
	}
	for (int i = 0; i < ret.length() / 2; i++) {
		swap(ret[i], ret[ret.length() - i - 1]);
	}
	return ret;
}

int main() {
	// freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		if ((n | m) == m) {
			string nStr = decToBase2(n);
			string mStr = decToBase2(m);
			string addStr = mStr.substr(0, mStr.length() - nStr.length());
			int stopIndex = -1;
			for (int i = nStr.length() - 1; i >= 0; i--) {
				int mIndex = i + mStr.length() - nStr.length();
				if (mStr[mIndex] == '0') {
					stopIndex = i;
					break;
				}
			}
			for (int i = 0; i < nStr.length(); i++) {
				int mIndex = i + mStr.length() - nStr.length();
				if (i == stopIndex) {
					addStr += "1";
					for (int j = i + 1; j < nStr.length(); j++) {
						addStr += "0";
					}
					cout << stoi(addStr, nullptr, 2) << nl;
					break;
				} else if (i == nStr.length() - 1) {
					cout << m + 1 << nl;
				} else {
					addStr += to_string(((nStr[i] - '0') + (mStr[mIndex] - '0')) % 2);
				}
			}
		} else if (n > m) {
			cout << 0 << nl;
		} else {
			string nStr = decToBase2(n);
			string mStr = decToBase2(m);
			string addStr = mStr.substr(0, mStr.length() - nStr.length());
			// int stopIndex = -1;
			// for (int i = nStr.length() - 1; i >= 0; i--) {
			// 	int mIndex = i + mStr.length() - nStr.length();
			// 	if (mStr[mIndex] == '0' && nStr[i] == '0') {
			// 		stopIndex = i;
			// 		break;
			// 	}
			// }
			for (int i = 0; i < nStr.length(); i++) {
				// if (i == stopIndex) {
				// 	for (int j = i; j < nStr.length(); j++) {
				// 		addStr += "0";
				// 	}
				// 	break;
				// }
				int mIndex = i + mStr.length() - nStr.length(); 
				if (nStr[i] == '1' && mStr[mIndex] == '0') {
					for (int j = i; j < nStr.length(); j++) {
						addStr += "0";
					}
					break;
				} else if (nStr[i] == mStr[mIndex]) {
					addStr += "0";
				} else {
					addStr += "1";
				}
			}
			cout << stoi(addStr, nullptr, 2) << nl;
		}
	}
}