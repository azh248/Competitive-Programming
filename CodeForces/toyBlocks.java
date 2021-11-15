import java.util.*;
import java.io.*;

public class toyBlocks {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());

		/* Program: */

		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int max = 0;
			int[] arr = new int[n];
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				arr[j] = Integer.parseInt(st.nextToken());
				if (arr[j] > max) {
					max = arr[j];
				}
			}
			int totalDifferenceFromMax = 0;
			for (int j = 0; j < n; j++) {
				totalDifferenceFromMax += max - arr[j];
			}
			int moves = 0;
			for (int j = 0; j < n; j++) {
				if (arr[j] < totalDifferenceFromMax - (max - arr[j]) || arr[j] % (totalDifferenceFromMax - (max - arr[j])) != 0) {
					// find closest multiple of n-1, make arr[j] that
					int element = arr[j];
					arr[j] = (int) ((element/(n-1)) + 1)*(n-1);
					moves += (arr[j] - element);
				}
			}
			pw.println(moves);
		}

		pw.close();
		br.close();
	}
}
