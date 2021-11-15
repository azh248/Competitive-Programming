/*
ID: azh248
LANG: JAVA
TASK: milk2
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class milk2 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("milk2.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("milk2.out"));

        StringTokenizer st = new StringTokenizer(br.readLine()); 
        
        /* Program: create arraylist with booleans up to index 1,000,000, then all set to false,
        and if a farmer is milking at a time then the booleans that have index within that time are set to true --
        at the end, find the longest strings of falses and trues */
        
        ArrayList<Boolean> times = new ArrayList<>();

        int maxEnding = 0; // checking to see where to end; makes it so longest idle time isn't wrong
        int minStarting = 1000000; 
        int N = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int startingNum = Integer.parseInt(st.nextToken());
            int endingNum = Integer.parseInt(st.nextToken());
            if (endingNum > maxEnding) {
                maxEnding = endingNum;
            }
            if (startingNum < minStarting) {
                minStarting = startingNum;
            }
            while (times.size() < maxEnding) {
                times.add(false);
            }
            for (int n = startingNum; n < endingNum; n ++) {
                times.set(n, true);
            }
        }

        int longestMilking = 0;
        int longestIdle = 0;

        int streak = 0;
        boolean streakInProgress = false;
        
        for (int i = 0; i < times.size(); i ++) {
            if (times.get(i) == true && streakInProgress == false) {
                streak += 1;
                streakInProgress = true;
                if (longestMilking < 1) {
                    longestMilking = 1;
                }
            }
            else if (times.get(i) == true && streakInProgress == true) {
                streak += 1;
                if (streak > longestMilking) {
                    longestMilking = streak;
                }
            }
            else {
                streakInProgress = false;
                streak = 0;
            }
        }
        streak = 0;
        streakInProgress = false;

        for (int i = minStarting; i < times.size(); i++) {
            if (times.get(i) == false && streakInProgress == false) {
                streak += 1;
                streakInProgress = true;
                if (longestIdle < 1) {
                    longestIdle = 1;
                }
            } 
            else if (times.get(i) == false && streakInProgress == true) {
                streak += 1;
                if (streak > longestIdle) {
                    longestIdle = streak;
                }
            }
            else {
                streakInProgress = false;
                streak = 0;
            }
        }
        pw.println(longestMilking + " " + longestIdle);

        pw.close();
        br.close();
    }

}