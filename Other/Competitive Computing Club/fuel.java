/*
ID: azh248
LANG: JAVA
TASK: fuel
*/

import java.util.*;
import java.io.*;

public class fuel {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("fuel.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("fuel.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		/* Program: */

		int[] differences = new int[n];
		int[] fuelsInitialized = new int[n];
		st = new StringTokenizer(br.readLine());
		fuelsInitialized[0] = Integer.parseInt(st.nextToken());
		differences[0] = fuelsInitialized[0];
		for (int i = 1; i < n; i++) {
			fuelsInitialized[i] = Integer.parseInt(st.nextToken());
			differences[i] = fuelsInitialized[i] - fuelsInitialized[i - 1];
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int startingRobot = Integer.parseInt(st.nextToken()) - 1;
			int endingRobot = Integer.parseInt(st.nextToken()) - 1;
			int add = Integer.parseInt(st.nextToken()) * Integer.parseInt(st.nextToken());
			if (startingRobot == 0) {
				if (endingRobot == n - 1) {
					differences[0] += add;
				} else {
					differences[0] += add;
					differences[endingRobot + 1] -= add;
				}
			} else if (endingRobot == n - 1) {
				differences[startingRobot] += add;
			} else {
				differences[startingRobot] += add;
				differences[endingRobot + 1] -= add;
			}
		}
		// converting from differences to fuel values
		int[] fuels = new int[n];
		fuels[0] = differences[0];
		pw.println(fuels[0]);
		for (int i = 1; i < n; i++) {
			fuels[i] = differences[i] + fuels[i - 1];
			pw.println(fuels[i]);
		}


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
