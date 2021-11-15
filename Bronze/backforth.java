/*
ID: azh248
LANG: JAVA
TASK: backforth
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class backforth {

    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        public InputReader() throws FileNotFoundException {
            br = new BufferedReader(new FileReader("backforth.in"));
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
        PrintWriter pw = new PrintWriter(new FileWriter("backforth.out"));
        ArrayList<Integer> milkSize1 = new ArrayList<>();
        ArrayList<Integer> milkSize2 = new ArrayList<>();
        ArrayList<Integer> originalMilkSize1 = new ArrayList<>();
        ArrayList<Integer> originalMilkSize2 = new ArrayList<>();
        ArrayList<Integer> uniqueMilks = new ArrayList<>();

        for (int i = 0; i < 10; i ++) {
            int x = ir.nextInt();
            originalMilkSize1.add(x);
        }
        for (int i = 0; i < 10; i++) {
            int x = ir.nextInt();
            originalMilkSize2.add(x);
        }

        int milk1 = 1000;
        int milk2 = 1000;
        for (Integer i : originalMilkSize1) {
            milkSize1.add(i);
        }
        for (Integer i : originalMilkSize2) {
            milkSize2.add(i);
        }


        for (int a = 0; a < milkSize1.size(); a ++) {       
            for (int b = 0; b < milkSize2.size(); b ++) {
                for (int c = 0; c < milkSize1.size(); c ++) {
                    for (int d = 0; d < milkSize2.size(); d ++) {
                        milk1 -= milkSize1.get(a);
                        milk2 += milkSize1.get(a);
                        milkSize2.add(milkSize1.get(a));
                        milkSize1.remove(a);

                        milk2 -= milkSize2.get(b);
                        milk1 += milkSize2.get(b);
                        milkSize1.add(milkSize2.get(b));
                        milkSize2.remove(b);

                        milk1 -= milkSize1.get(c);
                        milk2 += milkSize1.get(c);
                        milkSize2.add(milkSize1.get(c));
                        milkSize1.remove(c);

                        milk2 -= milkSize2.get(d);
                        milk1 += milkSize2.get(d);
                        milkSize1.add(milkSize2.get(d));
                        milkSize2.remove(d);

                        milkSize1.clear();
                        milkSize2.clear();
                        for (Integer i : originalMilkSize1) {
                            milkSize1.add(i);
                        }
                        for (Integer i : originalMilkSize2) {
                            milkSize2.add(i);
                        }

                        if (!uniqueMilks.contains(milk1)) {
                            uniqueMilks.add(milk1);
                        }
                        milk1 = 1000;
                        milk2 = 1000;
                    }
                }
            }
        }

        pw.println(uniqueMilks.size());




        /*
         * What to watch out for: == doesn't work for equality for reference types
         * setting one variable equal to another makes it so that variable changes when
         * the original one does, to get around this use "new"
         * there could be repeats of the same amount
         * 
         */

        pw.close();
    }

}
