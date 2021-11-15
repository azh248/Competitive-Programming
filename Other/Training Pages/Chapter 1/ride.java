/*
ID: azh248
LANG: JAVA
TASK: ride
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class ride {

  public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new FileReader("ride.in"));
    PrintWriter pw = new PrintWriter(new FileWriter("ride.out"));

    String comet = br.readLine();
    String group = br.readLine();

    char[] cometChar = comet.toCharArray();
    char[] groupChar = group.toCharArray();
    ArrayList<Integer> cometAscii = new ArrayList<>();
    ArrayList<Integer> groupAscii = new ArrayList<>();
    for (char x : cometChar) {
      int y = (int)x - 64;
      cometAscii.add((Integer)y);
    }
    for (char m : groupChar) {
      int n = (int)m - 64;
      groupAscii.add((Integer)n);
    }

    int productOfComet = 1;
    int productOfGroup = 1;

    for (Integer x : cometAscii) {
      productOfComet *= x;
    }
    for (Integer x : groupAscii) {
      productOfGroup *= x;
    }
    if (productOfComet%47 == productOfGroup%47) {
      pw.println("GO");
    }
    else {
      pw.println("STAY");
    }


    pw.close();
  }

}
