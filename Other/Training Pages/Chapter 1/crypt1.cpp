/*
ID: azh248
LANG: C++
TASK: crypt1
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 1000000007
#define F0R(j, n) for (int i = j; i < n; i++)
#define nl endl
#define pub push_back
#define pob pop_back

int n;
vector<int> digits;

vector<int> getDigits(int num) {
	vector<int> digs;
	while (num > 0) {
		int digit = num % 10;
		num -= digit;
		num /= 10;
		digs.pub(digit);
	}
	return digs;
}
int main() {
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
    cin >> n;
	F0R(0, n) {
		int digit;
		cin >> digit;
		digits.pub(digit);
	}
	int workingSols = 0;
	for (int a : digits) {
		for (int b : digits) {
			for (int c : digits) {
				for (int d : digits) {
					for (int e : digits) {
						int num1 = 100*a + 10*b + c;
						int num2 = 10*d + e;
						vector<int> digits1 = getDigits(num1 * e);
						vector<int> digits2 = getDigits(num1 * d);
						vector<int> digits3 = getDigits(num1 * num2);
						if (digits1.size() == 3 && digits2.size() == 3 && digits3.size() == 4) {
							bool worked = true;
							for (int i : digits1) {
								if (count(digits.begin(), digits.end(), i) == 0) {
									worked = false;
									break;
								}
							}
							for (int i : digits2) {
                                if (count(digits.begin(), digits.end(), i) == 0) {
									worked = false;
                                    break;
                                }
                            }
							for (int i : digits3) {
                                if (count(digits.begin(), digits.end(), i) == 0) {
									worked = false;
                                    break;
                                }
                            }
							if (worked) {workingSols++;}
						}
					}
				}
			}
		}
	}
	cout << workingSols << nl;
}
