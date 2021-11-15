/*
ID: azh248
LANG: JAVA
TASK: hps
*/

import java.util.*;
import java.io.*;

public class hps {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("hps.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("hps.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        /* Program: prefix sums */

        int[] hooves = new int[n];
        int[] papers = new int[n];
        int[] scissors = new int[n];
        
        st = new StringTokenizer(br.readLine());
        String str = st.nextToken();
        if (str.equals("P")) {
            papers[0] = 1;
            hooves[0] = 0;
            scissors[0] = 0;
        } else if (str.equals("H")) {
            papers[0] = 0;
            hooves[0] = 1;
            scissors[0] = 0;
        } else if (str.equals("S")) {
            papers[0] = 0;
            hooves[0] = 0;
            scissors[0] = 1;
        }
        for (int i = 1; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            str = st.nextToken();
            if (str.equals("P")) {
                papers[i] = papers[i - 1] + 1;
                hooves[i] = hooves[i - 1];
                scissors[i] = scissors[i - 1];
            } else if (str.equals("H")) {
                papers[i] = papers[i - 1];
                hooves[i] = hooves[i - 1] + 1;
                scissors[i] = scissors[i - 1];
            } else if (str.equals("S")) {
                papers[i] = papers[i - 1];
                hooves[i] = hooves[i - 1];
                scissors[i] = scissors[i - 1] + 1;
            }
        }
        int maxGamesWon = 0;
        int[][] arr = {hooves, papers, scissors};
        for (int[] i : arr) {
            for (int[] j : arr) {
                for (int k = 0; k < n; k++) {
                    int gamesWon = i[k] + j[n - 1] - j[k];
                    if (gamesWon > maxGamesWon) maxGamesWon = gamesWon;
                }
            }
        }
        pw.println(maxGamesWon);

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
