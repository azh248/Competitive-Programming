import java.util.*;
import java.io.*;

public class parity {

	static int n;
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());

		int[] arr = new int[n];

		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int result1 = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] % 2 != i % 2) {
				result1++;
			}
		}

		int result2 = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] % 2 == i % 2) {
				result2++;
			}
		}

		pw.println(Math.min(result1, result2));

		pw.close();
		br.close();
	}
}
