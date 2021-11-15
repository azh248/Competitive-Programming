/*
ID: azh248
LANG: JAVA
TASK: race
*/

import java.util.*;
import java.io.*;

public class race {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("race.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("race.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int k = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			// binary search on time for min value that yields a distance that's >= k
			int size = k;
			int right = size - 1;
			int left = 0;
			while (true) {
				int mid = (right + left) / 2;
				if (distanceTraveled(mid, x) >= k) {
					if (mid == size - 1) {
						pw.println(mid);
						break;
					} else if (right - left <= 1) {
						pw.println(mid);
						break;
					} else {
						right = mid;
					}
				} else {
					if (left == mid) {
						left = mid + 1;
					} else {
						left = mid;
					}
				}
			}
		}

		br.close();
		pw.close();
	}
	public static long distanceTraveled(int time, int x) {
		if ((time + x) % 2 == 0) {
			// straight up then down
			int riseTime = (time + x)/2;
			return (((long)riseTime*((long)riseTime + 1)/2) + ((long)riseTime*((long)riseTime - 1)/2) - (long)x*((long)x-1)/2);
		} else {
			// up, flat, then down
			int riseTime = (time + x - 1)/2;
			return ((long)riseTime*((long)riseTime + 1) - (long)x*((long)x - 1)/2);
		}
	}
}
