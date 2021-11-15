/*
ID: azh248
LANG: JAVA
TASK: mixmilk
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class mixmilk {

  public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new FileReader("mixmilk.in"));
    PrintWriter pw = new PrintWriter(new FileWriter("mixmilk.out"));

    /* read file input */
    StringTokenizer st = new StringTokenizer(br.readLine()); // optional to break line into tokens

    int capacity1 = Integer.parseInt(st.nextToken());
    int milk1 = Integer.parseInt(st.nextToken());

    StringTokenizer st1 = new StringTokenizer(br.readLine()); // optional to break line into tokens

    int capacity2 = Integer.parseInt(st1.nextToken());
    int milk2 = Integer.parseInt(st1.nextToken());

    StringTokenizer st2 = new StringTokenizer(br.readLine()); // optional to break line into tokens

    int capacity3 = Integer.parseInt(st2.nextToken());
    int milk3 = Integer.parseInt(st2.nextToken());

    /* creates an array for the capacities */
    int[] capacities = {capacity1, capacity2, capacity3};
    ArrayList<Integer> milkAmounts = new ArrayList<>();
    milkAmounts.add(milk1);
    milkAmounts.add(milk2);
    milkAmounts.add(milk3);
    for (int i = 0; i < 100; i ++) {
      int x = i%3;
      System.out.println(milkAmounts);
      if (milkAmounts.get((x + 1)%3) < capacities[(x + 1)%3] && milkAmounts.get(x) > 0) {
        if (milkAmounts.get((x+1)%3) + milkAmounts.get(x) > capacities[(x+1)%3]) {
          milkAmounts.set(x, milkAmounts.get(x) - capacities[(x+1)%3] + milkAmounts.get((x+1)%3));
          milkAmounts.set((x+1)%3, capacities[(x+1)%3]);
        }
        else {
          milkAmounts.set((x+1)%3, milkAmounts.get((x+1)%3) + milkAmounts.get(x));
          milkAmounts.set(x, 0);
        }
      }
    }
    pw.println(milkAmounts.get(0));
    pw.println(milkAmounts.get(1));
    pw.println(milkAmounts.get(2));
    pw.close();
    br.close();
  }

}
