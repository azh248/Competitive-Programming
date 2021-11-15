import java.util.*;
import java.io.*;

public class validTriangle {

	static int n, a, b, c;
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());

			if (a + b > c && b + c > a && a + c > b) {
				pw.println("Yes");
			} else {
				pw.println("No");
			}
		}

		pw.close();
		br.close();
	}
}
