import java.util.*;
import java.io.*;

public class robotProgram {

  public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);

    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());

    /* Program: */

    for (int i = 0; i < n; i++) {
		st = new StringTokenizer(br.readLine());
		int x = Math.abs(Integer.parseInt(st.nextToken()));
		int y = Math.abs(Integer.parseInt(st.nextToken()));
		if (Math.abs(x - y) > 1) {
			int moves = 0;
			int k = Math.min(x, y);
			moves += (2*k) + 1;
			moves += 2*(Math.max(x, y) - k - 1);
			pw.println(moves);
		} else {
			pw.println(Math.abs(x) + Math.abs(y));
		}
    }

    pw.close();
    br.close();
  }
}