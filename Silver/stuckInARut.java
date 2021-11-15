/*
ID: azh248
LANG: JAVA
TASK: stuckInARut
*/

import java.util.*;
import java.io.*;

public class stuckInARut {

	static HashSet<Integer> dfsInfo = new HashSet<>();
	static ArrayList<ArrayList<Integer>> stoppedCows = new ArrayList<>(); // adjacency lists containing the cows each
																			// cow is to blame for

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		ArrayList<int[]> northCows = new ArrayList<>();
		ArrayList<int[]> eastCows = new ArrayList<>();

		int[] stoppedAt = new int[n]; // where each cow was stopped
		for (int i = 0; i < n; i++) {
			ArrayList<Integer> add = new ArrayList<>();
			stoppedCows.add(add);
			stoppedAt[i] = 1000000000;
			st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			int[] cowDetails = { i, Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()) };
			if (str.equals("N")) {
				northCows.add(cowDetails);
			} else {
				eastCows.add(cowDetails);
			}
		}

		sortByCol(northCows, 1);
		sortByCol(eastCows, 2);

		for (int i = 0; i < northCows.size(); i++) {
			for (int j = 0; j < eastCows.size(); j++) {
				int[] cow1Details = eastCows.get(j);
				int[] cow2Details = northCows.get(i);
				int cow1 = cow1Details[0];
				int x1 = cow1Details[1];
				int y1 = cow1Details[2];
				int cow2 = cow2Details[0];
				int x2 = cow2Details[1];
				int y2 = cow2Details[2];
				if (y2 > y1 || x1 > x2) {
					continue;
				}
				int xDist = Math.abs(x1 - x2); // x distance between the points; how long it'll take for the east point
												// to reach their intersection
				int yDist = Math.abs(y1 - y2); // y distance betwen the points; how long it'll take for the north point
												// to reach their intersection
				if (xDist == yDist) { // they meet at same hour
					continue;
				} else if (xDist > yDist) { // xDist hits yDists's rut if yDist hasn't already been stopped; cow2 is to
											// blame
					if (stoppedAt[cow2] < y1) {
						continue;
					} else {
						if (x2 < stoppedAt[cow1]) {
							stoppedAt[cow1] = Math.min(stoppedAt[cow1], x2);
							stoppedCows.get(cow2).add(cow1);
						}
					}
				} else if (yDist > xDist) { // yDist hits xDists's rut if xDist hasn't already been stopped; cow1 is to
											// blame
					if (stoppedAt[cow1] < x2) {
						continue;
					} else {
						if (y1 < stoppedAt[cow2]) {
							stoppedAt[cow2] = Math.min(stoppedAt[cow2], y1);
							stoppedCows.get(cow1).add(cow2);
						}
					}
				}
			}
		}
		for (ArrayList<Integer> i : stoppedCows) { // dfs to find the blame on a cow
			dfsInfo.clear();
			for (int j : i) {
				dfs(j);
			}
			pw.println(dfsInfo.size());
		}

		br.close();
		pw.close();
	}

	public static void sortByCol(ArrayList<int[]> arr, int col) {
		Collections.sort(arr, new Comparator<int[]>() {
			public int compare(int[] arr1, int[] arr2) {
				if (arr1[col] > arr2[col]) {
					return 1;
				} else {
					return -1;
				}
			}
		});
	}

	public static void dfs(int node) {
		if (dfsInfo.contains(node)) {
			return;
		}
		dfsInfo.add(node);
		for (int i : stoppedCows.get(node)) {
			dfs(i);
		}
	}
}
