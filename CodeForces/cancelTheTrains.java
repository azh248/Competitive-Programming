import java.util.*;
import java.io.*;

public class cancelTheTrains {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());

		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(br.readLine());
	
			boolean[] bottom = new boolean[101];
			for (int j = 0; j < n; j++) {
				bottom[Integer.parseInt(st.nextToken())] = true;
			}
			st = new StringTokenizer(br.readLine());
			boolean[] top = new boolean[101];
			for (int j = 0; j < m; j++) {
				top[Integer.parseInt(st.nextToken())] = true;
			}
			int cancelled = 0;
			for (int j = 0; j <= 100; j++) {
				if (bottom[j]) {
					if (top[j]) {
						cancelled++;
					}
				}
			}
			pw.println(cancelled);
		}

		pw.close();
		br.close();
	}
}
