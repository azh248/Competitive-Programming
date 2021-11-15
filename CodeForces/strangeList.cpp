#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n" 
#define pub push_back
#define pob pop_back
#define long long long

int powOf(int num, int div) {
	int pow = 0;
	while (num % div == 0) {
		num /= div;
		pow++;
	}
	return pow;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
    cin >> t;
    for (int w = 0; w < t; w++) {
		ll n, x;
		cin >> n >> x;
		ll sum = 0;
		vector<ll> arr;
		for (int i = 0; i < n; i++) {
			ll num;
			cin >> num;
			arr.pub(num);
		}
		// find least power of x, all powers of every number before that (a1/x^n, a2/x^n, a3/x^n, a4/x^n, etc.) and at the end only do up to the number of least power
		ll minPower = 1000000000;
		ll minPowIndex = n - 1;
		for (int i = 0; i < n; i++) {
			if (powOf(arr[i], x) < minPower) {
				minPower = powOf(arr[i], x);
				minPowIndex = i;
			}
		}
		for (int i = 0; i < n; i++) {
			ll power = powOf(arr[i], x);
			sum += arr[i] * (minPower + 1);
		}
		for (int i = 0; i < minPowIndex; i++) {
			sum += arr[i];
		}

		cout << sum << nl;
    }
}
