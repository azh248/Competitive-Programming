/*
ID: azh248
LANG: JAVA
TASK: daisyChains 
*/

import java.util.*;
import java.io.*;

public class daisyChains {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		int[] petals = new int[n];

		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < n; i++) {
			petals[i] = Integer.parseInt(st.nextToken());
		}
		int averageFlowers = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int sum = 0;
				for (int k = i; k <= j; k++) {
					sum += petals[k];
				}
				double average = (double)sum/(double)(j - i + 1);
				for (int k = i; k <= j; k++) {
					if (petals[k] == average) {
						averageFlowers++;
						break;
					}
				}
			}
		}
		pw.println(averageFlowers);

		br.close();
		pw.close();
	}
}
