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
    freopen("secondHands.in", "r", stdin);
    freopen("secondHands.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
        int n, k; cin >> n >> k;
        vector<int> styles;
        unordered_map<int, int> styleCount;
        FOR(i, 0, n) {
            int s; cin >> s;
            styles.pb(s);
            if (styleCount.find(s) == styleCount.end()) styleCount[s] = 1;
            else styleCount[s]++;
        }
        SORT(styles);
        unordered_set<int> a;
        unordered_set<int> b;
        bool works = true;
        for (int i = 0; i < n; i++) {
            if (styleCount[styles[i]] >= 3) {
                works = false;
                break;
            } else if (styleCount[styles[i]] == 2) {
                if (a.count(styles[i]) == 0) {
                    if (a.size() == k) {
                        works = false;
                        break;
                    }
                    a.insert(styles[i]);
                } else {
                    if (b.size() == k) {
                        works = false;
                        break;
                    }
                    b.insert(styles[i]);
                }
            } else {
                if (a.size() > b.size()) {
                    if (b.size() == k) {
                        works = false;
                        break;
                    }
                    b.insert(styles[i]);
                } else {
                    if (a.size() == k) {
                        works = false;
                        break;
                    }
                    a.insert(styles[i]);
                }
            }

        }

		cout << "Case #" << t1 << ": " << (works ? "YES" : "NO") << nl;		
	}	
}