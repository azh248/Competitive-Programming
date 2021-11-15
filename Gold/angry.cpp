#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
int haybales[50000];

// dp[i] = minimum power to hit all haybales to the left or right of the ith haybale

int Ldp[50000];
int Rdp[50000];

int minPowerL(int haybale) {
	if (haybale < 0) {
		return 1e9;
	} else if (haybale == 0) {
		return 0;
	} else if (Ldp[haybale] != -1) {
		return Ldp[haybale];
	}
	// we find max(haybales[haybale] - haybales[haybale - 1], Ldp[haybale - 1] + 1), then see if skipping that haybale
	// and going to the next one directly would give a lesser minimum blast radius -- repeat this until it doesn't help
	int blastRadius = 1e9; // initial value, we'll try to improve it by skipping a number of bales from 0 upwards
	for (int i = haybale - 1; i >= 0; i--) {
		if (max(haybales[haybale] - haybales[i], minPowerL(i) + 1) <= blastRadius){
			blastRadius = max(haybales[haybale] - haybales[i], minPowerL(i) + 1); 
		} else {
			break; // not sure if this ensures the minimum 
		}
	}
	Ldp[haybale] = blastRadius;
	return blastRadius;
}

int minPowerR(int haybale){
	if (haybale >= n) {
		return 1e9;
	} else if (haybale == n - 1) {
		return 0;
	} else if (Rdp[haybale] != -1) {
		return Rdp[haybale];
	}
	// we find max(haybales[haybale + 1] - haybales[haybale], Rdp[haybale + 1] + 1), then see if skipping that haybale
	// and going to the next one directly would give a lesser minimum blast radius -- repeat this until it doesn't help
	int blastRadius = 1e9; // initial value, we'll try to improve it by skipping a number of bales from 0 upwards
	for (int i = haybale + 1; i < n; i++) {
		if (max(haybales[i] - haybales[haybale], minPowerR(i) + 1) <= blastRadius){
			blastRadius = max(haybales[i] - haybales[haybale], minPowerR(i) + 1); 
		} else {
			break; // not sure if this ensures the minimum 
		}
	}
	Rdp[haybale] = blastRadius;
	return blastRadius;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> haybales[i];
	}	
	sort(haybales, haybales + n);
	// we have 2 dp's -- left dp and right dp, both store the minimum power to hit a haybale such that it would hit every 
	// haybale to the left or right of that haybale. Then, we use two pointers and at each pair of pointers, we 
	// do an explosion there (we can find the minimum explosion radius with our dp arrays) and take the minimum overall 
	memset(Ldp, -1, sizeof(Ldp));
	memset(Rdp, -1, sizeof(Rdp));
	int pointer1 = 0;
	int pointer2 = n - 1;
	double minBlastRadius = 1e9;
	while (pointer1 < pointer2) {
		minBlastRadius = min(minBlastRadius, max((double)(haybales[pointer2] - haybales[pointer1])/2, (double)max(minPowerL(pointer1), minPowerR(pointer2)) + 1));		
		if (minPowerL(pointer1 + 1) < minPowerR(pointer2 - 1)) {
			pointer1++;
		} else {
			pointer2--;
		}
	}
	cout << fixed << setprecision(1) << minBlastRadius << nl;
}
