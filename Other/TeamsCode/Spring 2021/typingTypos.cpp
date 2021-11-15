#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
string s;
int arr[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}	
	string ret = "";
	ret += s[0];
	for (int i = 1; i < n; i++) {
		ret += s[i - arr[i]];
		s[i] = ret[i];
	}
	cout << ret << nl;
}
