import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class dreamoonStairs {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter pw = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();

        if (m > n) {
            pw.println(-1);
        } else {
            int x = (n/2 - 5)/m;
            while (true) {
                if (m*x >= (int) ((n + 1)/2)) {
                    break;
                } else {
                    x++;
                }
            }
            pw.println(x * m);
        }

        pw.close();
        sc.close();
    }

}
