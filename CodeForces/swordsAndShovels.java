import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class swordsAndShovels {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        /* Program: keep making 1 sword/1 shovel until diamonds/sticks > 2 or diamonds/sticks < 1/2 */

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int sticks = Integer.parseInt(st.nextToken());
            int diamonds = Integer.parseInt(st.nextToken());
            int moves = 0;
            if (sticks == 0 || diamonds == 0) {
                pw.println(0);
                continue;
            }
            while (1 + Math.min(Math.min(sticks - 3, diamonds - 3), Math.max(sticks - 3, diamonds - 3) / 2) > Math.min(Math.min(sticks, diamonds), Math.max(sticks, diamonds) / 2)) {
                sticks -= 3;
                diamonds -= 3;
                moves++;
            }
            moves += Math.min(Math.min(sticks, diamonds), Math.max(sticks, diamonds)/2);
            pw.println(moves);
        }

        pw.close();
        br.close();
    }
}
