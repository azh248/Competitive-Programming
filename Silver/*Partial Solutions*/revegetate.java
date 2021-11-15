/*
ID: azh248
LANG: JAVA
TASK: revegetate
*/

import java.util.*;
import java.io.*;

public class revegetate {

	static HashSet<Integer> dfsInfo = new HashSet<>();
	static ArrayList<ArrayList<Integer>> adjacencyLists = new ArrayList<>();

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("revegetate.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("revegetate.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		for (int i = 0; i < n; i++) {
			ArrayList<Integer> adjList = new ArrayList<>();
			adjacencyLists.add(adjList);
		}

		// if anyone's looking at this, I didn't count the case where it wasn't possible to accommodate the cows so I got test case 11 wrong

		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			st.nextToken();
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			adjacencyLists.get(a).add(b);
			adjacencyLists.get(b).add(a);
		}

		int components = 0;
		for (int i = 0; i < n; i++) {
			if (!dfsInfo.contains(i)) {
				dfs(i);
				components++;
			}
		}
		if (components == 0) {
			pw.println("0");
			br.close();
			pw.close();
			return;
		}
		pw.print("1");
		for (int i = 0; i < components; i++) {
			pw.print("0");
		}
		pw.println();

		br.close();
		pw.close();
	}

	public static void dfs(int node) {
		if (dfsInfo.contains(node)) {
			return;
		}
		dfsInfo.add(node);
		for (int i : adjacencyLists.get(node)) {
			dfs(i);
		}
	}
}
