#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;
pair<int, bool> prevArr[1000001];
int currArr[1000001];

bool cmp(pair<int, bool> a, pair<int, bool> b) {
	if (a.first == b.first) {
		return (a.second && !b.second);
	}
	return (a.first < b.first);
}

int main() {
	freopen("runway_input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> prevArr[i].first;
			prevArr[i].second = false;
		}
		sort(prevArr, prevArr + m);
		ll totalChanges = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> currArr[j];
			}
			sort(currArr, currArr + m);
			
			int stylePtr = 0; // current style that we need to get
			vector<int> changeStyles; // styles that we're missing and need to switch models into
			vector<int> changeModels; // models whose styles need to be changed
			vector<pair<int, bool>> pairs1; 

			for (int j = 0; j < m; j++) {
				if (stylePtr >= m) {
					for (int k = j; k < m; k++) {
						changeModels.pb(k);
					}
					break;
				}
				if (prevArr[j].first == currArr[stylePtr]) { // if the model can continue using their style, we let them since they either used up their under or are the best choice
					pairs1.pb(pii(stylePtr, prevArr[j].second));
					stylePtr++;
				} else if (prevArr[j].first > currArr[stylePtr]) { // we don't have this style, so we'll add it to the queue and then repeat with the same model
					changeStyles.pb(stylePtr);
					stylePtr++;
					j--;
				} else {
					// this model's style isn't used in the next round, so we just add them to the queue of styles to change to so we know what styles we have
					changeModels.pb(j);
				}
			}
			for (int k = stylePtr; k < m; k++) {
				changeStyles.pb(k);
			}

			// we don't have to worry about how we go about assigning models to styles, since they'll 
			// all have used their under styles by the end so all the models are indistinguishable
			for (int j = 0; j < changeModels.size(); j++) {
				totalChanges += ((prevArr[changeModels[j]].second) ? 1 : 0);
			}
			for (int j = 0; j < changeStyles.size(); j++) {
				// the models that have changed into these styles would have already used up their under style either beforehands or to change into this style
				prevArr[changeStyles[j]].second = true;			
			}

			for (int j = 0; j < pairs1.size(); j++) {
				prevArr[pairs1[j].first] = pairs1[j];
			}

			for (int j = 0; j < m; j++) {
				prevArr[j].first = currArr[j];
			}

			sort(prevArr, prevArr + m, cmp); // we sort them so that the models without an available under-style will get their preferred style first
		}
		cout << "Case #" << t1 << ": " << totalChanges << nl;
	}
}