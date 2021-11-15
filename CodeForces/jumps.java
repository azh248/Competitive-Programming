import java.util.*;
import java.io.*;

public class jumps {

	static int[][] dp;
	static int stoppingPoint;
	static int[][] visited;
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());

		/* Program: */

		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			int y = 100000;
			int k = 1;
			int x = Integer.parseInt(st.nextToken()) + 100000;
			stoppingPoint = x;
			dp = new int[2000000][100];
			visited = new int[2000000][100];
			// have to begin dp, also have to initialize some values
			// we want to find dp[0][0]
			minJumps(y, k); 
			int min = 100000000;
			for (int j = 0; j < dp[x].length; j++) {
				if (visited[x][j] >= 1) {
					min = Math.min(min, dp[x][j]); 
				}
			}
			pw.println(min - 1);
		}

		pw.close();
		br.close();
	}
	public static void minJumps(int position, int k) {
		if (k >= 99 || position >= 2000000 - k || position <= 10) {
			return;
		}
		if (visited[position][k] >= 2) {
			return;
		}
		if (visited[position - 1][k + 1] < 2 && position >= 10) {
			minJumps(position - 1, k + 1);
		} if (visited[position + k][k + 1] < 2 && position <= stoppingPoint) {
			minJumps(position + k, k + 1);
		}
		visited[position][k]++;
		if (position == stoppingPoint) {
			dp[position][k] = k;
			return;
		} else if (position > stoppingPoint) {
			dp[position][k] = dp[position - 1][k + 1];
			return;
		} else {
			dp[position][k] = Math.min(dp[position - 1][k + 1], dp[position + k][k + 1]);
		}
	}
}
