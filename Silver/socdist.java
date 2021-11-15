/*
ID: azh248
LANG: JAVA
TASK: socdist
*/

import java.util.*;
import java.io.*;

public class socdist {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("socdist.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("socdist.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		long[][] pastures = new long[m][2];

		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			long[] arr = {Long.parseLong(st.nextToken()), Long.parseLong(st.nextToken())};
			pastures[i] = arr;
		}
		sortByColumn(pastures, 0);

		long right = 1000000000000000000l;
		long left = 0l;
		while (true) {
			long mid = (right + left) / 2;
			if (canDistance(pastures, n, mid)) {
				if (mid == 999999999999999999l) {
					pw.println(mid);
					break;
				} else if (right - left <= 1) {
					pw.println(mid);
					break;
				} else {
					left = mid;
				}
			} else {
				right = mid;
			}
		}

		/* Binary search on the distance --> for each candidate d, see if it works:
		Sort the pastures and start at the first working position. Then, increment by d and also increment a number that determines
		which pasture we need to be on (while the ending number of the next pasture < the position, keep going). When we stop, if the 
		starting number of the next pasture > our position, set our position to that starting number. Also make sure that if there aren't any 
		pastures left then the candidate distance doesn't work. */

		br.close();
		pw.close();
	}
	public static void sortByColumn(long[][] pastures, int col) {
		Arrays.sort(pastures, new Comparator<long[]>() {
			public int compare(long[] entry1, long[] entry2) {
				if (entry1[col] > entry2[col])
					return 1;
				else
					return -1;
			}
		});
	}
	public static boolean canDistance(long[][] pastures, int cows, long distance) {
		long position = pastures[0][0];
		int pasturePosition = 0;
		for (int i = 0; i < cows; i++) {
			while (pasturePosition < pastures.length && pastures[pasturePosition][1] < position) {
				pasturePosition++;
			}
			if (pasturePosition >= pastures.length) {
				return false;
			} if (pastures[pasturePosition][0] > position) {
				position = pastures[pasturePosition][0];
			}
			position += distance; // next cow, increment distance by the distance between cows
		}
		return true;
	}
}
