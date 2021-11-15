#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;


vector<int> factorize(int num) { // returns prime factorization
	vector<int> factors;
	for (int i = 2; i * i <= num; i++) {
		while (num % i == 0) {
			factors.pb(i);
			num /= i;
		}
	}
	if (num > 1) {
		factors.pb(num);
	}
	return factors;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> arr = factorize(n);
	sort(arr.begin(), arr.end());
	vector<pii> ret;
	for (int i = 0; i < arr.size(); i++) {
		int count = 1;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j] == arr[i]) {
				count++;
			} else {
				i = j - 1;
				break;
			}
		}
		ret.pb({arr[i], count});
	}
	for (auto i : ret) {
		cout << i.first << " " << i.second << nl;
	}
}
