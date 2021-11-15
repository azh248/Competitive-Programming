import java.util.*;
import java.io.*;

public class uniqueBidAction {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());

		/* Program: */


		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int[] queue = new int[n];
			int[] howManyOfEach = new int[n + 1];
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				queue[j] = Integer.parseInt(st.nextToken());
				howManyOfEach[queue[j]]++;
			}
			boolean worked = false;
			int min = 1000000000;
			int minIndex = -1;
			for (int j = 0; j < n; j++) {
				if (howManyOfEach[queue[j]] == 1) {
					if (queue[j] < min) {
						minIndex = j;
						min = queue[j];
					}
					worked = true;
				}
			}
			if (!worked) pw.println(-1);
			else pw.println(minIndex + 1);
		}

		pw.close();
		br.close();
	}
}
