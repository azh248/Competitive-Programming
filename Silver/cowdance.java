/*
ID: azh248
LANG: JAVA
TASK: cowdance
*/

import java.util.*;
import java.io.*;

public class cowdance {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("cowdance.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("cowdance.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];

        /* Program: */

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i] =  Integer.parseInt(st.nextToken());
        }
        // need to binary search on the values of k and test if each one works
        int left = 1; 
        int right = n;
        while (true) {
            int mid = (right + left) / 2;
            if (danceWorks(arr, mid, t, n)) {
                if (mid == n) {
                    pw.println(mid);
                    break;
                } else if (right - left <= 1) {
                    pw.println(mid);
                    break;
                } else {
                    right = mid;
                }
            } else {
                if (left == mid) {
                    pw.println(right);
                    break;
                }
                left = mid;
            }
        }

        /**
         * What to watch out for: == doesn't work for equality for reference typeswait
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
    public static boolean danceWorks(int[] arr, int k, int t, int n) {
        ArrayList<Integer> dancers = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            dancers.add(arr[i]);
        }
        int time = 0;
        Collections.sort(dancers);
        for (int i = k; i < n; i++) {
            int leastDancer = dancers.get(0);
            time += leastDancer;
            int nextDancer = arr[i];
            dancers.remove(0);
            for (int j = 0; j < dancers.size(); j++) {
                dancers.set(j, dancers.get(j) - leastDancer);
            }
            for (int j = 0; j < dancers.size() - 1; j++) {
                if (nextDancer >= dancers.get(j) && nextDancer <= dancers.get(j + 1)) {
                    dancers.add(j + 1, nextDancer); // takes up time
                    break;
                } else if (nextDancer <= dancers.get(0)) {
                    dancers.add(0, nextDancer); // takes up time
                    break;
                } else if (nextDancer >= dancers.get(dancers.size() - 1)) {
                    dancers.add(nextDancer);
                    break;
                }
            }
        }
        time += dancers.get(dancers.size() - 1);
        if (time <= t) return true;
        else return false;
    }
}
