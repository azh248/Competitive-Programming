/*
ID: azh248
LANG: C++
TASK: palsquare
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 1000000007
#define F0R(j, n) for (int i = j; i < n; i++)
#define nl endl
#define pub push_back
#define pob pop_back

int base;

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
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
    cin >> base;
	F0R(1, 301) {
		int n = i;
		int squared = pow(n, 2);
		string squaredBaseB = baseB(squared, base);
		if (is_palindrome(squaredBaseB)) {
			cout << baseB(n, base) << " " << squaredBaseB << nl;
		}
	}
}
