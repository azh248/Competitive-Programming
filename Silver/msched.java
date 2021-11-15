/*
ID: azh248
LANG: JAVA
TASK: msched
*/

import java.util.*;
import java.io.*;

public class msched {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("msched.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("msched.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int[][] arr = new int[n][2]; // have to sort by first index and start from bottom up
		int[] optimal = new int[10001];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int milk = Integer.parseInt(st.nextToken());
			int deadline = Integer.parseInt(st.nextToken());
			arr[i][0] = deadline;
			arr[i][1] = milk;
		}
		sortByColumn(arr, 0);
		for (int i = 0; i < n; i++) {
			int deadline = arr[i][0];
			int milk = arr[i][1];
			int min = 10000;
			int minIndex = -1;
			for (int j = deadline; j >= 1; j--) {
				if (optimal[j] < min) {
					min = optimal[j];
					minIndex = j;
				}
			}
			if (minIndex == -1) continue;
			optimal[minIndex] = Math.max(optimal[minIndex], milk);
		}
		long sum = 0;
		for (int i = 1; i <= 10000; i++) {
			sum += optimal[i];
		}
		pw.println(sum);

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
