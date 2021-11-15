#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int s, d, n, m;

class cmp {
	public:
		bool operator()(pii a, pii b) {
			return a.second > b.second;
		}
};

int timeTo[300];
vector<pii> adjLists[300];
int startingColor[300];
int startingTime[300];
int cycle[300][2];

void dijkstra(int root) {
	fill(timeTo, timeTo + n, 1e9);
	timeTo[root] = 0;
	priority_queue<pii, vector<pii>, cmp> nodes; 
	nodes.push(make_pair(root, 0));
	while (!nodes.empty()) { // continously process the closest unvisited node
							 // and later process its neighbors
		int minTimeNode = nodes.top().first; // min timeTo to starting node
		int currTime = nodes.top().second;
		nodes.pop();
		if (currTime != timeTo[minTimeNode]) {
			continue;
		}
		int currColor1;
		int remTime1;
		int currTime1 = currTime;
		if (startingTime[minTimeNode] + currTime1 >= cycle[minTimeNode][startingColor[minTimeNode]]) {
			currTime1 += startingTime[minTimeNode];
			currColor1 = startingColor[minTimeNode];
			currTime1 %= (cycle[minTimeNode][0] + cycle[minTimeNode][1]);
			if (currTime1 >= cycle[minTimeNode][currColor1]) {
				remTime1 = currTime1 - cycle[minTimeNode][currColor1];
				currColor1++;
				currColor1 %= 2;
			} else {
				remTime1 = currTime1;
			}
		} else {
			currColor1 = startingColor[minTimeNode];
			remTime1 = startingTime[minTimeNode] + currTime1;
		}
		for (pii i : adjLists[minTimeNode]) {
			int neighbor = i.first;
			int length = i.second;
			int waitingTime = 0;
			if (timeTo[minTimeNode] + waitingTime + length >= timeTo[neighbor]) {
				continue;
			}
			int currColor2;
			int remTime2;
			int currTime2 = currTime;
			if (startingTime[neighbor] + currTime2 >= cycle[neighbor][startingColor[neighbor]]) {
				currTime2 += startingTime[neighbor];
				currColor2 = startingColor[neighbor];
				currTime2 %= (cycle[neighbor][0] + cycle[neighbor][1]);
				if (currTime2 >= cycle[neighbor][currColor2]) {
					remTime2 = currTime2 - cycle[neighbor][currColor2];
					currColor2++;
					currColor2 %= 2;
				} else {
					remTime2 = currTime2;
				}
			} else {
				currColor2 = startingColor[neighbor];
				remTime2 = startingTime[neighbor] + currTime2;
			}
			int currColor1Temp = currColor1;
			if (currColor1Temp == currColor2) {
				timeTo[neighbor] = timeTo[minTimeNode] + length;
				nodes.push(make_pair(neighbor, timeTo[neighbor])); // process the neighbor later
				continue;
			} else {
				if (cycle[minTimeNode][currColor1Temp] - remTime1 < cycle[neighbor][currColor2] - remTime2) {
					waitingTime += cycle[minTimeNode][currColor1Temp] - remTime1;
					remTime2 += cycle[minTimeNode][currColor1Temp] - remTime1;
					currColor1Temp++;
					currColor1Temp %= 2;
				} else {
					int addTime = cycle[minTimeNode][currColor1Temp] - remTime1;
					waitingTime += addTime;
					addTime -= (cycle[neighbor][currColor2] - remTime2);
					remTime2 = 0;
					currColor2++;
					currColor2 %= 2;
					addTime %= (cycle[neighbor][0] + cycle[neighbor][1]);
					if (addTime >= cycle[neighbor][currColor2]) {
						addTime -= cycle[neighbor][currColor2];
						currColor2++;
						currColor2 %= 2;
					}
					remTime2 = addTime;
					currColor1Temp++;
					currColor1Temp %= 2;
				}
			}
			if (timeTo[minTimeNode] + waitingTime + length >=
				timeTo[neighbor]) {
				continue;
			}
			if (currColor1Temp == currColor2) {
				timeTo[neighbor] = timeTo[minTimeNode] + waitingTime + length;
				nodes.push(make_pair(neighbor, timeTo[neighbor])); // process the neighbor later
				continue;
			}
			if ((cycle[minTimeNode][0] == cycle[neighbor][1]) && (cycle[minTimeNode][1] == cycle[neighbor][0]) && (remTime2 == 0)) {
				continue;
			}
			if (cycle[minTimeNode][currColor1Temp] == cycle[neighbor][currColor2] - remTime2) {
				waitingTime += cycle[minTimeNode][currColor1Temp];
				currColor2++;
				currColor2 %= 2;
				currColor1Temp++;
				currColor1Temp %= 2;
				if (cycle[minTimeNode][currColor1Temp] == cycle[neighbor][currColor2]) {
					waitingTime += cycle[minTimeNode][currColor1Temp];
					currColor2++;
					currColor2 %= 2;
					currColor1Temp++;
					currColor1Temp %= 2;
				}
				waitingTime += min(cycle[minTimeNode][currColor1Temp], cycle[neighbor][currColor2]);
			} else {
				waitingTime += min(cycle[minTimeNode][currColor1Temp], cycle[neighbor][currColor2] - remTime2);
			}
			if (timeTo[minTimeNode] + waitingTime + length >=
				timeTo[neighbor]) {
				continue;
			}
			timeTo[neighbor] = timeTo[minTimeNode] + waitingTime + length;
			nodes.push(make_pair(neighbor, timeTo[neighbor])); // process the neighbor later
		}
	}
}

int main() {
	freopen("!.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> d >> n >> m;
	s--;
	d--;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		startingColor[i] = (x == "P");
		int remaining;
		cin >> remaining;
		cin >> cycle[i][0] >> cycle[i][1];
		startingTime[i] = cycle[i][startingColor[i]] - remaining;
	}	
	for (int i = 0; i < m; i++) {
		int a, b, d; cin >> a >> b >> d; a--; b--;
		adjLists[a].pb({b, d});
		adjLists[b].pb({a, d});
	}
	dijkstra(s);
	cout << ((timeTo[d] == 1e9) ? 0 : timeTo[d]) << nl;
}
