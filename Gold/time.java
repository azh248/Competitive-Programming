/*
ID: azh248
LANG: JAVA
TASK: time
*/

import java.util.*;
import java.io.*;

public class time {

	static int[] moonies;
	static long[][] dp;
	static boolean[][] connects;
	static ArrayList<ArrayList<Integer>> adjacencyLists = new ArrayList<>();

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("time.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("time.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());

		dp = new long[n + 1][1000];
		moonies = new int[n + 1];
		connects = new boolean[n + 1][1000]; // determines if the node at a point can connect to city 1 day 0

		for (int i = 0; i < n; i++) {
			moonies[i + 1] = Integer.parseInt(st.nextToken());
			ArrayList<Integer> add = new ArrayList<>();
			adjacencyLists.add(add);
		}
		ArrayList<Integer> add = new ArrayList<>();
		adjacencyLists.add(add); // for 1-shifting

		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			adjacencyLists.get(b).add(a);
		}
		connects[1][0] = true;
		for (int i = 1; i < 1000; i++) {
			for (int j = 1; j <= n; j++) {
				findMax(j, i);
			}
		}
		int maxMoonies = 0;
;
		for (int i = 1; i < 1000; i++) {
			if (connects[1][i]) { // this works
				maxMoonies = Math.max(maxMoonies, (int)(dp[1][i] - (long)c*(long)Math.pow(i, 2)));
			}
		}
		pw.println(maxMoonies);

		br.close();
		pw.close();
	}
	
	public static void findMax(int city, int days) {
		for (int i : adjacencyLists.get(city)) { // add this city's moonies
			if (connects[i][days - 1]) {
				connects[city][days] = true;
				if (dp[i][days - 1] + (long)moonies[city] > dp[city][days]) {
					dp[city][days] = dp[i][days - 1] + (long)moonies[city];
				}
			}
		}
	}
}
