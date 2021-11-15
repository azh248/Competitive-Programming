/*
ID: azh248
LANG: JAVA
TASK: rectangularPasture 
*/

import java.util.*;
import java.io.*;

public class rectangularPasture {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		int[][] arr = new int[n][2];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());
		}
		sortByX(arr);

		long workingSubsets = 0l;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int y1 = arr[i][1];
				int y2 = arr[j][1];
				int above = 0;
				int below = 0;
				// check how many above, how many below this pair of cows, then we know how many subsets can be created containing these 2 cows
				for (int k = i + 1; k < j; k++) {
					int y3 = arr[k][1];
					if (y3 < Math.min(y1, y2)) {
						below++;
					} else if (y3 > Math.max(y1, y2)) {
						above++;
					}
				}
				workingSubsets += (above + 1)*(below + 1);
			}
		}
		pw.println(workingSubsets + n + 1);

		br.close();
		pw.close();
	}

	public static void sortByX(int[][] arr) {
		Arrays.sort(arr, new Comparator<int[]>() {
			public int compare(int[] arr1, int[] arr2) {
				if (arr1[0] > arr2[0]) {
					return 1;
				} else {
					return -1;
				}
			}
		});
	}
}
