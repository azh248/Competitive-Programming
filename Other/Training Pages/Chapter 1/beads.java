/*
ID: azh248
LANG: JAVA
TASK:beads
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class beads {

  public static void main(String[] args) throws IOException {

    Scanner br = new Scanner(new File("beads.in"));
    PrintWriter pw = new PrintWriter(new FileWriter("beads.out"));
    int n = Integer.parseInt(br.nextLine().trim());
    ArrayList<String> necklace = new ArrayList<>();
    String halfW = br.nextLine();
    String w = (halfW + halfW).trim();
    for (int i = 0; i < w.length(); i ++) {
      necklace.add(Character.toString(w.charAt(i)));
    }
    int tempSize = necklace.size();
    for (int i = 0; i < tempSize; i ++) {
      necklace.add(necklace.get(i));
    }
    int longest = 0;
    ArrayList<Character> streak = new ArrayList<>();
    ArrayList<Integer> bothSidesStreak = new ArrayList<>();
    boolean keepGoing = true;
    if (necklace.contains("w") == false && necklace.contains("b") == false) {
      pw.println(n);
    }
    else if (necklace.contains("w") == false && necklace.contains("r") == false) {
      pw.println(n);
    }
    else if (necklace.contains("b") == false && necklace.contains("r") == false) {
      pw.println(n);
    }
    else {
    /* go to every boundary between 2 beads, look at b to the left r to the right, r to the left b to the right */

    // thing to fix: it's not always reaching b, sometimes it just reaches the beginning while going, also after it reaches a b it doesn't stop, it keeps going and it might find another larger streak
    for (int i = 0; i < w.length(); i ++) {
      bothSidesStreak.clear();
      keepGoing = true;
      streak.clear();
      for (int x = i; x > 0; x --) {
        // if that character is a b, clear the streak but add it to the big streak
        if (w.charAt(x) == 'b' && keepGoing == true) {
          bothSidesStreak.add(streak.size());
          streak.clear();
          keepGoing = false;
        }
        else {
          if (x == 1 && keepGoing == true) {
            bothSidesStreak.add(streak.size());
            streak.clear();
            keepGoing = false;
          }
          else if (keepGoing == true){
            streak.add(w.charAt(x));
          }
        }
      }
      streak.clear();
      keepGoing = true;
      for (int y = i + 1; y < w.length(); y ++) {
        // if that character is a r, clear the streak but add it to the big streak
        if (w.charAt(y) == 'r' && keepGoing == true) {
          bothSidesStreak.add(streak.size());
          streak.clear();
          keepGoing = false;
          if (arrayListSum(bothSidesStreak) > longest) {
            longest = arrayListSum(bothSidesStreak);
          }
        }
        else {
          if (y == w.length() - 1 && keepGoing == true) {
            bothSidesStreak.add(streak.size());
            keepGoing = false;
            streak.clear();
            if (arrayListSum(bothSidesStreak) > longest) {
              longest = arrayListSum(bothSidesStreak);
            }
            bothSidesStreak.clear();
          }
          else if (keepGoing == true){
            streak.add(w.charAt(y));
        }
      }
    }

  }
    // now the same thing but for r b instead of b r
    for (int i = 0; i < w.length(); i ++) {
      bothSidesStreak.clear();
      keepGoing = true;
      streak.clear();
      for (int x = i; x > 0; x --) {
        // if that character is a r, clear the streak but add it to the big streak
        if (w.charAt(x) == 'r' && keepGoing == true) {
          bothSidesStreak.add(streak.size());
          streak.clear();
          keepGoing = false;
        }
        else {
          if (x == 1 && keepGoing == true) {
            bothSidesStreak.add(streak.size());
            keepGoing = false;
            streak.clear();
          }
          else if (keepGoing == true){
            streak.add(w.charAt(x));
          }
        }
      }
      keepGoing = true;
      streak.clear();
      for (int y = i + 1; y < w.length(); y ++) {
        // if that character is a b, clear the streak but add it to the big streak
        if (w.charAt(y) == 'b' && keepGoing == true) {
          bothSidesStreak.add(streak.size());
          streak.clear();
          keepGoing = false;
          if (arrayListSum(bothSidesStreak) > longest) {
            longest = arrayListSum(bothSidesStreak);
          }
        }
        else {
          if (y == w.length() - 1 && keepGoing == true) {
            bothSidesStreak.add(streak.size());
            if (arrayListSum(bothSidesStreak) > longest) {
              longest = arrayListSum(bothSidesStreak);
            }
            streak.clear();
            keepGoing = false;
            bothSidesStreak.clear();
          }
          else if (keepGoing == true){
            streak.add(w.charAt(y));
          }
      }
    }
  }
    if (longest > n) {
      pw.println(n);
    }
    else {
      pw.println(longest);
    }
    br.close();
}
  pw.close();

}
  public static int arrayListSum(ArrayList<Integer> summed) {
    int sum = 0;
    for (Integer i : summed) {
      sum += i;
    }
    return sum;
  }
}
