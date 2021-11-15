/*
ID: azh248
LANG: JAVA
TASK: bcount
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class bcount {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("bcount.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("bcount.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];

        /* Program: */

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int[] prefixHolsteins = new int[n];
        int[] prefixGuernseys = new int[n];
        int[] prefixJerseys = new int[n];

        if (arr[0] == 1) {
            prefixHolsteins[0] = 1;
        } else if (arr[0] == 2) {
            prefixGuernseys[0] = 1;
        } else {
            prefixJerseys[0] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (arr[i] == 1) {
                prefixHolsteins[i] = prefixHolsteins[i - 1] + 1;
                prefixGuernseys[i] = prefixGuernseys[i - 1];
                prefixJerseys[i] = prefixJerseys[i - 1];
            } else if (arr[i] == 2) {
                prefixGuernseys[i] = prefixGuernseys[i - 1] + 1;
                prefixHolsteins[i] = prefixHolsteins[i - 1];
                prefixJerseys[i] = prefixJerseys[i - 1];
            } else {
                prefixJerseys[i] = prefixJerseys[i - 1] + 1;
                prefixHolsteins[i] = prefixHolsteins[i - 1];
                prefixGuernseys[i] = prefixGuernseys[i - 1];
            }
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            if (a == 0) {
                pw.println(Integer.toString(prefixHolsteins[b]) + " " + Integer.toString(prefixGuernseys[b]) + " " + Integer.toString(prefixJerseys[b]));
            } else {
                pw.println(Integer.toString(prefixHolsteins[b] - prefixHolsteins[a - 1]) + " " + Integer.toString(prefixGuernseys[b] - prefixGuernseys[a - 1]) + " " + Integer.toString(prefixJerseys[b] - prefixJerseys[a - 1]));
            }
        }

        /**
         * What to watch out for: == doesn't work for equality for reference types
         * setting one variable equal to another makes it so that variable changes when
         * the original one does, to get around this use "new" or .clone() with a cast,
         * if it's a list of lists you have to do a deep clone you might have to use
         * larger data types --> for silver and above problems test cases are
         * huge!!!!!!!!!!!!!! check if the loops are in the right order (if each cow has
         * n amounts of milk, going through the amounts of milk first, then the cows
         * would be incorrect) try to break asap when tle, instead of using if (!x) ___,
         * use if (x) break; else ___ try to avoid unnecessary nested loops use treeset
         * --> built in bsearch for floor and ceiling use linkedlist --> O(1) insertion
         * and deletion but O(n) accessing
         */

        br.close();
        pw.close();
    }
}
