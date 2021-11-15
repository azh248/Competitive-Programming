/*
ID: azh248
LANG: JAVA
TASK: cipher
*/

import java.util.*;
import java.io.*;

public class cipher {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("cipher.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("cipher.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		/* Program: */

		ArrayList<String> message = new ArrayList<>();

		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < n; i++) {
			int letter = Integer.parseInt(st.nextToken());
			if (letter == -1) {
				message.add(" ");
				continue;
			}
			message.add(Character.toString((char)(letter + 96)));
		}
		Collections.reverse(message);
		for (int i = 0; i < n; i++) {
			pw.print(message.get(i) + " ");
		}
		pw.println();

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
