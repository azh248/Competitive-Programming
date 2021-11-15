/*
ID: azh248
LANG: JAVA
TASK: clocktree
*/

import java.util.*;
import java.io.*;

public class clocktree {

	static HashSet<Integer> dfsInfo = new HashSet<>();
	static ArrayList<ArrayList<Integer>> adjacencyLists = new ArrayList<>();
	static int[] times;
	static int startingPoint;
	static ArrayList<int[]> addback = new ArrayList<>();
	static int[] parents;
	static boolean switchedStartingPoints = false;
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("clocktree.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("clocktree.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		times = new int[n];
		int[] origTimes = new int[n];
		parents = new int[n];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			times[i] = Integer.parseInt(st.nextToken()) - 1;
			origTimes[i] = times[i];
			ArrayList<Integer> arr = new ArrayList<>();
			adjacencyLists.add(arr);
		}
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine());
			int room1 = Integer.parseInt(st.nextToken()) - 1;
			int room2 = Integer.parseInt(st.nextToken()) - 1;
			adjacencyLists.get(room1).add(room2);
			adjacencyLists.get(room2).add(room1);
		}
		int workingRooms = 0;
		startingPoint = 0;
		for (int i = 0; i < n; i++) {
			dfsInfo.clear();
			switchedStartingPoints = false;
			startingPoint = i;
			parents[startingPoint] = -1;
			findParents(startingPoint);
			dfs(i);
			for (int[] j : addback) {
				adjacencyLists.get(j[0]).add(j[1]);
			}
			addback.clear();
			int[] arr = times;
			ArrayList<ArrayList<Integer>> adj = adjacencyLists;
			int[] par = parents;
			boolean worked = true;
			if (times[startingPoint] == 0) {
				times[startingPoint] = 11;
			}
			for (int j = 0; j < n; j++) {
				if (times[j] != 11) {
					worked = false;
					break;
				}
			}
			if (worked) {
				workingRooms++;
			}
			times = (int[]) origTimes.clone();
		}
		pw.println(workingRooms);

		br.close();
		pw.close();
	}
	
	public static void dfs(int node) {
		int[] a = times;
		ArrayList<ArrayList<Integer>> b = adjacencyLists;

		if (node != startingPoint) {
			times[node]++;
			times[node] %= 12;
		} else {
			// if the starting node has only 1 neighbor to go to, we want to fill it up and move on because we don't want to come back since it's a leaf
			if (adjacencyLists.get(startingPoint).size() == 1 && (parents[startingPoint] == -1 || adjacencyLists.get(startingPoint).get(0) == parents[startingPoint])) {
				int nextStartingPoint = adjacencyLists.get(startingPoint).get(0);
				times[nextStartingPoint] += 12 - times[startingPoint]; // add 1 beacuse the next startingnode won't have 1 added for visiting because of the previous if statement
				times[nextStartingPoint] %= 12;
				times[startingPoint] = 11;
				int[] arr1 = {startingPoint, nextStartingPoint};
				addback.add(arr1);
				adjacencyLists.get(startingPoint).remove((Integer)nextStartingPoint);
				startingPoint = nextStartingPoint;
				switchedStartingPoints = true;
				dfs(nextStartingPoint);
				return;
			}
		}
		int i = 0;
		int size = adjacencyLists.get(node).size();
		while (i < size) {
			if (adjacencyLists.get(node).get(i) == parents[node]) {
				i++;
				continue;
			} else if (adjacencyLists.get(adjacencyLists.get(node).get(i)).size() == 1) {
				int leafNode = adjacencyLists.get(node).get(i);
				times[node] += 11 - times[leafNode];
				times[node] %= 12;
				times[leafNode] = 11;
				int[] arr = {node, leafNode};
				addback.add(arr);
				adjacencyLists.get(node).remove(i);
				i--;
			} else {
				dfs(adjacencyLists.get(node).get(i));
				if (adjacencyLists.get(adjacencyLists.get(node).get(i)).size() == 1) {
					int leafNode = adjacencyLists.get(node).get(i);
					times[node] += 12 - times[leafNode]; // add 1 because we have to end at that node, not the leaf
					times[node] %= 12;
					times[leafNode] = 11;
					int[] arr = { node, leafNode };
					addback.add(arr);
					adjacencyLists.get(node).remove(i);
					i--; // cancel out the next increment since we just removed an element before the next element so the next element's index --
				}
			}
			size = adjacencyLists.get(node).size();
			i++;
		}
	}
	public static void findParents(int node) {
		if (dfsInfo.contains(node)) {
			return;
		}
		dfsInfo.add(node);
		for (int i : adjacencyLists.get(node)) {
			if (dfsInfo.contains(i)) {
				continue;
			}
			findParents(i);
			parents[i] = node;
		}
	}
}
