import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class removeSmallest {

  public static void main(String[] args) throws IOException {

    Scanner br = new Scanner(System.in);
    PrintWriter pw = new PrintWriter(System.out);
    ArrayList<ArrayList<Integer>> testCases = new ArrayList<>();

    int t = br.nextInt();
    for (int i = 0; i < t; i ++) {
      int n = br.nextInt();
      ArrayList<Integer> testCaseTemporary = new ArrayList<>();
      for (int x = 0; x < n; x ++) {
        int w = br.nextInt();
        testCaseTemporary.add(w);
      }
      testCases.add(testCaseTemporary);
    }
    for (ArrayList<Integer> testCase : testCases) {
      int a = 0;
      for (int i = 0; i < testCase.size(); i ++) {
        int z = testCase.get(new Integer(i));
        if (i + 1 != testCase.size()) {
          int y = testCase.get(i+1);
          if (Math.abs(y - z) <= 1) {
            continue;
          }
          else {
            a += 1;
          }
        }
        else {
          continue;
        }
      }
      if (a >= 1) {
        pw.println("NO");
      }
      else {
        pw.println("YES");
      }
    }
    pw.close();
    br.close();
  }

}
