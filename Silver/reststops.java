/*
ID: azh248
LANG: JAVA
TASK: reststops
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class reststops {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("reststops.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("reststops.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        long length = Long.parseLong(st.nextToken());
        long n = Long.parseLong(st.nextToken());
        long johnSpeed = Long.parseLong(st.nextToken());
        long bessieSpeed = Long.parseLong(st.nextToken());

        ArrayList<Long> restStops = new ArrayList<>();

        for (int i = 0; i < length; i ++) {
            restStops.add((long)-1);
        }

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int index = Integer.parseInt(st.nextToken());
            restStops.set(index, Long.parseLong(st.nextToken()));
        }

        ArrayList<Integer> tastyPoints = new ArrayList<>();
        ArrayList<Integer> tastyValues = new ArrayList<>();
        long maxTastyValue = 0;
        for (long i = length - 1; i >= 0; i --) {
            if (restStops.get((int) i) > maxTastyValue) {
                maxTastyValue = restStops.get((int) i);
                tastyPoints.add((int)i);
                tastyValues.add((int)maxTastyValue);
            }
        }
        Collections.reverse(tastyPoints);
        Collections.reverse(tastyValues);
        int tastyIndex = 0;
        
        /*
         always go to the maximum tasty unit rest stop, as there is no extra time
         needed to switch stops when farmer john catches up, go to the next maximum
         tasty unit rest stop, and repeat
         */

        long tastingSeconds = 0;
        long currentPosition = 0;
        long totalTasty = 0;

        while (tastyIndex != tastyPoints.size()) {
            tastingSeconds = (tastyPoints.get(tastyIndex) - currentPosition)*(johnSpeed - bessieSpeed);
            currentPosition = tastyPoints.get(tastyIndex);
            totalTasty += (long)tastyValues.get(tastyIndex)*tastingSeconds;
            tastyIndex++;
        }

        pw.println(totalTasty);

    
        /**
         * What to watch out for: == doesn't work for equality for reference types
         * setting one variable equal to another makes it so that variable changes when
         * the original one does, to get around this use "new" start using ? in an if
         * else statement, put the else directly after the closing bracket if using pw
         * before a return, make sure to close pw when printing a line, otherwise the
         * line won't print.
         */

        br.close();
        pw.close();
    }

}
