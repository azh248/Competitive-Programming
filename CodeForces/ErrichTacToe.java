import java.util.*;
import java.io.*;

public class ErrichTacToe {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int t = Integer.parseInt(st.nextToken());

		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			char[][] board = new char[n][n];
			char[][] origBoard = new char[n][n];
			char[][] firstBoard = new char[n][n];
			char[][] secondBoard = new char[n][n];
			char[][] thirdBoard = new char[n][n];
			for (int j = 0; j < n; j++) {
				st = new StringTokenizer(br.readLine());
				char[] arr = new char[n];
				String s = st.nextToken();
				for (int k = 0; k < n; k++) {
					arr[k] = s.charAt(k);
				}
				board[j] = arr;
				origBoard[j] = arr.clone();
			}
			int oCount1 = 0;
			int oCount2 = 0;
			int oCount3 = 0;
			
			tryBoard(board, 0, n);

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (board[j][k] == 'O') {
						oCount1++;
					}
					firstBoard[j][k] = board[j][k];
					board[j][k] = origBoard[j][k];
				}
			}

			tryBoard(board, 1, n);
			
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (board[j][k] == 'O') {
						oCount2++;
					}
					secondBoard[j][k] = board[j][k];
					board[j][k] = origBoard[j][k];
				}
			}
			
			tryBoard(board, 2, n);

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (board[j][k] == 'O') {
						oCount3++;
					}
					thirdBoard[j][k] = board[j][k];
					board[j][k] = origBoard[j][k];
				}
			}
			if (oCount1 < oCount2) {
				if (oCount1 < oCount3) {
					for (int j = 0; j < n; j++) {
						for (int k = 0; k < n; k++) {
							pw.print(Character.toString(firstBoard[j][k]));
						}
						pw.println();
					}
				} else {
					for (int j = 0; j < n; j++) {
						for (int k = 0; k < n; k++) {
							pw.print(Character.toString(thirdBoard[j][k]));
						}
						pw.println();
					}
				}
			} else {
				if (oCount2 < oCount3) {
					for (int j = 0; j < n; j++) {
						for (int k = 0; k < n; k++) {
							pw.print(Character.toString(secondBoard[j][k]));
						}
						pw.println();
					}
				} else {
					for (int j = 0; j < n; j++) {
						for (int k = 0; k < n; k++) {
							pw.print(Character.toString(thirdBoard[j][k]));
						}
						pw.println();
					}
				}
			}
		}

		pw.close();
		br.close();
	}
	public static void tryBoard(char[][] board, int mod, int n) {
		for (int j = 0; j < n; j++) {
			for (int k = (j % 3 + mod)%3; k < n; k += 3) {
				if (board[j][k] == 'X') {
					if (j >= 2) {
						if (board[j - 1][k] == 'X' && board[j - 2][k] == 'X') {
							board[j][k] = 'O';
							continue;
						}
					} if (j < n - 2) {
						if (board[j + 1][k] == 'X' && board[j + 1][k] == 'X') {
							board[j][k] = 'O';
							continue;
						}
					} if (j >= 1 && j < n - 1) {
						if (board[j - 1][k] == 'X' && board[j + 1][k] == 'X') {
							board[j][k] = 'O';
							continue;
						}
					} 
					if (j > 0) {
						if (board[j - 1][k] == 'X') {
							board[j][k] = 'O';
							continue;
						}
					} else if (j < n - 1) {
						if (board[j + 1][k] == 'X') {
							board[j][k] = 'O';
							continue;
						}
					}
					if (k >= 2) {
						if (board[j][k - 1] == 'X' && board[j][k - 2] == 'X') {
							board[j][k] = 'O';
							continue;
						}
					} if (k < n - 2) {
						if (board[j][k + 1] == 'X' && board[j][k + 2] == 'X') {
							board[j][k] = 'O';
							continue;
						}
					} if (k >= 1 && k < n - 1) {
						if (board[j][k - 1] == 'X' && board[j][k + 1] == 'X') {
							board[j][k] = 'O';
							continue;
						}
					}
					if (k > 0) {
						if (board[j][k - 1] == 'X') {
							board[j][k] = 'O';
							continue;
						}
					} else if (k < n - 1) {
						if (board[j][k + 1] == 'X') {
							board[j][k] = 'O';
							continue;
						}
					}
				}
			}
		}
	}
}
