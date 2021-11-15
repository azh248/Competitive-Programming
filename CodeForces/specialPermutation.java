import java.util.*;
import java.io.*;

public class specialPermutation {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());

		/* Program: */

		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			for (int j = 0; j < n - 1; j++) {
				pw.print(Integer.toString(j + 2) + " ");
			}
			pw.println(1);
		}

		pw.close();
		br.close();
	}
}
