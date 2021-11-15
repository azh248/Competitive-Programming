#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		string s; cin >> s;
		int consonants = 0, vowels = 0;
		int maxOccurrenceConsonant = 0, maxOccurrenceVowel = 0;
		int vowelOccurrences[30]{};
		int consonantOccurrences[30]{};
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
				vowels++;
				vowelOccurrences[s[i] - 'A']++;
			} else {
				consonants++;
				consonantOccurrences[s[i] - 'A']++;
			}
		}
		for (int i = 0; i < 30; i++) {
			maxOccurrenceConsonant = max(maxOccurrenceConsonant, consonantOccurrences[i]);
			maxOccurrenceVowel = max(maxOccurrenceVowel, vowelOccurrences[i]);
		}
		cout << "Case #" << t1 << ": " << min((consonants - maxOccurrenceConsonant) * 2 + vowels, (vowels - maxOccurrenceVowel) * 2 + consonants) << nl;
	}
}