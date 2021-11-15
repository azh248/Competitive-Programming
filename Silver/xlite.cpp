#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int n, t;

pii dp[50][128]; // dp[i][j] = min lights lit from index i onwards if the next 7 lights are j (convert to binary)

string decToBin(int dec) {
	string bin = "";
	while (dec > 0) {
		bin = to_string(dec % 2) + bin;
		dec /= 2;
	}
	while (bin.length() < t) {
		bin = "0" + bin;
	}
	return bin;
}

string initialLights;
string pitchfork;

pii minLit(int light, int nextLights) {
	if (dp[light][nextLights].first != -1) {
		return dp[light][nextLights];
	} else if (light >= n - t) {
		int num = 0;
		string nextLightsBin = decToBin(nextLights);
		for (int i = light; i < n; i++) {
			num += (nextLightsBin[i - light] - '0');
		}
		for (int i = 0; i < t; i++) { // using the pitchfork
			nextLightsBin.replace(i, 1, to_string((((nextLightsBin[i]) - '0') + (pitchfork[i] - '0')) % 2));
		}
		int pitchforkNum = 0;
		for (int i = light; i < n; i++) {
			pitchforkNum += (nextLightsBin[i - light] - '0');
		}
		if (pitchforkNum < num) {
			return {pitchforkNum, 1};
		} else {
			return {num, 0};
		}
	} 
	string nextLightsBin = decToBin(nextLights);
	pii noPress = minLit(light + 1, stoi(nextLightsBin.substr(1, t - 1) + to_string(initialLights[light + t] - '0'), nullptr, 2));
	noPress.first += (nextLightsBin[0] - '0');
	for (int i = 0; i < t; i++) { // using the pitchfork
		nextLightsBin.replace(i, 1, to_string((((nextLightsBin[i]) - '0') + (pitchfork[i] - '0')) % 2));
	}
	pii press = minLit(light + 1, stoi(nextLightsBin.substr(1, t - 1) + to_string(initialLights[light + t] - '0'), nullptr, 2));
	press.first += (nextLightsBin[0] - '0');
	press.second++;
	if (press.first < noPress.first) {
		dp[light][nextLights] = press;
		return press;
	} else if (noPress.first < press.first) {
		dp[light][nextLights] = noPress;
		return noPress; 
	} else {
		if (press.second < noPress.second) {
			dp[light][nextLights] = press;
			return press;
		} else {
			dp[light][nextLights] = noPress;
			return noPress; 
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t >> initialLights >> pitchfork;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 128; j++) {
			dp[i][j] = {-1, -1};
		}
	}
	cout << minLit(0, stoi(initialLights.substr(0, t), nullptr, 2)).second << nl;
}
