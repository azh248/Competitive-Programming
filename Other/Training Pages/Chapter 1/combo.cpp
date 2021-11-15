/*
ID: azh248
LANG: C++
TASK: combo
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 1000000007
#define nl endl
#define pub push_back
#define pob pop_back

int n;
vector<tuple<int, int, int> > possibleCombos;

int main() {
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
    cin >> n;
	int arr1[3];
	int arr2[3];
	cin >> arr1[0] >> arr1[1] >> arr1[2] >> arr2[0] >> arr2[1] >> arr2[2];
	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			for (int k = -2; k <= 2; k++) {
				tuple<int, int, int> tuple1 = {(arr1[0] + i + n)%n, (arr1[1] + j + n)%n, (arr1[2] + k + n)%n};
                tuple<int, int, int> tuple2 = {(arr2[0] + i + n) % n, (arr2[1] + j + n) % n, (arr2[2] + k + n) % n};
				bool tuple1Works = true;
				for (tuple<int, int, int> tuple3 : possibleCombos) {
                    if (get<0>(tuple1) == get<0>(tuple3) && get<1>(tuple1) == get<1>(tuple3) && get<2>(tuple1) == get<2>(tuple3)) {
						tuple1Works = false;
						break;
					}   
	            }
				if (tuple1Works) {
					possibleCombos.pub(tuple1);
				}
				bool tuple2Works = true;
                for (tuple<int, int, int> tuple3 : possibleCombos) {
                    if (get<0>(tuple2) == get<0>(tuple3) && get<1>(tuple2) == get<1>(tuple3) && get<2>(tuple2) == get<2>(tuple3)) {
                        tuple2Works = false;
                        break;
                    }
                }
				if (tuple2Works) {
					possibleCombos.pub(tuple2);
				}
            }
		}
	}
	int size = possibleCombos.size();
	cout << size << nl;
}
