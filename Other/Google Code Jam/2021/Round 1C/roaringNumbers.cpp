#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

bool roaring(int num) {
	string s = to_string(num);
	for (int i = 1; i <= s.length()/2; i++) {
		string s1 = "";
		int num = 0;
		for (int j = 0; j < i; j++) {
			num *= 10;
			num += s[j] - '0';
		}
		while (s1.length() < s.length()) {
			s1 += to_string(num);
			num++;
		}
		if (s1 == s) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int nextRoaring[(int)2e6];
	nextRoaring[(int)2e6 - 1] = -1;
	for (int i = 2e6 - 1; i >= 0; i--) {
		if (roaring(i + 1)) {
			nextRoaring[i] = i + 1;
		} else {
			nextRoaring[i] = nextRoaring[i + 1];
		}
	}
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		int num;
		cin >> num;
		cout << "Case #" << t1 << ": " << nextRoaring[num] << nl;			
	}	
}