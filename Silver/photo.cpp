#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
map<int, int> position[5];
int arr[20000];

bool cmp(int a, int b) {
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (position[i][a] < position[i][b]) {
			cnt++;
		}
	}
	return (cnt >= 3);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		position[0].insert({arr[i], i});
	}
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			position[i].insert({num, j});
		}
	}
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << nl;
	}
}
