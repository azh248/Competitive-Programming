ID: azh248
LANG: JAVA
TASK: swap
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class swap {

    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        public InputReader() throws FileNotFoundException {
            br = new BufferedReader(new FileReader("swap.in"));
            st = null;
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) throws IOException {

        InputReader ir = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("swap.out"));

        int n = ir.nextInt();
        int k = ir.nextInt();

        ArrayList<Integer> cowOrders = new ArrayList<>();
        ArrayList<Integer> originalCowOrders = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            cowOrders.add(i + 1);
        }

        for (Integer i : cowOrders) {
            originalCowOrders.add(i);
        }
    
        int a1 = ir.nextInt();
        int a2 = ir.nextInt();
        int b1 = ir.nextInt();
        int b2 = ir.nextInt();

        int repeatingNum = 0;

        for (int i = 1; i <= k; i ++) {
            for (int j = a1; j <= (int)((a2 + a1 - 1)/2); j ++) {
                int a = cowOrders.get(j - 1);
                int b = cowOrders.get(a2 - j + a1 - 1);
                cowOrders.set(j - 1, b);
                cowOrders.set(a2 - j + a1 - 1, a);
            }
            for (int j = b1; j <= (int)((b2 + b1 - 1)/2); j ++) {
                int a = cowOrders.get(j - 1);
                int b = cowOrders.get(b2 - j + b1 - 1);
                cowOrders.set(j - 1, b);
                cowOrders.set(b2 - j + b1 - 1, a);
            }
            if (cowOrders.equals(originalCowOrders)) {
                repeatingNum = i;
                while (i + repeatingNum <= k - 1 && i != 1) {
                    i += repeatingNum;
                }
            }
        }

        for (Integer x : cowOrders) {
            pw.println(x);
        }
        pw.close();
    }

}
