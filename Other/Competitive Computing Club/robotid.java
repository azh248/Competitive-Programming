/*
ID: azh248
LANG: JAVA
TASK: robotid
*/

import java.util.*;
import java.io.*;

public class robotid1 {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("robotid.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("robotid.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int k1 = Integer.parseInt(st.nextToken());


		/* Program: */

		int[] arr = new int[n];

		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int totalWorked = 0;
		for (int i = 1; i <= n; i++) {
			boolean worked = false;
			for (int j = 0; j < n - i + 1; j++) {
				int product = 1;
				for (int k = j; k < j + i; k++) {
					product *= arr[k];
				}
				if (product < k1) {
					worked = true;
					totalWorked++;
				}
			}
			if (!worked) break;
		}
		pw.println(totalWorked);

		/**
		 * setting one variable equal to another makes it so that variable changes when
		 * the original one does, to get around this use "new" or .clone() with a cast,
		 * if it's a list of lists you have to do a deep clone you might have to use
		 * larger data types --> for silver and above problems test cases are
		 * huge!!!!!!!!!!!!!! check if the loops are in the right order (if each cow has
		 * n amounts of milk, going through the amounts of milk first, then the cows
		 * would be incorrect) try to break asap when tle, instead of using if (!x) ___,
		 * use if (x) break; else ___ try to avoid unnecessary nested loops use treeset
		 * --> built in bsearch for floor and ceiling use linkedlist --> O(1) insertion
		 * and deletion but O(n) accessing
		 */

		br.close();
		pw.close();
	}
}
