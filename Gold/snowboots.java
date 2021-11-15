/*
ID: azh248
LANG: JAVA
TASK: snowboots
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class snowboots {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("snowboots.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("snowboots.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        int[] snowDepths = new int[n];

        /*
         * try each pair of boots, in each step always go to the furthest possible tile
         */

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            snowDepths[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < b; i++) {
            st = new StringTokenizer(br.readLine());
            int depth = Integer.parseInt(st.nextToken());
            int distance = Integer.parseInt(st.nextToken());

            int position = 0;
            boolean keepGoing = true;
            while (position != n) {
                if (distance + position >= n) {
                    position = n;
                    break;
                } else if (keepGoing) {
                    boolean canStep = false;
                    for (int j = distance; j > 0; j--) {
                        if (depth >= snowDepths[j + position]) {
                            canStep = true;
                            position += j;
                            break;
                        }
                    }
                    if (!canStep) {
                        pw.println(0);
                        keepGoing = false;
                        break;
                    }
                }
            }
            if (keepGoing) {
                pw.println(1);
            }
        }

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
