#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define pA first
#define pB second
#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, q;
int classNum[100000];
int room[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> classNum[i];
		classNum[i]--;
		room[classNum[i]] = i;
	}
	int currRoom = room[0];
	for (int i = 0; i < q; i++) {
		int num;
		cin >> num;
		num--;
		if (room[num] > currRoom) {
			cout << "Right ";
		} else {
			cout << "Left ";
		}
		cout << abs(room[num] - currRoom) << nl;
		currRoom = room[num];
	}
}