/*
ID: azh248
LANG: JAVA
TASK: triangles
*/

import java.util.*;
import java.io.*;

public class triangles {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("triangles.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("triangles.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

		/* 2 arraylists of the points at a specific x/y value. Then, we iterate through the y values and for the ones with size >= 2, we 
		iterate through all possible combos of 2 points and find the points with the same x value as one of them. Then, we find the area 
		of this triangle. */

		ArrayList<ArrayList<Integer>> xValuePoints = new ArrayList<>();
		ArrayList<ArrayList<Integer>> yValuePoints = new ArrayList<>();

		for (int i = 0; i < 2*Math.pow(10, 4); i++) {
			ArrayList<Integer> addX = new ArrayList<>();
			xValuePoints.add(addX);
			ArrayList<Integer> addY = new ArrayList<>();
			yValuePoints.add(addY);
		}
		ArrayList<Integer> allYValPoints = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken()) + 10000;
			int y = Integer.parseInt(st.nextToken()) + 10000;
			xValuePoints.get(x).add(y);
			yValuePoints.get(y).add(x);
			allYValPoints.add(y);
		}
		Collections.sort(allYValPoints);
		HashSet<Integer> workingYValPoints = new HashSet<>();
		for (int i = 0; i < allYValPoints.size() - 1; i++) {
			if (allYValPoints.get(i).equals(allYValPoints.get(i + 1))) {
				workingYValPoints.add(allYValPoints.get(i));
				i++;
			}
		}
		long areaSum = 0;
		for (int i : workingYValPoints) {
			for (int j = 0; j < yValuePoints.get(i).size(); j++) {
				for (int k = j + 1; k < yValuePoints.get(i).size(); k++) {
					int x1 = yValuePoints.get(i).get(j);
					int x2 = yValuePoints.get(i).get(k);
					for (int a = 0; a < xValuePoints.get(x1).size(); a++) {
						areaSum += Math.abs(i - xValuePoints.get(x1).get(a))*Math.abs(x1 - x2);
						areaSum %= 1000000007;
					}
					for (int b = 0; b < xValuePoints.get(x2).size(); b++) {
						areaSum += Math.abs(i - xValuePoints.get(x2).get(b)) * Math.abs(x1 - x2);
						areaSum %= 1000000007;
					}
				}
			}
		}
		pw.println(areaSum);

        br.close();
        pw.close();
    }
}
