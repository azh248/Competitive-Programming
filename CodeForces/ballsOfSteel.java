import java.util.*;
import java.io.*;

public class ballsOfSteel {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());

		/* just try a random point --> if it can reach all of them, print 1, otherwise print -1 */

		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			int[][] points = new int[n][2];
			for (int j = 0; j < n; j++) {
				st = new StringTokenizer(br.readLine());
				int[] arr = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
				points[j] = arr;
			}
			boolean totalWorked = false;
			for (int l = 0; l < n; l++) {
				int x = points[l][0];
				int y = points[l][1];
				boolean worked = true;
				for (int j = 0; j < n; j++) {
					int pointX = points[j][0];
					int pointY = points[j][1];
					if (Math.abs(x - pointX) + Math.abs(y - pointY) > k) {
						worked = false;
						break;
					}
				}
				if (worked) {
					totalWorked = true;
				}
			}
			if (totalWorked) {
				pw.println(1);
			} else {
				pw.println(-1);
			}
		}

		pw.close();
		br.close();
	}
}
