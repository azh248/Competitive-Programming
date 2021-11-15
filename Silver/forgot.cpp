#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int l, n;
string phrase;
string words[1000];

string dp[1000];

string minWord(int index) {
	if (index > l) {
		return "0";
	} else if (index == l) {
		return "";
	} else if (dp[index] != "-1") {
		return dp[index];
	}
	string word = "0";
	for (int i = 0; i < n; i++) {
		if (index + words[i].length() > l) {
			continue;
		}
		bool works = true;
		for (int j = index; j < index + words[i].length(); j++) {
			if (phrase[j] != '?') {
				if (phrase[j] != words[i][j - index]) {
					works = false;
					break;
				}
			}
		}
		if (!works) {
			continue;
		}
		if (minWord(index + words[i].length()) != "0") {
			string result = words[i] + minWord(index + words[i].length());
			for (int j = i + 1; j < n; j++) {
				if (words[j].length() < words[i].length()) {
					break;
				}
				for (int k = 0; k < words[i].length(); k++) {
					if (words[i][k] != words[j][k]) {
						works = false;
						break;
					}
				}
				if (!works) {
					break;
				}
				string nextResult = words[j] + minWord(index + words[j].length());
				if (minWord(index + words[j].length()) != "0") {
					result = min(result, nextResult); 
				}
			}
			word = result;
			break;
		}
	}
	dp[index] = word;
	return word;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> n;
	cin >> phrase;
	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}	
	sort(words, words + n);
	for (int i = 0; i < 1000; i++) {
		dp[i] = "-1";
	}
	cout << minWord(0) << nl;
}
