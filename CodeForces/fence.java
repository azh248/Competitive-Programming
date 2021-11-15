import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class fence {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        /* Program: */

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int[] arr = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), 
                    Integer.parseInt(st.nextToken())};
            Arrays.sort(arr);
            pw.println(Math.max(1, arr[2] - arr[1] - arr[0] + 1));
        }

        pw.close();
        br.close();
    }

}
