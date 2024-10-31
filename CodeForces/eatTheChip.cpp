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
		int h, w, x1, y1, x2, y2; cin >> h >> w >> x1 >> y1 >> x2 >> y2;
        if (x2 <= x1) {
            cout << "Draw" << nl;
        } else if ((x2 - x1) % 2 == 1) {
            // only alice (x1, y1) can win
            while (x2 > x1) {
                // game over
                if (x2 - x1 == 1) {
                    if (abs(y2 - y1) <= 1) {
                        cout << "Alice" << nl;
                    } else {
                        cout << "Draw" << nl;
                    }
                    break;
                }

                // alice's move
                x1 += 1;
                if (y1 < y2) {
                    if (y1 < w) {
                        y1 += 1;
                    }
                } else if (y1 > y2) {
                    if (y1 > 1) {
                        y1 -= 1;
                    }
                } else {
                    // nothing happens bc alice just moves straight down
                }

                // bob's move
                x2 -= 1;
                if (y2 > y1) {
                    if (y2 < w) {
                        y2 += 1;
                    }
                } else if (y2 < y1) {
                    if (y2 > 1) {
                        y2 -= 1;
                    }
                } else {
                    // nothing bob can do here
                    cout << "Alice" << nl;
                    break;
                }

                // somehow game over
                if (x2 < 1 || x1 > h) {
                    cout << "Draw" << nl;
                    break;
                }
            }
        } else {
            // only bob (x2, y2) can win
            while (x2 > x1) {
                // alice's move
                x1 += 1;
                if (y1 < y2) {
                    if (y1 > 1) {
                        y1 -= 1;
                    }
                } else if (y1 > y2) {
                    if (y1 < w) {
                        y1 += 1;
                    }
                } else {
                    // nothing alice can do here
                    cout << "Bob" << nl;
                    break;
                }

                // game over
                if (x2 - x1 == 1) {
                    if (abs(y2 - y1) <= 1) {
                        cout << "Bob" << nl;
                    } else {
                        cout << "Draw" << nl;
                    }
                    break;
                }

                // bob's move
                x2 -= 1;
                if (y2 > y1) {
                    if (y2 > 1) {
                        y2 -= 1;
                    }
                } else if (y2 < y1) {
                    if (y2 < w) {
                        y2 += 1;
                    }
                } else {
                    // bob just moves straight up
                }

                // somehow game over
                if (x2 < 1 || x1 > h) {
                    cout << "Draw" << nl;
                    break;
                }
            }
        }
	}	
}
