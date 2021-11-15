/*
ID: azh248
LANG: JAVA
TASK: div7
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class div7 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("div7.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("div7.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        ArrayList<Integer> cowID = new ArrayList<>();
        ArrayList<Long> cowPrefixSum = new ArrayList<>();
        cowPrefixSum.add((long)0);

        /*
         * iterate through sizes going down, if it hits a size that is a multiple of 7
         * then print it and stop
         */

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int id = Integer.parseInt(st.nextToken());
            cowID.add(id);
            cowPrefixSum.add(cowPrefixSum.get(Math.max(0, i - 1)) + id);
        }
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j <= n - i; j++) {
                if ((cowPrefixSum.get(j + i) - cowPrefixSum.get(j)) % 7 == 0) {
                    pw.println(i);
                    pw.close();
                    return;
                }
            }
        }
        pw.println(0);

        /**
         * What to watch out for: == doesn't work for equality for reference types
         * setting one variable equal to another makes it so that variable changes when
         * the original one does, to get around this use "new" start using ? in an if
         * else statement, put the else directly after the closing bracket you might
         * have to use larger data types --> for silver and above problems test cases
         * are huge when needing to find the max in an array, just use max =
         * Math.max(max, nextInt) check if the loops are in the right order (if each cow
         * has 3 amounts of milk, going through the amounts of milk first, then the cow
         * would be incorrect) try to break asap when tle, instead of using if (!x) ___,
         * use if (x) break; else ___ try to avoid unnecessary nested loops when setting
         * arraylists of arrays/arraylists equal to each other, make sure to clone the
         * arrays AT EVERY POINT THEY'RE IN CONTACT
         */

        br.close();
        pw.close();
    }
}
