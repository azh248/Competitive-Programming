/*
ID: azh248
LANG: JAVA
TASK: shuffle
*/

import java.util.*;
import java.io.*;

public class shuffle {

	static int[][] processResults;
	static HashSet<Integer> notVisited = new HashSet<>();
	static boolean[] hasCow;
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("shuffle.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("shuffle.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		processResults = new int[(int) (Math.log(n * 2) / Math.log(2)) + 2][n + 1];

		int[] shuffle = new int[n + 1];
		hasCow = new boolean[n + 1];
		
		st = new StringTokenizer(br.readLine());

		for (int i = 1; i <= n; i++) {
			shuffle[i] = Integer.parseInt(st.nextToken());
		}

		processResults[0] = shuffle;

		createProcessResults((int) (Math.log(n * 2) / Math.log(2)) + 1);

		pw.println(n - notVisited.size());

		br.close();
		pw.close();
	}
	
	public static void createProcessResults(int power2) {
		if (power2 == 0) {
			return;
		}
		if (processResults[power2 - 1][1] == 0) {
			createProcessResults(power2 - 1);
		}
		int[] arr = processResults[power2 - 1];
		int[] newArr = new int[processResults[1].length];
		hasCow = new boolean[processResults[1].length];
		for (int i = 1; i < processResults[1].length; i++) {
			newArr[i] = arr[arr[i]];
			hasCow[arr[i]] = true;
		}
		for (int i = 1; i < processResults[1].length; i++) {
			if (!hasCow[i]) {
				notVisited.add(i);
			}
		}
		processResults[power2] = newArr;
	}
}
