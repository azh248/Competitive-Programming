/*
ID: azh248
LANG: JAVA
TASK: mountains
*/

import java.util.*;
import java.io.*;

public class mountains {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("mountains.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("mountains.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		int[][] mountains = new int[n][2];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int[] arr = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
			mountains[i] = arr;
		}
		sortByColumn(mountains, 0);

		int maxYIntercept = 0;
		ArrayList<int[]> distinguishableMountainsForward = new ArrayList<>();
		ArrayList<int[]> distinguishableMountainsBackwards = new ArrayList<>();

		/* We keep track of the max y intercept of any mountain so far, and for every mountain if y <= -x + maxYIntercept then don't count it, 
		otherwise check if its y intercept is the greatest so far. We then iterate through it backwards, doing the opposite thing, and check which
		mountains satisfy both. */

		for (int i = 0; i < n; i++) {
			int x = mountains[i][0];
			int y = mountains[i][1];
			if (y <= -1*x + maxYIntercept) {
				continue;
			} else {
				distinguishableMountainsForward.add(mountains[i]);
				if (x + y > maxYIntercept) {
					maxYIntercept = x + y;
				}
			}
		}
		maxYIntercept = -1000000000;
		for (int i = n - 1; i >= 0; i--) {
			int x = mountains[i][0];
			int y = mountains[i][1];
			if (y <= x + maxYIntercept) {
				continue;
			} else {
				distinguishableMountainsBackwards.add(mountains[i]);
				if (y - x > maxYIntercept) {
					maxYIntercept = y - x;
				}
			}
		}
		int distinguishableMountains = 0;
		for (int[] i : distinguishableMountainsBackwards) { // i could also do this in O(nlogn) complexity by sorting and then comparing but I don't think that's necessary
			for (int[] j : distinguishableMountainsForward) {
				if (i[0] == j[0] && i[1] == j[1]) {
					distinguishableMountains++;
				}
			}
		}
		pw.println(distinguishableMountains);

		br.close();
		pw.close();
	}
	
	public static void sortByColumn(int arr[][], int col) {
		Arrays.sort(arr, new Comparator<int[]>() {
			public int compare(final int[] entry1, final int[] entry2) {
				if (entry1[col] > entry2[col])
					return 1;
				else
					return -1;
			}
		});
	}
}
