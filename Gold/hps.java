/*
ID: azh248
LANG: JAVA
TASK: hps
*/

import java.util.*;
import java.io.*;

public class hps {

	static int[][][] dp;
	static int[] moves;
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("hps.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("hps.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		dp = new int[n + 1][k + 1][3];
		moves = new int[n + 1];

		/* Program: */


		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());

			char move = st.nextToken().charAt(0);
			if (move == 'H') {
				moves[i] = 0;
			} else if (move == 'P') {
				moves[i] = 1;
			} else {
				moves[i] = 2;
			}
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= k; j++) {
				for (int k1 = 0; k1 < 3; k1++) {
					maxGames(i, j, k1);
				}
			}
		}
		pw.println((int)Math.max(Math.max(dp[n][k][0], dp[n][k][1]), dp[n][k][2]));

		br.close();
		pw.close();
	}
	public static void maxGames(int gamesPlayed, int switchesLeft, int move) {
		int bonus = (move == moves[gamesPlayed]) ? 1 : 0;

		if (gamesPlayed == 0) {
			dp[gamesPlayed][switchesLeft][move] = 0;
			return;
		} else if (switchesLeft == 0) {
			dp[gamesPlayed][switchesLeft][move] = dp[gamesPlayed - 1][switchesLeft][move] + (moves[gamesPlayed] == move ? 1 : 0);
			return;
		}
		int firstMax = dp[gamesPlayed - 1][switchesLeft][move];
		int secondMax = dp[gamesPlayed - 1][switchesLeft - 1][(move + 1) % 3];
		int thirdMax = dp[gamesPlayed - 1][switchesLeft - 1][(move + 2) % 3];
		firstMax += bonus;
		secondMax += bonus;
		thirdMax += bonus;
		if (firstMax > secondMax) {
			if (firstMax > thirdMax) {
				dp[gamesPlayed][switchesLeft][move] = firstMax;
			} else {
				dp[gamesPlayed][switchesLeft][move] = thirdMax;
			}
		} else {
			if (secondMax > thirdMax) {
				dp[gamesPlayed][switchesLeft][move] = secondMax;
			} else {
				dp[gamesPlayed][switchesLeft][move] = thirdMax;
			}
		}
	}
}
