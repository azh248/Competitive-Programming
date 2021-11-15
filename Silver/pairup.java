/*
ID: azh248
LANG: JAVA
TASK: pairup
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class pairup {
  public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new FileReader("pairup.in"));
    PrintWriter pw = new PrintWriter(new FileWriter("pairup.out"));

    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    ArrayList<int[]> arr = new ArrayList<int[]>();

    /* Program: */

    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());
      int[] add = {x, y};
      arr.add(add);
    }
    sortByColumn(arr, 1);
    long minSum = 0L;
    int pointer0 = 0;
    int pointer1 = n - 1;
    while (pointer1 - pointer0 > 0) {
        int max = 0;
        int min = 0;
        if (arr.get(pointer0)[0] > arr.get(pointer1)[0]) {
            max = pointer0;
            min = pointer1;
            pointer1 --;
        } else if (arr.get(pointer0)[0] < arr.get(pointer1)[0]) {
            max = pointer1;
            min = pointer0;
            pointer0 ++;
        } else {
            max = pointer1;
            min = pointer0;
            pointer0 ++;
            pointer1 --;
        }
        int[] add = new int[2];
        add[1] = arr.get(max)[1];
        add[0] = arr.get(max)[0] - arr.get(min)[0];
        arr.set(max, add);
        if (arr.get(max)[1] + arr.get(min)[1] > minSum) {
            minSum = arr.get(max)[1] + arr.get(min)[1];
        }
    }

    pw.println(minSum);
    /**
     * What to watch out for: == doesn't work for equality for reference types
     * setting one variable equal to another makes it so that variable changes when
       the original one does, to get around this use "new" or .clone() with a cast, if it's a list of lists you have to do a deep clone
     * you might have to use larger data types --> for silver and above problems test cases are huge
     * check if the loops are in the right order (if each cow has n amounts of milk, going through the amounts of milk first, then the cows would be incorrect)
     * try to break asap when tle, instead of using if (!x) ___, use if (x) break; else ___
     * try to avoid unnecessary nested loops
     * use more methods
     */

    br.close();
    pw.close();
  }
  public static void sortByColumn(ArrayList<int[]> arr, int col) {
      Collections.sort(arr, new Comparator<int[]>() {
          public int compare(final int[] entry1, final int[] entry2) {
              if (entry1[col] > entry2[col])
                  return 1;
              else
                  return -1;
          }
      });
  }
}
