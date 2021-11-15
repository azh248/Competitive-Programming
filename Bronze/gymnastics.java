import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

class gymnastics {

  public static void main(String[] args) throws IOException {

    // creates scanner and outputter, scans input - verified to store practice session placements in practiceSessions
    Scanner fileReader = new Scanner(new File("gymnastics.in"));
    BufferedWriter bw = new BufferedWriter(new FileWriter("gymnastics.out"));
    int numberOfLines = fileReader.nextInt();
    int numberOfCows = fileReader.nextInt();
    ArrayList<ArrayList<Integer>> practiceSessions = new ArrayList<ArrayList<Integer>>();
    int consistentPairs = 0;

    for (int a = 0; a < numberOfLines; a++) {
      ArrayList<Integer> tempArrayList = new ArrayList<Integer>();
      for (int b = 0; b < numberOfCows; b++) {
        int num1 = fileReader.nextInt();
        tempArrayList.add(num1);
      }
      practiceSessions.add(tempArrayList);
    }

    // goes through each pair of cows and sees if they're consistent in every practice session
    for (int i = 1; i < numberOfCows + 1; i++) {
      for (int m = 1; m < numberOfCows + 1; m++) {
        Integer aWins = 0;
        Integer bWins = 0;
        for (ArrayList<Integer> practiceSession : practiceSessions) {
          Collections.sort(practiceSession);
          if (Collections.binarySearch(practiceSession, i) > Collections.binarySearch(practiceSession, m)) {
            aWins += 1;
          }
          if (Collections.binarySearch(practiceSession, i) < Collections.binarySearch(practiceSession, m)) {
            bWins += 1;
          }
        }
        if (aWins == numberOfLines || bWins == numberOfLines) {
          consistentPairs += 1;
        }
      }
      }
    bw.write(Integer.toString(consistentPairs));
    bw.close();
    fileReader.close();
  }
}
