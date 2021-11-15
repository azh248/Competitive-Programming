/*
ID: azh248
LANG: JAVA
TASK: mooyomooyo
*/

import java.util.*;
import java.io.*;

public class mooyomooyo {

	static int[][] board;
	static boolean[][] visited;
	static int yMax;
	static int xMax; 
	static Queue<int[]> component;
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("mooyomooyo.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("mooyomooyo.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		/* Program: keep floodfilling every square until there is nothing that is removed as a result of the floodfill (make sure to reset 
		visited afterwards, and iterate from the bottom to top of the graph, bringing points down into empty spots). During the floodfill of a square, if it isn't 0 add the coordinates to a stack. If that stacks size >= k at the end, set all
		of the points in the stack to 0 */

		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		component = new LinkedList<>();
		board = new int[n][10];
		visited = new boolean[n][10];
		yMax = n - 1;
		xMax = 9;

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int[] arr = new int[10];
			String s = st.nextToken();
			for (int j = 0; j < 10; j++) {
				arr[j] = Integer.parseInt(Character.toString(s.charAt(j)));
			}
			board[i] = arr;
		}
		while (true) {
			boolean worked = false;
			visited = new boolean[n][10];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < 10; j++) {
					if (!visited[i][j] && board[i][j] != 0) {
						component.clear();
						ff(i, j, board[i][j]);
						if (component.size() < k) {
							continue; // if not enough nodes were visited
						}
						worked = true;
						for (int[] l : component) {
							board[l[0]][l[1]] = 0;
						}
					}
				}
			}
			if (!worked) {
				break;
			}
			// starting from the bottom row going up, move all elements down if they can be moved down
			for (int i = n - 2; i >= 0; i--) {
				for (int j = 0; j < 10; j++) {
					int counter = 0;
					while (i + counter < n - 1 && board[i + 1 + counter][j] == 0) {
						board[i + 1 + counter][j] = board[i + counter][j];
						board[i + counter][j] = 0;
						counter++;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				pw.print(board[i][j]);
			}
			pw.println();
		}

		br.close();
		pw.close();
	}
	
	public static void ff(int y, int x, int color) {
		if (y < 0 || y > yMax || x < 0 || x > xMax)
			return; 
		if (board[y][x] != color)
			return;
		if (visited[y][x])
			return; 
		visited[y][x] = true;
		int[] arr = {y, x};
		component.add(arr);
		ff(y, x + 1, color);
		ff(y, x - 1, color);
		ff(y - 1, x, color);
		ff(y + 1, x, color);
	}
}
