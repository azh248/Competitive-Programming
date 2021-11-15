/*
ID: azh248
LANG: JAVA
TASK: factory
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class factory {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("factory.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("factory.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        ArrayList<ArrayList<Integer>> connections = new ArrayList<>();

        /* create an arraylist of integer arraylists that describes what elements are connected to each element,
        then iterate through that arraylist and add to another arraylist */

        int n = Integer.parseInt(st.nextToken());

        int[][] graph = new int[n][n];

        for (int i = 0; i < n; i++) {
            ArrayList<Integer> connection = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                graph[i][j] = 0;
            }
            connections.add(connection);
        }

        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            graph[Integer.parseInt(st.nextToken()) - 1][Integer.parseInt(st.nextToken()) - 1] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1) {
                    ArrayList<Integer> connectionJ = connections.get(j);
                    ArrayList<Integer> connectionI = connections.get(i);
                    connectionJ.add(i);
                    for (Integer k : connectionI) {
                        connectionJ.add(k);
                    }
                    connections.set(j, connectionJ);
                }
            }
        }

        for (int l = 0; l < 20; l++) {
            for (ArrayList<Integer> i : connections) {
                for (int j = i.size() - 1; j >= 0; j--) {
                    for (Integer k : connections.get(i.get(j))) {
                        if (!i.contains(k)) {
                            i.add(k);
                        }
                    }
                }
            }
        }

        for (ArrayList<Integer> i : connections) {
            if (i.size() == n - 1) {
                pw.println(connections.indexOf(i) + 1);
                pw.close();
                br.close();
                return;
            }
        }
        pw.println(-1);

        /**
         * What to watch out for: == doesn't work for equality for reference types
         * setting one variable equal to another makes it so that variable changes when
         * the original one does, to get around this use "new" start using ? in an if
         * else statement, put the else directly after the closing bracket if using pw
         * before a return, make sure to close pw when printing a line, otherwise the
         * line won't print. you might have to use larger data types --> for silver and
         * above problems test cases are huge when needing to find the max in an array,
         * just use max = Math.max(max, nextInt) check if the loops are in the right
         * order (if each cow has 3 amounts of milk, going through the amounts of milk
         * first, then the cow would be incorrect) classnotfound --> clean the java
         * language server workspace try to break asap when tle, instead of using if
         * (!x) ___, use if (x) break; else ___
         */

        br.close();
        pw.close();
    }

}
