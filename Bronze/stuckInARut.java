/*
ID: azh248 
LANG: JAVA
TASK: stuckInARut 
*/

import java.util.*;
import java.io.*;

public class stuckInARut {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
	
		ArrayList<int[]> northCows = new ArrayList<>();
		ArrayList<int[]> eastCows = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			String direc = st.nextToken();
			int[] arr = { i, Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()) };
			if (direc.equals("N")) {
				northCows.add(arr);
			} else {
				eastCows.add(arr);
			}
		}
		int[] stoppedAt = new int[n];
		int[] distanceMoved = new int[n];

		for (int i = 0; i < n; i++) {
			stoppedAt[i] = 1000000000;
			distanceMoved[i] = 1000000000;
		}
		/* 
		Iterate through every pair and find the 
		*/

		sortByCol(eastCows, 1);
		sortByCol(northCows, 1);

		for (int i = eastCows.size() - 1; i >= 0; i--) {
			for (int j = 0; j < northCows.size(); j++) {
				int[] cow1Info = eastCows.get(i);
				int[] cow2Info = northCows.get(j);
				int cow1 = cow1Info[0];
				int cow2 = cow2Info[0];
				int x1 = cow1Info[1];
				int y1 = cow1Info[2];
				int x2 = cow2Info[1];
				int y2 = cow2Info[2];
				if (y2 > y1 || x1 > x2) {
					continue;
				} 
				int xDistance = x2 - x1;
				int yDistance = y1 - y2;
				if (xDistance == yDistance) {
					continue;
				} else if (xDistance > yDistance) {
					if (xDistance < distanceMoved[cow1]) {
						if (stoppedAt[cow2] < y1) {
							continue;
						} else {
							distanceMoved[cow1] = xDistance;
							stoppedAt[cow1] = Math.min(stoppedAt[cow1], x2);
						}
					}
				} else {
					if (yDistance < distanceMoved[cow2]) {
						if (stoppedAt[cow1] < x2) {
							continue;
						} else {
							distanceMoved[cow2] = yDistance;
							stoppedAt[cow2] = Math.min(stoppedAt[cow2], y1);
						}
					}
				}
			}
		}
		for (int i : distanceMoved) {
			if (i == 1000000000) {
				pw.println("Infinity");
			} else {
				pw.println(i);
			}
		}

		br.close();
		pw.close();
	}
	
	public static void sortByCol(ArrayList<int[]> arr, int col) {
		Collections.sort(arr, new Comparator<int[]>() {
			public int compare(final int[] arr1, final int[] arr2) {
				if (arr1[col] > arr2[col]) {
					return 1;
				} else {
					return -1;
				}
			}
		});
	}
}
