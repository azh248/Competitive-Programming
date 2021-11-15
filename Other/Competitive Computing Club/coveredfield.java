/*
ID: azh248
LANG: JAVA
TASK: coveredfield
*/

import java.util.*;
import java.io.*;

public class coveredfield {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("coveredfield.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("coveredfield.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		int[][] fieldDifferences = new int[10000][10000]; 

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken()) - 1;
			int y1 = Integer.parseInt(st.nextToken()) - 1;
			int x2 = Integer.parseInt(st.nextToken()) - 1;
			int y2 = Integer.parseInt(st.nextToken()) - 1;
			for (int j = y1 + 1; j <= y2 + 1; j++) {
				fieldDifferences[j + 1][x1 + 1]++; // the +1 is for 1-shifting so in the future its easier to get the
														// actual wall's paint values
				fieldDifferences[j + 1][x2 + 2]--;
			}
		}

		/* retrieve number of paint using the differences */

		int[][] field = new int[10000][10000];


		int[] kCounts = new int[m];
		for (int w = 1; w <= m; w++) {
			int kCount = 0;

			for (int i = 1; i < 10000; i++) {
				int lastIndex = 0;
				for (int j = 1; j < 10000; j++) {
					if (fieldDifferences[i][j] != 0) {
						lastIndex = j;
					}
				}
				if (lastIndex == 0) {
					continue;
				}
				for (int j = lastIndex - 1; j >= 0; j--) {
					field[i][j] = field[i][j + 1] - fieldDifferences[i][j + 1];
					if (field[i][j] == w)
						kCount++;
				}
			}
			kCounts[w - 1] = kCount;

		}
		int[] prefixSums = new int[m];
		prefixSums[m - 1] = kCounts[m - 1];
		for (int i = m - 2; i >= 0; i--) {
			prefixSums[i] = prefixSums[i + 1] + kCounts[i];
		}
		for (int i = 0; i < m; i++) {
			pw.println(prefixSums[i]);
		}


		/*
		 * use 2d prefix sums, find how much is covered by k layers of paint, then find
		 * the tiles that are covered by k-1 coats of paint and determine the best 2
		 * rectangles to paint
		 */

		/**
		 * What to watch out for: == doesn't work for equality for reference types
		 * setting one variable equal to another makes it so that variable changes when
		 * the original one does, to get around this use "new" start using ? in an if
		 * else statement, put the else directly after the closing bracket you might
		 * have to use larger data types --> for silver and above problems test cases
		 * are huge when needing to find the max in an array, just use max =
		 * Math.max(max, nextInt) check if the loops are in the right order (if each cow
		 * has 3 amounts of milk, going through the amounts of milk first, then the cow
		 * would be incorrect) try to break asap when tle, instead of using if (!x) ___,
		 * use if (x) break; else ___ try to avoid unnecessary nested loops when setting
		 * arraylists of arrays/arraylists equal to each other, make sure to clone the
		 * arrays AT EVERY POINT THEY'RE IN CONTACT
		 */

		br.close();
		pw.close();
	}
}
