/*
ID: azh248
LANG: JAVA
TASK: pails
*/

import java.util.*;
import java.io.*;

public class pails {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("pails.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("pails.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		long x = Long.parseLong(st.nextToken());
		long y = Long.parseLong(st.nextToken());
		long k = Long.parseLong(st.nextToken());
		long m = Long.parseLong(st.nextToken());

		/* Program: x - ky, y - kx, y%x + x, x, y, x + y, */

		ArrayList<Long> possibilities = new ArrayList<>();
		if (k >= 1) {
			possibilities.add(x);
			possibilities.add(y);
			possibilities.add(0l);
		}
		if (k >= 2) {
			possibilities.add(x + y);
		}
		if (k >= 3) {
			for (long i = 0; i < (k - 1) / 2; i++) {
				possibilities.add(Math.max(0, x - (i + 1) * y));
				possibilities.add(Math.max(0, y - (i + 1) * x));
			}
			for (long i = 0; i < (k - 1) / 2; i++) {
				if ((i + 1) * y < x) {
					possibilities.add(((i + 2) * y) % x);
				}
				if ((i + 1) * x < y) {
					possibilities.add(((i + 2) * x) % y);
				}
			}
		}
		if (k >= (long) (x / y + 1) * 2 + 1) {
			possibilities.add(((long) (x / y) * y + y) % x);
			possibilities.add(((long) (x / y) * y + y) % x * 4);
			possibilities.add(((long) (x / y) * y + y) % x + y);
			possibilities.add(((long) (y / x) * x + x) % y);
			possibilities.add(((long) (y / x) * x + x) % y * 4);
			possibilities.add(((long) (y / x) * x + x) % y + y);
		}
		long minDistance = 10000;
		for (long i : possibilities) {
			minDistance = Math.min(minDistance, Math.abs(i - m));
		}
		pw.println(minDistance);

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
