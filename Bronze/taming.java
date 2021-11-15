/*
ID: azh248
LANG: JAVA
TASK: taming
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class taming {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("taming.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("taming.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        ArrayList<Integer> logs = new ArrayList<>();
        ArrayList<Integer> breakouts = new ArrayList<>();

        /* basically goes through and for the ones with numbers, it goes back that amount 
        and sets the corresponding breakouts value to 1 (meaning a breakout has happened that day).
        all values between that day and the current one are then set to 0 (meaning false). everything in 
        breakouts has an initial value of 2 (unknown) */


        for (int i = 0; i < n; i++) {
            logs.add(Integer.parseInt(st.nextToken()));
            if (logs.get(i) > i) {
                pw.println(-1);
                pw.close();
                return;
            }
            breakouts.add(2); 
        }

        for (int i = 0; i < n; i ++) {
            if (logs.get(i) != -1) {
                int log = logs.get(i);
                breakouts.set(i - log, 1);
                for (int j = i - log + 1; j <= i; j ++) {
                    if (breakouts.get(j) == 1) {
                        pw.println(-1);
                        pw.close();
                        return;
                    }
                    breakouts.set(j, 0);
                }
            }
        }

        int min = 0;
        int max = 0;

        if (breakouts.get(0) == 0) {
            pw.println(-1);
            pw.close();
            return;
        }
        else if (breakouts.get(0) == 2) {
            breakouts.set(0, 1);
        }

        for (Integer i : breakouts) {
            if (i == 1) {
                min ++;
                max ++;
            } else if (i == 2) {
                max ++;
            }
        }
        pw.println(Integer.toString(min) + " " + Integer.toString(max));

        /*
         * What to watch out for: == doesn't work for equality for reference types
         * setting one variable equal to another makes it so that variable changes when
         * the original one does, to get around this use "new" start using ? in an if
         * else statement, put the else directly after the closing bracket
         * make sure each event is consistent --> whenever there hasn't been a breakout in the last n days, everything in those last n should be -1
         */

        pw.close();
    }

}
