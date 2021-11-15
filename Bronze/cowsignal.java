/*
ID: azh248
LANG: JAVA
TASK: cowsignal
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class cowsignal {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("cowsignal.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("cowsignal.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            String patternLine = st.nextToken();
            String line = "";
            for (int j = 0; j < N; j++) {
                for (int x = 0; x < K; x++) {
                    line += patternLine.charAt(j);
                }
            }
            for (int y = 0; y < K; y++) {
                pw.println(line);
            }
        }

        /*
         * for each line, for each character in each line, add that character to a
         * temporary line String k times, and print the line K times
         */

        pw.close();
        br.close();
    }

}
