/*
ID:azh248
LANG:C++
TASK:cbarn 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"; 
#define pb push_back

int n;
int arr[100000];

int main() {
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];		
	}	
	int start;
	int total = 0;
	int curr = 0;
	for (int i = 0; i < 2 * n; i++) {
		total += arr[i % n] - 1;
		curr++;
		if (total < 0) {
			total = 0;
			curr = 0;
		} else if (curr == n) {
			start = (i + 1) % n;
		}

	}
	ll energy = 0;
	priority_queue<ll, vector<ll>, greater<ll> > cows;
	for (int i = start; i < start + n; i++) {
		for (int j = 0; j < arr[i % n]; j++) {
			cows.push(i);
		}
		if (cows.empty()) {
			energy = 1e9;
			break;
		}
		energy += (i - cows.top()) * (i - cows.top());
		cows.pop();
	}
	cout << energy << nl;
}
