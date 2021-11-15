/*
ID: azh248
LANG: JAVA
TASK: square
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class square {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("square.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("square.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        /* reads input, stores in integer pairs */

        int[][] coordinates = new int[4][2];

        coordinates[0][0] = Integer.parseInt(st.nextToken());
        coordinates[0][1] = Integer.parseInt(st.nextToken());

        coordinates[1][0] = Integer.parseInt(st.nextToken());
        coordinates[1][1] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        coordinates[2][0] = Integer.parseInt(st.nextToken());
        coordinates[2][1] = Integer.parseInt(st.nextToken());

        coordinates[3][0] = Integer.parseInt(st.nextToken());
        coordinates[3][1] = Integer.parseInt(st.nextToken());
        
        

        /* finds the smallest x, largest x, smallest y, largest y, finds the larger distance between
        smallest x and largest x vs between smallest y and largest y, squares that */

        int maxX = -1000000000;
        int minX = 1000000000;

        int maxY = -1000000000;
        int minY = 1000000000;

        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 2; j ++) {
                System.out.println(coordinates[i][j]);
                if (j == 0) {
                    System.out.println("0");
                    if (coordinates[i][j] > maxX) {
                        maxX = coordinates[i][j];
                    } if (coordinates[i][j] < minX) {
                        minX = coordinates[i][j];
                    }
                }
                else if (j == 1) {
                    System.out.println("1");
                    if (coordinates[i][j] > maxY) {
                        maxY = coordinates[i][j];
                    } if (coordinates[i][j] < minY) {
                        minY = coordinates[i][j];
                    }
                }
                System.out.println();
            }
        }

        System.out.println();
        System.out.println(maxY);
        System.out.println(minY);
        System.out.println(maxX);
        System.out.println(minX);

        if (maxY - minY >= maxX - minX) {
            pw.println((int)Math.pow((maxY - minY), 2));
        }
        else {
            pw.println((int)Math.pow((maxX - minX), 2));
        }

        pw.close();
        br.close();
    }

}
