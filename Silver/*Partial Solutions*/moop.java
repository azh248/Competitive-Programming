/*
ID: azh248
LANG: JAVA
TASK: moop
*/

import java.util.*;
import java.io.*;

public class moop {

	static HashSet<Integer> dfsInfo = new HashSet<Integer>();
	static ArrayList<ArrayList<Integer>> adjacencyLists = new ArrayList<>();
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("moop.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("moop.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		/* just find the # of connected components and print it --> in each connected component, 
		at least 1 particle remains. For the minimum, exactly 1 particle in each component remains */

		int[][] particles = new int[n][2];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			particles[i][0] = Integer.parseInt(st.nextToken());
			particles[i][1] = Integer.parseInt(st.nextToken());
			ArrayList<Integer> adjList = new ArrayList<>();
			adjacencyLists.add(adjList);
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((particles[i][0] <= particles[j][0] && particles[i][1] <= particles[j][1]) || (particles[i][0] >= particles[j][0] && particles[i][1] >= particles[j][1])) {
					adjacencyLists.get(i).add(j);
					adjacencyLists.get(j).add(i);
				}
			}
		}
		int components = 0;
		ArrayList<ArrayList<Integer>> a = adjacencyLists;
		for (int i = 0; i < n; i++) {
			if (!dfsInfo.contains(i)) {
				components++;
				dfs(i);
			}
		}
		pw.println(components);

		br.close();
		pw.close();
	}
	
	public static void dfs(int node) {
		// uses dfs and iterates through each node's adjacency list that it passes into
		// checks if node has already been visited
		if (dfsInfo.contains(node)) {
			return;
		}
		// otherwise it adds the node to the set of traversed nodes and sets that node
		// as the new root
		dfsInfo.add(node);
		for (int i : adjacencyLists.get(node)) {
			dfs(i); // WARNING: MIGHT GET STACK OVERFLOW ERROR
		}
	}
}
