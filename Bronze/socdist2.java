/*
ID: azh248
LANG: JAVA
TASK: socdist2
*/

import java.util.*;
import java.io.*;

public class socdist2 {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("socdist2.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("socdist2.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int[][] cows = new int[n][2];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			cows[i][0] = Integer.parseInt(st.nextToken());
			cows[i][1] = Integer.parseInt(st.nextToken());
		}
		sortByColumn(cows, 0);

		int closestToInfected = 1000000000;

		for (int i = 1; i < n - 1; i++) {
			if (cows[i][1] == 0) {
				if (cows[i - 1][1] == 1) {
					closestToInfected = Math.min(closestToInfected, cows[i][0] - cows[i - 1][0]);	
				} if (cows[i + 1][1] == 1) {
					closestToInfected = Math.min(closestToInfected, cows[i + 1][0] - cows[i][0]);
				}
			}
		}

		if (cows[0][1] == 0) {
			if (cows[1][1] == 1) {
				closestToInfected = Math.min(closestToInfected, cows[1][0] - cows[0][0]);
			}
		} if (cows[n - 1][1] == 0) {
			if (cows[n - 2][1] == 1) {
				closestToInfected = Math.min(closestToInfected, cows[n - 1][0] - cows[n - 2][0]);	
			}
		}

		closestToInfected--;
		int infected = 0;

		for (int i = 0; i < n; i++) {
			if (cows[i][1] == 1) {
				infected++;
				while (i != n - 1 && cows[i + 1][1] == 1 && cows[i + 1][0] - cows[i][0] <= closestToInfected) {
						i++;
				}
			}
		}
		pw.println(infected);


		br.close();
		pw.close();
	}
	public static void sortByColumn(int arr[][], int col) {
		Arrays.sort(arr, new Comparator<int[]>() {
			public int compare(final int[] entry1, final int[] entry2) {
				if (entry1[col] > entry2[col]) {
					return 1;
				} else {
					return -1;
				}
			}
		});
	}
}
