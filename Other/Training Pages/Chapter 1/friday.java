/*
ID: azh248
LANG: JAVA
TASK: friday
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class friday {

  public static void main(final String[] args) throws IOException {

    final BufferedReader br = new BufferedReader(new FileReader("friday.in"));
    final PrintWriter pw = new PrintWriter(new FileWriter("friday.out"));

    final int N = Integer.parseInt(br.readLine());

    // arrays of the occurences of the days on 13ths in 1 year --> starting on monday, repeating twice to allow for the year starting on any day
    final int[] leapYearMonday = { 1, 2, 2, 1, 2, 3, 1};
    final int[] regularYearMonday = { 1, 3, 1, 2, 2, 2, 1};

    // creates a hashmap that links year to the starting day of the year
    final HashMap<Integer, Integer> startingDayOfTheYear = new HashMap<>();
    startingDayOfTheYear.put(0, 0);
    for (int i = 1; i < N; i ++) {
      if (isLeapYear(i + 1899) == true) {
        startingDayOfTheYear.put(i, (startingDayOfTheYear.get(i - 1) + 2)%7);
      }
      else {
        startingDayOfTheYear.put(i, (startingDayOfTheYear.get(i - 1) + 1)%7);
      }
    }

    // creates a hashmap that counts how many of each day appears on the 13th
    final int[] numberDay = new int[7];

    // adds to day variables according to day, cycles through the week adding
    // for each year, we find its starting day and cycle through the arrays according to that. it adds according to the monday years, but shifts it forwards/backwards

    for (final Map.Entry<Integer, Integer> x : startingDayOfTheYear.entrySet()) {
      if (isLeapYear((int)x.getKey() + 1900) == true) {
        final int a = x.getValue(); // now for every case of the starting day, we need to add the 6 consecutive days of leapYearMonday afterwards to the 6 corresponding variables
        for (int i = 0; i < 7; i ++) {
          numberDay[i] += leapYearMonday[(7+i-a)%7];
          }


      }
      else {
        final int c = x.getValue();
        for (int i = 0; i < 7; i ++) {
          numberDay[i] += regularYearMonday[(7-c+i)%7];
        }
    }

  }
    pw.println(numberDay[5] + " " + numberDay[6] + " " + numberDay[0] + " " + numberDay[1] + " " + numberDay[2] + " " + numberDay[3] + " " + numberDay[4]);
    pw.close();
    br.close();
  }



  // returns true if leap year, false otherwise
  public static boolean isLeapYear(final int i) {
    if (i % 100 == 0) {
      if (i % 400 == 0) {
        return true;
      }
      else {
        return false;
      }
    }
    else {
      if (i % 4 == 0) {
        return true;
      }
      else {
        return false;
      }
    }
  }
}
