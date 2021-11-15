/*
ID: azh248
LANG: JAVA
TASK: lemonade
*/

import java.util.*;
import java.io.*;

public class lemonade {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("lemonade.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("lemonade.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		int[] arr = new int[n];

		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);
		
		int line = 0;

		for (int i = n - 1; i >= 0; i--) {
			if (arr[i] < line) {
				continue;
			} else {
				line++;
			}
		}
		pw.println(line);

		br.close();
		pw.close();
	}
}
