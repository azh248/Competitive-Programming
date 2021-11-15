/*
ID: azh248
LANG: JAVA
TASK: NNN
*/

import java.util.*;
import java.io.*;

public class NNN {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("NNN.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("NNN.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		/* Program: */

		st = new StringTokenizer(br.readLine());
		boolean works = false;
		String str = st.nextToken();
		for (int i = 0; i <= n - k; i++) {
			char ch = str.charAt(i);
			boolean localWorked = true;
			for (int j = i + 1; j < i + k; j++) {
				if (str.charAt(j) != ch) {
					localWorked = false;
				}
			}
			if (localWorked) works = true;
		}
		pw.println(!works);

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
