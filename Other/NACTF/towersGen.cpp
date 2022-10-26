#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
	return uniform_int_distribution<long long>(l, r)(rng);
}

int main(int argc, char* argv[]) {
	
	freopen("in1.txt", "w", stdout);
	int n = 100000;
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << rnd(1, 1000) << " ";
	}
	cout << endl;
}