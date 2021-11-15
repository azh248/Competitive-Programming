import java.util.*;
import java.io.*;

public class pingpong {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());

		/* Program: */

		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int aWins = 0;
			int bWins = 0;
			aWins = a - 1;
			bWins = b;
			pw.println(Integer.toString(aWins) + " " + Integer.toString(bWins));
		}

		pw.close();
		br.close();
	}
}
