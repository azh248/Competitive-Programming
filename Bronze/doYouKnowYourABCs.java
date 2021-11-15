/*
ID: azh248
LANG: JAVA
TASK: doYouKnowYourABCs 
*/

import java.util.*;
import java.io.*;

public class doYouKnowYourABCs {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int[] arr = new int[7];

		for (int i = 0; i < 7; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);
		int[] abc = {arr[0], arr[1], arr[6] - arr[0] - arr[1]};
		Arrays.sort(abc);
		pw.println(Integer.toString(abc[0]) + " " + Integer.toString(abc[1]) + " " + Integer.toString(abc[2]));

		br.close();
		pw.close();
	}
}
