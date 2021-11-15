#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n;
pii arr[100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}	
	int minArea = 1e9;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int maxX = 0;
				int minX = 1e9;
				int maxY = 0;
				int minY = 1e9;
				maxX = max(maxX, arr[i].first);
				maxX = max(maxX, arr[j].first);
				maxX = max(maxX, arr[k].first);
				minX = min(minX, arr[i].first);
				minX = min(minX, arr[j].first);
				minX = min(minX, arr[k].first);
				maxY = max(maxY, arr[i].second);
				maxY = max(maxY, arr[j].second);
				maxY = max(maxY, arr[k].second);
				minY = min(minY, arr[i].second);
				minY = min(minY, arr[j].second);
				minY = min(minY, arr[k].second);
				minArea = min(minArea, (maxX - minX)*(maxY - minY));
			}
		}
	}
	cout << minArea << nl;
}
