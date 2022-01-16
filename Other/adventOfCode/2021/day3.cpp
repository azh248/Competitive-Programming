#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define pA first
#define pB second
#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;

int main() {
	freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<string> nums;
	vector<string> nums1;
	string var;
	while (cin >> var) {
		nums.pb(var);
	}
	int arr[12]{};
	for (string i : nums) {
		int cnt = 0;
		for (int j = 0; j < 12; j++) {
			if (i[j] == '1') {
				arr[j]++;
			}
		}
	}
	nums1 = nums;
	ll num1;
	ll num2;
	for (int i = 0; i < 12; i++) {
		if (nums.size() == 1) {
			break;
		}
		vector<string> newNums;
		int oneCnt = 0;
		for (string j : nums) {
			if (j[i] == '1') {
				oneCnt++;
			}
		}
		if (oneCnt * 2 >= nums.size()) {
			for (string j : nums) {
				if (j[i] == '1') {
					newNums.pb(j);
				}
			}
		} else {
			for (string j : nums) {
				if (j[i] == '0') {
					newNums.pb(j);
				}
			}
		}
		nums = newNums;
	}
	for (int i = 0; i < 12; i++) {
		if (nums1.size() == 1) {
			break;
		}
		vector<string> newNums1;
		int zeroCnt = 0;
		for (string j : nums1) {
			if (j[i] == '0') {
				zeroCnt++;
			}
		}
		if (zeroCnt * 2 <= nums1.size()) {
			for (string j : nums1) {
				if (j[i] == '0') {
					newNums1.pb(j);
				}
			}
		} else {
			for (string j : nums1) {
				if (j[i] == '1') {
					newNums1.pb(j);
				}
			}
		}
		nums1 = newNums1;
	}
		num2 = stoll(nums1[0], nullptr, 2);
		num1 = stoll(nums[0], nullptr, 2);
		cout << num1 << " " << num2 << nl;
		cout << num1 * num2 << nl;
}