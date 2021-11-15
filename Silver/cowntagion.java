/*
ID: azh248
LANG: JAVA
TASK: cowntagion
*/

import java.util.*;
import java.io.*;

public class cowntagion {

	static int days = 0;
	static ArrayList<ArrayList<Integer>> adjacencyLists = new ArrayList<>();
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		for (int i = 0; i < n; i++) {
			ArrayList<Integer> add = new ArrayList<>();
			adjacencyLists.add(add);
		}
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			adjacencyLists.get(a).add(b);
			adjacencyLists.get(b).add(a);
		}
		treeDfs(0, -1);

		pw.println(days);
		
		br.close();
		pw.close();
	}
	public static void treeDfs(int currentNode, int previousNode) {
		// process node
		int children = adjacencyLists.get(currentNode).size() - 1;
		if (currentNode == 0) {
			children++; // doesn't have a parent we have to account for when determining the number of children
		}
		int cowsAtFarm = 1;
		while (cowsAtFarm - 1 < children) {
			cowsAtFarm *= 2;
			days++;
		}
		for (int i : adjacencyLists.get(currentNode)) {
			if (i != previousNode) {
				days++;
				treeDfs(i, currentNode);
			}
		}
	}
}
