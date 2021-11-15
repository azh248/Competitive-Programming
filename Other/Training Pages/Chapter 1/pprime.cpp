/*
ID:azh248
LANG:C++
TASK:pprime 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int a, b;

// int sieveResult[100000000]{};

bool prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

// void sieve(int n) { // find all prime numbers up to n by marking the composite numbers with their least prime factor
//     for (int i = 2; i <= b; i++) {
//         if (sieveResult[i] != 0)
//             continue;
//         for (int multiple = 2 * i; multiple <= n; multiple += i) {
//             sieveResult[multiple] = i;
//         }
//     }
// }
vector<int> palindromes;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
    cin >> a >> b;
	for (int j = 1; j <= 10000; j++) {
		string s = to_string(j);
		string s1 = s;
		string ret = s;
		reverse(s.begin(), s.end());
		ret += s;
		palindromes.pb(stoi(ret));
		string ret1 = s1;
		s1 = s1.substr(0, s.length() - 1);
		reverse(s1.begin(), s1.end());
		ret1 += s1;
		palindromes.pb(stoi(ret1));
	}
	// for (int i = a; i <= b; i++) {
	// 	string s = to_string(i);
	// 	bool works = true;
	// 	for (int i = 0; i <= s.length()/2; i++) {
	// 		if (s[i] != s[s.length() - 1 - i]) {
	// 			works = false;
	// 			break;
	// 		}
	// 	}
	// 	if (works) {
	// 		palindromes.pb(i);
	// 	}
	// }	
	sort(palindromes.begin(), palindromes.end());
	for (int i : palindromes) {
		if (i >= a && i <= b && prime(i)) {
			cout << i << nl;
		}
	}
}
