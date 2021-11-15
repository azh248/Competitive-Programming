#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

string str;
double d, s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> str >> s >> d;
	int hrs = 10 * (str[0] - '0') + (str[1] - '0');
	int mins = 10 * (str[3] - '0') + (str[4] - '0');
	hrs += floor(d/s);
	mins += floor((60 * (d/s - floor(d/s)) + 0.0001));
	hrs += floor(mins/60);
	hrs %= 24;
	mins %= 60;
	cout << ((hrs < 10) ? "0" : "") << hrs << ":" << ((mins < 10) ? "0" : "") << mins << nl;
}
