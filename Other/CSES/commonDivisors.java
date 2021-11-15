/*
ID: azh248
LANG: JAVA
TASK: commonDivisors
*/

import java.util.*;
import java.io.*;

public class commonDivisors {
    static int[] factors;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        /* Program: */

        int[] arr = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        factors = new int[arr[arr.length - 1] + 1];

        for (int i : arr) {
            factor(i); // use this to find all factors
        }
        for (int i = arr[arr.length - 1]; i > 0; i--) {
            if (factors[i] >= 2) {
                pw.println(i);
                break;
            }
        }

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

    public static void factor(int n) {
        for (int i = 1; i*i <= n; i++) {
            if (n%i == 0) {
                factors[i] ++;
                if (i*i != n) factors[n/i] ++;
            }
        }
    }
}
