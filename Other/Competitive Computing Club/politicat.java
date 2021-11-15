/*
ID: azh248
LANG: JAVA
TASK: politicat
*/

import java.util.*;
import java.io.*;

public class politicat {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("politicat.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("politicat.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		int k = Integer.parseInt(st.nextToken());

		/* Program: */
		
		ArrayList<Integer> fiveArr = new ArrayList<>();
		ArrayList<Integer> tenArr = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int votes = (int)Integer.parseInt(st.nextToken())/2 + 1;
			if (Integer.parseInt(st.nextToken()) == 5) fiveArr.add(votes);
			else tenArr.add(votes);
		}
		Collections.sort(fiveArr);
		Collections.sort(tenArr);
		int votes = 0;
		if (k%10 == 5) {
			k -= 5;
			votes += fiveArr.get(0);
			fiveArr.remove(0);
		}
		ArrayList<Integer> votesPerTenPoint = new ArrayList<Integer>();
		for (int i = 0; i < fiveArr.size() - 1; i += 2) {
			votesPerTenPoint.add(fiveArr.get(i) + fiveArr.get(i + 1));
		}
		for (int i : tenArr) votesPerTenPoint.add(i);
		Collections.sort(votesPerTenPoint);
		for (int i = 1; i <= k/10; i++) {
			votes += votesPerTenPoint.get(i - 1);
		}
		pw.println(votes);


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
