#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
	return uniform_int_distribution<long long>(l, r)(rng);
}

int myrand(int i) { return rand() % i; }

int main(int argc, char* argv[]) {
	freopen("in1.txt", "w", stdout);
	std::srand(unsigned(std::time(0)));
	int n = 100000;
	int q = 100000;
	cout << n << " " << q << endl;
	vector<int> vec;
	for (int i = 1; i <= n; i++) {
		vec.push_back(i);
	}
	random_shuffle(vec.begin(), vec.end(), myrand);
	for (int i : vec) {
		cout << i << " ";
	}
	cout << endl;
	int prevRoom = -1;
	for (int i = 0; i < q; i++) {
		int num = rnd(1, n);
		while (num == prevRoom) {
			num = rnd(1, n);
		}
		cout << num << endl;
		prevRoom = num;
	}
}