import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class game23 {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter pw = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int moves = 0;


        if (m == n) {
            pw.println(0);
        } else if (testIfDivisible(n, m) == false) {
            pw.println(-1);
        } else {
            while (m/n % 2 == 0) {
                moves ++;
                n *= 2;
            } while (m/n % 3 == 0) {
                moves ++;
                n *= 3;
            }
            pw.println(moves);
        }

        pw.close();
        sc.close();
    }
    static boolean testIfDivisible(int n, int m) {
        if (m/n %2 != 0 && m/n %3 != 0 || m % n != 0) {
            return false;
        } else if (m%n != 0) {
            return false;
        } while (m/n %2 == 0) {
            n *= 2;
        } while (m/n %3 == 0) {
            n *= 3;
        }
        return true;
    }
}
