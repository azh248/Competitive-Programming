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
		int l; cin >> l;
		vector<int> layers;
		layers.pb(64);
		for (int i = 0; i < l; i++) {
			int layer; cin >> layer;
			layers.pb(layer);
		}
		l++;
		vector<vector<double>> weights[l];
		FOR(i, 1, l) {
			for (int j = 0; j < layers[i]; j++) {
				weights[i].pb({});
				for (int k = 0; k < layers[i - 1]; k++) {
					double weight; cin >> weight;
					weights[i][j].pb(weight);
				}
				double bias; cin >> bias;
				weights[i][j].pb(bias);
			}
		}
		vector<double> neurons[1000];
		for (int i = 0; i < 64; i++) {
			double neuron; cin >> neuron;
			neurons[0].pb(neuron);
		}
		for (int i = 1; i < l; i++) {
			for (int j = 0; j < layers[i]; j++) {
				double sum = 0;
				for (int k = 0; k < layers[i-1]; k++) {
					double weight = weights[i][j][k];
					sum += neurons[i-1][k] * weight;
				}
				double b = weights[i][j][layers[i-1]];
				neurons[i].pb(max((double)0, sum + b));
			}
		}
		double maximum = -1;
		int maxInd = -1;
		for (int i = 0; i < layers[l-1]; i++) {
			if (neurons[l-1][i] > maximum) {
				maximum = neurons[l-1][i];
				maxInd = i;
			}
		}
		vector<string> arr;
		arr.pb("STOP_SIGN");
		arr.pb("YIELD");
		arr.pb("LANE_ENDS");
		arr.pb("SPEED_LIMIT");
		arr.pb("CROSSWALK");
		cout << arr[maxInd] << nl;
	}
}
