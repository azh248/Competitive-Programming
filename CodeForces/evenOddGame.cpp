#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 1000000007
#define nl "\n"
#define pub push_back
#define pob pop_back()
#define long long long

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n; 
		cin >> n;
		vector<int> nums;
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			nums.pub(num);
		}
		ll aScore = 0;
		ll bScore = 0;
		int turn = 0;
		sort(nums.begin(), nums.end());
		for (int j = n - 1; j >= 0; j--) {
			int lastNum = nums[j];
			if (turn == 0) {
				turn = 1;
				if (lastNum % 2 == 0) {
					aScore += lastNum;
				}
			} else {
				turn = 0;
				if (lastNum % 2 == 1) {
					bScore += lastNum;
				}
			}
		}

		if (aScore > bScore) {
			cout << "Alice" << nl;
		} else if (aScore < bScore) {
			cout << "Bob" << nl;
		} else {
			cout << "Tie" << nl;
		}
	}
}
