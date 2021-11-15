/*
ID: azh248
LANG: JAVA
TASK: measurement
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class measurement {

  public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new FileReader("measurement.in"));
    PrintWriter pw = new PrintWriter(new FileWriter("measurement.out"));

    StringTokenizer st = new StringTokenizer(br.readLine()); // optional to break line into tokens


    /* creates 3 arraylists that track the day in which the entry took place,
    the cow that changed, and how much the change was. */
    ArrayList<Integer> entryDays = new ArrayList<>();
    int display = 7;
    ArrayList<String> displayCows = new ArrayList<>();
    String[] cows = {"Mildred", "Elsie", "Bessie"};
    displayCows.add("Mildred");
    displayCows.add("Elsie");
    displayCows.add("Bessie");
    ArrayList<String> cowThatChanges = new ArrayList<>();
    ArrayList<Integer> change = new ArrayList<>();
    ArrayList<Integer> cowMilks = new ArrayList<>(); // index 0 is Mildred, 1 is Elsie, 2 is Bessie
    cowMilks.add(7);
    cowMilks.add(7);
    cowMilks.add(7);
    int day;
    int index = 0;
    int displayChanges = 0;
    int tempDisplayChanges = 0;
    int N = Integer.parseInt(st.nextToken());
    for (int i = 0; i < N; i ++) {
      st = new StringTokenizer(br.readLine());
      day = Integer.parseInt(st.nextToken());
      entryDays.add(day);
      cowThatChanges.add(st.nextToken());
      change.add(Integer.parseInt(st.nextToken()));
    }
    // thing to do: make it so that the display also changes when the display cow changes milk, if it decreases milk, check if it's still the display cow
    // also make it so it doesn't double count when the display cow decreases
    for (int i = 0; i < 100; i ++) {
      tempDisplayChanges = displayChanges;
      // JUST A PROGRESS UPDATE
      // a
      // <o/
      if (i == 43) {
        System.out.println(displayCows);
      }
      if (entryDays.contains(i) == true) {
        System.out.println(i);
        index = entryDays.indexOf(i);
        String cow = cowThatChanges.get(index); // sketchy, might need new Integer(i)
        System.out.println(cow);
        int displayCowsLength = displayCows.size();
        boolean isDisplayCow = displayCows.contains(cow);
        int cowChange = change.get(index);
        int max = 0;
        int cowIndex = 4;
        if (cow.length() == 7) { // using cow lengths because for some reason the string doesn't work
          cowMilks.set(0, cowMilks.get(0) + cowChange);
          if (isDisplayCow == true) {
            if (cowChange < 0) {
              if (displayCowsLength == 1) {
                // check if its still lead cow
                for (int n = 0; n < 3; n ++) {
                  if (cowMilks.get(n) > max) {
                    max = cowMilks.get(n);
                    cowIndex = n;
                  }
                }
                if (cowMilks.get(0) == cowMilks.get(1) && cowMilks.get(1) == cowMilks.get(2)) {
                  displayCows.clear();
                  displayCows.add("Elsie");
                  displayCows.add("Bessie");
                  display = cowMilks.get(0);
                }
                else if (cowMilks.get(0) <= max) {
                  displayCows.clear();
                  displayCows.add(cows[cowIndex]);
                  display = max;
                }
              }
              else {
                displayCows.remove(cow);
                displayChanges += 1;
              }
              // check if its still lead cow

            }
            else {
              if (displayCowsLength == 1) {
                display += cowChange;
              }
              else {
                displayCows.clear();
                displayCows.add(cow);
                display += cowChange;
                displayChanges += 1;
              }
            }
          }
        }
        else if (cow.length() == 5) {
          cowMilks.set(1, cowMilks.get(1) + cowChange);
          if (isDisplayCow == true) {
            if (cowChange < 0) {
              if (displayCowsLength == 1) {
                // check if its still lead cow
                for (int n = 0; n < 3; n ++) {
                  if (cowMilks.get(n) > max) {
                    max = cowMilks.get(n);
                    cowIndex = n;
                  }
                }
                if (cowMilks.get(0) == cowMilks.get(1) && cowMilks.get(1) == cowMilks.get(2)) {
                  displayCows.clear();
                  displayCows.add("Mildred");
                  displayCows.add("Bessie");
                  display = cowMilks.get(0);
                }
                else if (cowMilks.get(1) <= max) {
                  displayCows.clear();
                  displayCows.add(cows[cowIndex]);
                  display = max;
                }
              }
              else {
                displayCows.remove(cow);
                displayChanges += 1;
              }
              // check if its still lead cow

            }
            else {
              if (displayCowsLength == 1) {
                display += cowChange;
              }
              else {
                displayCows.clear();
                displayCows.add(cow);
                display += cowChange;
                displayChanges += 1;
              }
            }
          }
        }
        else if (cow.length() == 6) {
          if (isDisplayCow == true) {
            if (cowChange < 0) {
              if (displayCowsLength == 1) {
                // check if its still lead cow
                for (int n = 0; n < 3; n ++) {
                  if (cowMilks.get(n) > max) {
                    max = cowMilks.get(n);
                    cowIndex = n;
                  }
                }
                if (cowMilks.get(0) == cowMilks.get(1) && cowMilks.get(1) == cowMilks.get(2)) {
                  displayCows.clear();
                  displayCows.add("Mildred");
                  displayCows.add("Elsie");
                  display = cowMilks.get(0);
                }
                if (cowMilks.get(2) <= max) {
                  displayCows.clear();
                  displayCows.add(cows[cowIndex]);
                  display = max;
                }
              }
              else {
                displayCows.remove(cow);
                displayChanges += 1;
              }
              // check if its still lead cow

            }
            else {
              if (displayCowsLength == 1) {
                display += cowChange;
              }
              else {
                displayCows.clear();
                displayCows.add(cow);
                display += cowChange;
                displayChanges += 1;
              }
            }
          }
          cowMilks.set(2, cowMilks.get(2) + cowChange);
        }

        if (displayChanges > tempDisplayChanges) {
        }
        else {
          if (cowMilks.get(0) > display && displayCows.contains("Mildred") == false) {
            displayChanges += 1;
            display = cowMilks.get(0);
            displayCows.clear();
            displayCows.add("Mildred");
          }
          else if (cowMilks.get(0) == display && displayCows.contains("Mildred") == false && displayCows.isEmpty() == false) {
            displayChanges += 1;
            displayCows.add("Mildred");
          }


          else if (cowMilks.get(1) > display && displayCows.contains("Elsie") == false) {
            displayChanges += 1;
            display = cowMilks.get(1);
            displayCows.clear();
            displayCows.add("Elsie");

          }
          else if (cowMilks.get(1) == display && displayCows.contains("Elsie") == false && displayCows.isEmpty() == false) {
            displayChanges += 1;
            displayCows.add("Elsie");
          }


          else if (cowMilks.get(2) > display && displayCows.contains("Bessie") == false) {
            displayChanges += 1;
            display = cowMilks.get(2);
            displayCows.clear();
            displayCows.add("Bessie");
          }
          else if (cowMilks.get(2) == display && displayCows.contains("Bessie") == false && displayCows.isEmpty() == false) {
            displayChanges += 1;
            displayCows.add("Bessie");
          }
        }
        System.out.println(displayChanges);
        System.out.println(cowMilks);
        System.out.println();
      }
    }


    pw.println(displayChanges);
    pw.close();
    br.close();
  }

}
