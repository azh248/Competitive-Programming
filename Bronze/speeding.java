/*
ID: azh248
LANG: JAVA
TASK: speeding
*/

import java.util.*;
import java.io.*;

public class speeding {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("speeding.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("speeding.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        /* Program: */

        int[] arr = new int[101];

        int distanceTraveled = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int distance = Integer.parseInt(st.nextToken());
            int speedLimit = Integer.parseInt(st.nextToken());
            for (int j = 0; j < distance; j++) {
                arr[distanceTraveled + j] =  speedLimit;
            }
            distanceTraveled += distance;
        }
        distanceTraveled = 0;
        int maxOverSpeedLimit = 0;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int distance = Integer.parseInt(st.nextToken());
            int speedLimit = Integer.parseInt(st.nextToken());
            for (int j = 0; j < distance; j++) {
                if (arr[distanceTraveled + j] < speedLimit) {
                    if (speedLimit - arr[distanceTraveled + j] > maxOverSpeedLimit) {
                        maxOverSpeedLimit = speedLimit - arr[distanceTraveled + j];
                    }
                }
            }
            distanceTraveled += distance;
        }
        pw.println(maxOverSpeedLimit);
        

        /**
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
