#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}	
	int longestL, longestR;
	int longestSegment = 0;
	int l = 0;
	int r = -1;
	int elementCount[1000000]{};
	int diffElements = 0;
	while (r < n - 1) {
		if (diffElements + ((elementCount[arr[r + 1]] == 0) ? 1 : 0) <= k) {
			if (elementCount[arr[r + 1]] == 0){
				diffElements++;
			}
			r++;
			elementCount[arr[r]]++;
		} else {
			if (elementCount[arr[l]] == 1) {
				diffElements--;
			}
			elementCount[arr[l]]--;
			l++;
		}
		if (r - l + 1 > longestSegment)	{
			longestSegment = r - l + 1;
			longestL = l;
			longestR = r;
		}
	}
	cout << longestL + 1 << " " << longestR + 1 << nl;
}
