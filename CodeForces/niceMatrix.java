import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class niceMatrix {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(st.nextToken());

        /* Program: split each column/row in half and floor, then make all 4 symmetric vertices equal. If m/n is odd, make their row/column equal too. */

        for (int i = 0; i < t; i++) {
            st = new StringTokenizer(br.readLine());
            long moves = 0;
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int[][] arr = new int[n][m];
            for (int j = 0; j < n; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < m; k++) {
                    arr[j][k] = Integer.parseInt(st.nextToken());
                }
            }
            for (int j = 0; j < (int)(n / 2); j++) {
                for (int k = 0; k < (int)(m / 2); k++) {
                    int topLeft = arr[j][k];
                    int bottomLeft = arr[n - j - 1][k];
                    int topRight = arr[j][m - k - 1];
                    int bottomRight = arr[n - j - 1][m - k - 1];
                    int average = Math.max(Math.min(topLeft, bottomLeft), Math.min(topRight, bottomRight));
                    moves += (Math.abs(average - topLeft) + Math.abs(average - topRight) + Math.abs(average - bottomLeft) + Math.abs(average - bottomRight));
                }
            }
            if (n % 2 == 1) {
                for (int j = 0; j < (int)(m / 2); j++) {
                    int left = arr[(int)(n / 2)][j];
                    int right = arr[(int)(n / 2)][m - j - 1];
                    moves += Math.abs(left - right);
                }
            } if (m % 2 == 1) {
                for (int j = 0; j < (int)(n / 2); j++) {
                    int left = arr[j][(int)(m / 2)];
                    int right = arr[n - j - 1][(int)(m / 2)];
                    moves += Math.abs(left - right);
                }
            }
            pw.println(moves);
        }

        pw.close();
        br.close();
    }

}
