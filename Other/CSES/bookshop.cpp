#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 1000000007
#define nl endl
#define pub push_back
#define pob pop_back

int bookDetails[1000][2];
int n, x;

int maxPages(int maxPrice, int book, unordered_set<int> booksBought) {
    booksBought.insert(book);
    unordered_set<int> booksBoughtNew = booksBought;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (booksBought.count(i) == 0) {
            booksBoughtNew.insert(i);
			if (bookDetails[i][0] <= maxPrice) {
            	ret = max(ret, maxPages(maxPrice - bookDetails[i][0], i, booksBoughtNew) + bookDetails[i][1]);
			}
            booksBoughtNew.erase(i);
        }
    }
    return ret;
}

int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> bookDetails[i][0];
	}
	for (int i = 0; i < n; i++) {
		cin >> bookDetails[i][1];
	}
	unordered_set<int> booksBought;
	cout << maxPages(x, -1, booksBought) << nl;
}
