/*
ID: azh248
LANG: JAVA
TASK: multimoo
*/

import java.util.*;
import java.io.*;

public class multimoo {

	static int[][] board;
	static boolean[][] visited;
	static int currentSize, xMax, yMax;
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("multimoo.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("multimoo.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		board = new int[n][n];
		visited = new boolean[n][n];
		xMax = n;
		yMax = n;

		/* Program: first find the largest area by one cow, print it, then, we do the following:
		We iterate though every point on the board, resetting visited as we go, and we explore 2 of its neighbors. 
		We can make sure we only explore new neighbors by only going right and down. We also have to make sure
		its neighbors aren't the same color. */

		HashSet<Integer> distinctIDs = new HashSet<>();

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				distinctIDs.add(board[i][j]);
			}
		}
		int maxSingleRegion = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					currentSize = 0;
					ff(i, j, board[i][j], board[i][j]);
					if (currentSize > maxSingleRegion) {
						maxSingleRegion = currentSize;
					}
				} 
			}
		}
		pw.println(maxSingleRegion);
	
		/* Program: first find the largest area by one cow, print it, then, we do the following:
		We iterate though every point on the board, resetting visited as we go, and we explore 2 of its neighbors. 
		We can make sure we only explore new neighbors by only going right and down. We also have to make sure
		its neighbors aren't the same color. */

		int maxPairRegion = 0;

		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				visited = new boolean[n][n];
				int id = board[i][j];
				int rightNeighborID = board[i + 1][j];
				int downNeighborID = board[i][j + 1];
				if (id != rightNeighborID) {
					currentSize = 0;
					ff(i, j, id, rightNeighborID);
					if (currentSize > maxPairRegion) {
						maxPairRegion = currentSize;
					} 
				} if (id != downNeighborID) {
					currentSize = 0;
					ff(i, j, id, downNeighborID);
					if (currentSize > maxPairRegion) {
						maxPairRegion = currentSize;
					}
				}
			}
		}
		pw.println(maxPairRegion);

		// ArrayList<Integer> ids = new ArrayList<>();
		// Iterator<Integer> idItr = distinctIDs.iterator();
		// while (idItr.hasNext()) {
		// 	ids.add(idItr.next());
		// }
		// int size = ids.size();
		// int biggestPairRegion = 0;
		// for (int a = 0; a < size; a++) {
		// 	for (int b = a + 1; b < size; b++) {
		// 		visited = new boolean[n][n];
		// 		for (int i = 0; i < n; i++) {
		// 			for (int j = 0; j < n; j++) {
		// 				if (!visited[i][j] && (board[i][j] == ids.get(a) || board[i][j] == ids.get(b))) {
		// 					currentSize = 0;
		// 					ff(i, j, ids.get(a), ids.get(b));
		// 					biggestPairRegion = Math.max(biggestPairRegion, currentSize);
		// 				}
		// 			}
		// 		}
		// 	}
		// }
		// pw.println(biggestPairRegion);

		br.close();
		pw.close();
	}
	
	public static void ff(int y, int x, int firstColor, int secondColor) {
		if (y < 0 || y >= yMax || x < 0 || x >= xMax)
			return;
		if (board[y][x] != firstColor && board[y][x] != secondColor)
			return; 
		if (visited[y][x])
			return;
		visited[y][x] = true; 
		currentSize++; 
		ff(y, x + 1, firstColor, secondColor);
		ff(y, x - 1, firstColor, secondColor);
		ff(y - 1, x, firstColor, secondColor);
		ff(y + 1, x, firstColor, secondColor);
	}
}
