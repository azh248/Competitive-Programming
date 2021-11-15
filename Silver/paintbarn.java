/*
ID: azh248
LANG: JAVA
TASK: paintbarn
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class painbarn {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("paintbarn.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("paintbarn.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[][] barnWallDifferences = new int[1010][1010]; // each value in this is the actual wall's amount of paint[x]
                                                           // - actualWall[x-1], so it's easier to add all the elements
                                                           // in a rectangle
        // watch out --> the coordinate plane for 2d arrays is different from the one in
        // the problem

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            for (int j = y1; j < y2; j++) {
                barnWallDifferences[j + 1][x1 + 1]++; // the +1 is for 1-shifting so in the future its easier to get the
                                                      // actual wall's paint values
                barnWallDifferences[j + 1][x2 + 1]--;
            }
        }

        /* retrieve number of paint using the differences */

        int[][] barnWall = new int[1010][1010];
        int kCount = 0;

        for (int i = 1; i < 1010; i++) {
            int lastIndex = 0;
            for (int j = 1; j < 1010; j++) {
                if (barnWallDifferences[i][j] != 0) {
                    lastIndex = j;
                }
            }
            if (lastIndex == 0) {
                continue;
            }
            for (int j = lastIndex - 1; j >= 0; j--) {
                barnWall[i][j] = barnWall[i][j + 1] - barnWallDifferences[i][j + 1];
                if (barnWall[i][j] == k)
                    kCount++;
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                System.out.print(barnWall[i][j] + " ");
            }
            System.out.println();
        }
        pw.println(kCount);

        /*
         * use 2d prefix sums, find how much is covered by k layers of paint, then find
         * the tiles that are covered by k-1 coats of paint and determine the best 2
         * rectangles to paint
         */

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
