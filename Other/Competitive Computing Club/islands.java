/*
ID: azh248
LANG: JAVA
TASK: islands
*/

import java.util.*;
import java.io.*;

public class islands {

	static int[][] grid;
	static boolean[][] visited;
	static int n1, m1, currentSize;
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("islands.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("islands.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		n1 = Integer.parseInt(st.nextToken());
		m1 = Integer.parseInt(st.nextToken());

		grid = new int[n1][m1];
		visited = new boolean[n1][m1];

		/* Program: */

		for (int i = 0; i < n1; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m1; j++) {
				grid[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int maxSize = 0;
		for (int i = 0; i < n1; i++) {
			for (int j= 0; j < m1; j++) {
				if (!visited[i][j] && grid[i][j] == 1) {
					currentSize = 0;
					ff(i, j, 1);
					if (currentSize > maxSize) maxSize = currentSize;
				}
			}
		}
		pw.println(maxSize);

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
	public static void ff(int y, int x, int color) {
		if (y < 0 || y >= n1 || x < 0 || x >= m1)
			return; // if outside grid
		if (grid[y][x] != color)
			return; // wrong color
		if (visited[y][x])
			return; // already visited this square
		visited[y][x] = true; // mark current square as visited
		currentSize++; // increment the size for each square we visit
		ff(y, x + 1, color);
		ff(y, x - 1, color);
		ff(y - 1, x, color);
		ff(y + 1, x, color);
	}
}
