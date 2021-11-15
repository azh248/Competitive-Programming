/*
ID: azh248
LANG: JAVA
TASK: sleepy
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class sleepy {

    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        public InputReader() throws FileNotFoundException {
            br = new BufferedReader(new FileReader("sleepy.in"));
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
        PrintWriter pw = new PrintWriter(new FileWriter("sleepy.out"));

        int n = ir.nextInt();
        ArrayList<Integer> cowArrangement = new ArrayList<>();
        ArrayList<Integer> optimalArrangement = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            cowArrangement.add(ir.nextInt());
            optimalArrangement.add(i + 1);
        }

        int moves = 0;

        while (!cowArrangement.equals(optimalArrangement)) {
            cowArrangement = moveCow(cowArrangement);
            moves++;
        }

        pw.println(moves);

    
        /*
         * What to watch out for: == doesn't work for equality for reference types
         * setting one variable equal to another makes it so that variable changes when
         * the original one does, to get around this use "new"
         * 
         * 
         */

        pw.close();
    }
    public static ArrayList<Integer> moveCow(ArrayList<Integer> ordering) {
        int sequenceLength = 1;
        for (int i = ordering.size() - 1; i >= 0; i --) {
            if (i != 0) {
                if (ordering.get(i) > ordering.get(i - 1)) {
                    sequenceLength ++;
                } else {
                    break; // sketchy, check if this breaks out of the outer loop
                }
            }
            else {
                sequenceLength ++;
            }
        }
        for (int i = ordering.size() - 1; i >= ordering.size() - sequenceLength; i --) {
            if (ordering.get(0) > ordering.get(i)) {
                int x = ordering.get(0);
                ordering.remove(0);
                ordering.add(i, x);
                break; // check if this breaks out of the outer loop
            } else { 
                if (i == ordering.size() - sequenceLength) {
                    ordering.add(ordering.size() - sequenceLength, ordering.get(0));
                    ordering.remove(0);
                }
            }
        }
        return ordering;

    }

}
