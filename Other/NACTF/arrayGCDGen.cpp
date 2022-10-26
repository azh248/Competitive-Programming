#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
	return uniform_int_distribution<long long>(l, r)(rng);
}

int main(int argc, char *argv[]) {
	freopen("in1.txt", "w", stdout);
	freopen("primes.txt", "r", stdin);
	std::srand(unsigned(std::time(0)));
	int n = 100000;
	int m = 50;
	cout << n << " " << m << endl;
	vector<long long> arr1 = {};
	for (int i = 1; i <= n; i++) {
		arr1.push_back(rnd(1, 1e18));
	}
	sort(arr1.begin(), arr1.end());
	for (long long i : arr1) {
		cout << i << " ";
	}
	cout << endl;
	vector<long long> bigPrimes;
	long long bigPrime;
	while (cin >> bigPrime) {
		bigPrimes.push_back(bigPrime);
	}
	set<int> arr;
	while (arr.size() < 10) {
		int num = rnd(2, 500);
		bool prime = true;
		for (int i = 2; i * i <= num; i++) {
			if (num % i == 0) {
				prime = false;
				break;
			}
		}
		if (prime) {
			arr.insert(num);
		}
	}
	auto it = arr.begin();
	for (int i = 0; i < 10; i++) {
		cout << *it << " " << rnd(2, 100000) << endl;
		it++;
	}
	for (int i = 0; i < 40; i++) {
		cout << bigPrimes[i] << " " << rnd(2, 100000) << endl;
	}
	freopen("primes.txt", "w", stdout);
	for (int i = 40; i < bigPrimes.size(); i++) {
		cout << bigPrimes[i] << endl;
	}
}