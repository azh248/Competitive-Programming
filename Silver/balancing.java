/*
ID: azh248
LANG: JAVA
TASK: balancing
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class balancing {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("balancing.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("balancing.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        ArrayList<int[]> cowCoordinates = new ArrayList<>();

        /*
         * look at the middle part to get an estimate, and then go right a bit and left
         * a bit, looking at the spaces in between coordinates to determine where to
         * search for min and max. This will make the time compleixty low enough to
         * search the entirety of that area.
         */

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int[] coordinates = new int[2];
            coordinates[0] = Integer.parseInt(st.nextToken());
            coordinates[1] = Integer.parseInt(st.nextToken());
            cowCoordinates.add(coordinates);
        }
        ArrayList<Integer> cowCoordinatesX = new ArrayList<>();
        ArrayList<Integer> cowCoordinatesY = new ArrayList<>();

        for (int[] i : cowCoordinates) {
            cowCoordinatesX.add(i[0]);
        }
        for (int[] i : cowCoordinates) {
            cowCoordinatesY.add(i[1]);
        }
        Collections.sort(cowCoordinatesX);
        Collections.sort(cowCoordinatesY);

        int topLeft = 0;
        int topRight = 0;
        int bottomLeft = 0;
        int bottomRight = 0;
        int smallestMaximumCows = cowCoordinates.size();

        for (int y = cowCoordinatesX.size() / 4; y < cowCoordinatesX.size() * 3 / 4; y++) {
            for (int x = cowCoordinatesY.size() / 4; x < cowCoordinatesY.size() * 3 / 4; x++) {
                int yAxis = cowCoordinatesX.get(y) + 1;
                int xAxis = cowCoordinatesY.get(x) + 1;
                
                topLeft = 0;
                topRight = 0;
                bottomLeft = 0;
                bottomRight = 0;
                for (int[] i : cowCoordinates) {
                    if (i[0] > yAxis && i[1] > xAxis) {
                        topRight++;
                    } else if (i[0] > yAxis && i[1] < xAxis) {
                        topLeft++;
                    } else if (i[0] < yAxis && i[1] > xAxis) {
                        bottomRight++;
                    } else if (i[0] < yAxis && i[1] < xAxis) {
                        bottomLeft++;
                    }
                }
                smallestMaximumCows = Math.min(smallestMaximumCows, Math.max(Math.max(topLeft, topRight), Math.max(bottomLeft, bottomRight)));

            }
        }

        pw.println(smallestMaximumCows);

        /**
         * What to watch out for: == doesn't work for equality for reference types
         * setting one variable equal to another makes it so that variable changes when
         * the original one does, to get around this use "new" start using ? in an if
         * else statement, put the else directly after the closing bracket if using pw
         * before a return, make sure to close pw when printing a line, otherwise the
         * line won't print. you might have to use larger data types --> for silver and
         * above problems test cases are huge
         */

        br.close();
        pw.close();
    }
}
