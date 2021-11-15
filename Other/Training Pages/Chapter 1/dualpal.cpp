/*
ID: azh248
LANG: C++
TASK: dualpal
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 1000000007
#define F0R(j, n) for (int i = j; i < n; i++)
#define nl endl
#define pub push_back
#define pob pop_back

int n, s;

string baseB(int n, int b) {
    string ret = "";
    while (n != 0) {
        int remainder = n % b;
        if (remainder < 10) {
            ret = to_string(remainder) + ret;
        } else {
            ret = string(1, ((char)(remainder - 10 + 'A'))) + ret;
        }
        n -= remainder;
        n /= b;
    }
    return ret;
}

bool is_palindrome(string s) {
    F0R(0, s.length() / 2) {
        if (s[i] != s[s.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);
    cin >> n >> s;
	while (n > 0) {
		s++;
		int works = 0;
		F0R(2, 11) {
			if (is_palindrome(baseB(s, i))) {
				works++;
			}
		}
		if (works >= 2) {
			cout << s << nl;
			n--;
		}
	}
}
