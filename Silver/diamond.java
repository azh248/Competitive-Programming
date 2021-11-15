/*
ID: azh248
LANG: JAVA
TASK: diamond
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class diamond {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("diamond.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("diamond.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        /* do two pointers for the diamonds and have an array of int arrays of size 2 that contain the bounds from one
        index to the second, if the first pointer moves up (it's reached the maximum) we add it to an array of int[] bounds.
        This ensures that we have all the possible diamond cases that we need. Now we have to find the maximum 
        2 cases that don't intersect, or the maximum intersecting 2 cases that create one large bound. */
        
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        ArrayList<Integer> diamonds = new ArrayList<>();
        ArrayList<int[]> maxDiamondCaseBounds = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            diamonds.add(Integer.parseInt(st.nextToken()));
        }
        Collections.sort(diamonds);
        int pointer1 = 0;
        int pointer2 = 0;
        int diamondSize = 1;
        int maxDiamondSize = 1;
        
        while (pointer2 < diamonds.size() - 1) { // want to minimize maxDiamondCaseBounds size or determine the most efficient 2 cases without having to iterate
            if (diamonds.get(pointer2 + 1) <= diamonds.get(pointer1) + k) {
                pointer2 ++;
                diamondSize ++;
            } else {
                int[] x = { pointer1, pointer2 };
                maxDiamondCaseBounds.add(x);
                pointer1 ++;
                diamondSize --;
            }
            if (diamondSize > maxDiamondSize) {
                maxDiamondSize = diamondSize;
            }
        }
        int[] x = { pointer1, pointer2 };
        maxDiamondCaseBounds.add(x);
        int maxTwoCaseSize = 0;

        for (int i = 0; i < maxDiamondCaseBounds.size(); i++) {
            for (int j = i + 1; j < maxDiamondCaseBounds.size(); j++) {
                int twoCaseSize = 0;
                int[] arr1 = maxDiamondCaseBounds.get(i);
                int[] arr2 = maxDiamondCaseBounds.get(j);
                if (arr1[1] >= arr2[0] - 1) {
                    twoCaseSize = arr2[1] - arr1[0] + 1;
                } else {
                    twoCaseSize = arr1[1] - arr1[0] + 1 + arr2[1] - arr2[0] + 1;
                }
                if (twoCaseSize > maxTwoCaseSize) {
                    maxTwoCaseSize = twoCaseSize;
                }
            }
        }

        pw.println(maxTwoCaseSize);

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
