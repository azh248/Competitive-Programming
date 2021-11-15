/*
ID: azh248
LANG: JAVA
TASK: favorite
*/

import java.util.*;
import java.io.*;

public class favorite {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("favorite.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("favorite.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		long n = Long.parseLong(st.nextToken());

		/* Program: precalculate factorials and 10^7 + 10^6 + ..., then if x is the size of the word 
		its id is just for each letter in the word, ((x-1)! * the letter)(10^x-1 + 10^x-1.....10^0) */

		long[] factorials = new long[7];
		factorials[0] = 1;
		for (int i = 1; i < 7; i++) {
			long product = 1;
			for (long j = i; j > 0; j--) {
				product *= j;
			}
			factorials[i] = product;
		}
		long[] powersOf10 = new long[7];
		powersOf10[0] = 1;
		for (int i = 1; i < 7; i++) {
			powersOf10[i] = powersOf10[i - 1] + (long)Math.pow(10, i);
		}
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			String s = st.nextToken();
			char[] arr = s.toCharArray();
			int size = s.length();
			int[] intValues = new int[size];
			for (int j = 0; j < size; j++) {
				intValues[j] = (int)arr[j] - 96;
			}
			long sum = 0;
			for (int j = 0; j < size; j++) {
				sum += intValues[j] * factorials[size - 1] * powersOf10[size - 1];
			}
			pw.println(sum);
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
