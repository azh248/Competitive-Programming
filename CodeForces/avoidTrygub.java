import java.util.*;
import java.io.*;

public class avoidTrygub {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int t = Integer.parseInt(st.nextToken());

		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			st = new StringTokenizer(br.readLine());
			String s = st.nextToken();
			int tQueue = 0;
			for (int j = 0; j < s.length() - 1; j++) {
				if (s.charAt(j) == 't') {
					tQueue++;
				}  else {
					pw.print(Character.toString(s.charAt(j)));
				}
			}
			pw.print(Character.toString(s.charAt(s.length() - 1)));
			for (int j = 0; j < tQueue; j++) {
				pw.print("t");
			}
			pw.println();
		}

		pw.close();
		br.close();
	}
}
