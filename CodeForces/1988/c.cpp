#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define F0R1(i, a) for (int i = 1; i <= (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i = a; i > 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())
#define S0RT(arr, n) sort(arr, arr + n)

#define pA first
#define pB second
#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

string decToBase2(ll num) {
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
        ll n; cin >> n;
        string s = decToBase2(n);
        int ones = 0;
        FOR(i, 0, s.length()) {
            if (s[i] == '1') {
                ones++;
            }
        }
        if (ones == 1) {
            cout << 1 << nl;
            cout << n << nl;
            continue;
        }
        cout << ones + 1 << nl;
        FOR(i, 0, s.length()) {
            if (s[i] == '1') {
                string s1 = s;
                s1[i] = '0';
                ll num = stoll(s1, nullptr, 2);
                cout << num << " ";
            }
        }
        cout << n << nl;
	}	
}
