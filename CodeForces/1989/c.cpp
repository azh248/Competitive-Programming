#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define F0R1(i, a) for (int i = 1; i <= (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i = a; i > 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())
#define S0RT(arr, n) sort(arr, arr + n)

#define pA first
#define pB second
#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n; cin >> n;
        vector<int> a(n);
        FOR(i, 0, n) {
            cin >> a[i];
        }
        vector<int> b(n);
        FOR(i, 0, n) {
            cin >> b[i];
        }
        int bothNeg = 0;
        int bothPos = 0;
        int movie1 = 0;
        int movie2 = 0;
        FOR(i, 0, n) {
            if (a[i] > 0 && b[i] > 0) {
                bothPos++;
            } else if (a[i] < 0 && b[i] < 0) {
                bothNeg++;
            } else if (a[i] > 0 && b[i] == 0) {
                movie1++;
            } else if (a[i] == 0 && b[i] > 0) {
                movie2++;
            } else if (a[i] < 0) {
                movie2 += b[i];
            } else if (b[i] < 0) {
                movie1 += a[i];
            }
        }
        int diff = movie1 - movie2;

        // goal is to make the difference as close to 0 as possible
        while (movie1 > movie2) {
            if (bothNeg > 0) {
                bothNeg--;
                movie1--;
            } else if (bothPos > 0) {
                bothPos--;
                movie2++;
            } else {
                break;
            }
        }
        while (movie2 > movie1) {
            if (bothNeg > 0) {
                bothNeg--;
                movie2--;
            } else if (bothPos > 0) {
                bothPos--;
                movie1++;
            } else {
                break;
            }
        }
        if (bothNeg % 2 == 0 && bothPos % 2 == 0) {
            cout << min(movie1, movie2) + (bothPos - bothNeg) / 2 << nl;
        } else if (bothNeg % 2 == 1 && bothPos % 2 == 1) {
            cout << min(movie1, movie2) + (bothPos - bothNeg) / 2 << nl;
        } else {
            if (bothNeg % 2 == 1) {
                bothNeg--;
                cout << min(movie1, movie2) + (bothPos - bothNeg) / 2 - 1 << nl;
            } else if (bothPos % 2 == 1) {
                bothPos--;
                cout << min(movie1, movie2) + (bothPos - bothNeg) / 2 << nl;
            } else { // SHOULD NOT HAPPEN
                cout << min(movie1, movie2) + (bothPos - bothNeg) / 2 << nl;
            }
        }
	}	
}
