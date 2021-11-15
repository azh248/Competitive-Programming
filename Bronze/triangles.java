/*
ID: azh248
LANG: JAVA
TASK: triangles
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;
import java.awt.*;

public class triangles {

    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        public InputReader() throws FileNotFoundException {
            br = new BufferedReader(new FileReader("triangles.in"));
            st = null;
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) throws IOException {

        InputReader ir = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("triangles.out"));

        int n = ir.nextInt();

        ArrayList<Point> points = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            points.add(new Point(ir.nextInt(), ir.nextInt()));
        }

        int maxArea = 0;

        /* Program: run through all possible combinations and see if 2 of the x-values are the same and 2 of the y-values are the same, 
        then check if the area is above the maximum area */

        for (int i = 0; i < points.size(); i ++) {
            for (int j = 0; j < points.size(); j ++) {
                for (int k = 0; k < points.size(); k ++) {
                    if (i != j && j != k) {
                        if (points.get(i).getX() == points.get(j).getX() && points.get(i).getY() == points.get(k).getY()) {
                            if (Math.abs(points.get(i).getY() - points.get(j).getY()) * Math.abs(points.get(i).getX() - points.get(k).getX()) > maxArea) {
                                maxArea = (int) (Math.abs(points.get(i).getY() - points.get(j).getY()) * Math.abs(points.get(i).getX() - points.get(k).getX()));
                            }
                        }
                    }
                }
            }
        }

        pw.println(maxArea);

        pw.close();
    }

}
