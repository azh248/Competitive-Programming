/*
ID: azh248
LANG: JAVA
TASK: fenceplan
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class fenceplan {

    static HashSet<Integer> dfsInfo = new HashSet<Integer>();
    static int maxX = 0;
    static int maxY = 0;
    static int minY = 0;
    static int minX = 0;
    static int[][] cows = new int[100000][2];

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("fenceplan.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("fenceplan.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        ArrayList<ArrayList<Integer>> adjacencyLists = new ArrayList<ArrayList<Integer>>();

        /*
         * Program: perform dfs, and for each network look at the perimeter and see if
         * it's smaller than the current min
         */

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            cows[i][0] = Integer.parseInt(st.nextToken());
            cows[i][1] = Integer.parseInt(st.nextToken());
            ArrayList<Integer> add = new ArrayList<Integer>();
            adjacencyLists.add(add);
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adjacencyLists.get(a - 1).add(b - 1);
            adjacencyLists.get(b - 1).add(a - 1);
        }
        int minPerimeter = 1000000000;
        for (int i = n - 1; i >= 0; i--) { // after going through one, just skip the others cuz we've already dfs'd them
            // see the perimeter of the surrounding fence for this adjacency list
            if (!dfsInfo.contains(i)) {
                maxX = 0;
                minX = 1000000000;
                maxY = 0;
                minY = 1000000000;
                dfs(adjacencyLists, (ArrayList<Integer>) adjacencyLists.get(i).clone(), i);
                minPerimeter = Math.min(minPerimeter, 2 * (maxX - minX) + 2 * (maxY - minY));
            }
        }
        pw.println(minPerimeter);

        /**
         * What to watch out for: == doesn't work for equality for reference types
         * setting one variable equal to another makes it so that variable changes when
         * the original one does, to get around this use "new" or .clone() with a cast,
         * if it's a list of lists you have to do a deep clone you might have to use
         * larger data types --> for silver and above problems test cases are huge check
         * if the loops are in the right order (if each cow has n amounts of milk, going
         * through the amounts of milk first, then the cows would be incorrect) try to
         * break asap when tle, instead of using if (!x) ___, use if (x) break; else ___
         * try to avoid unnecessary nested loops use more methods
         */

        br.close();
        pw.close();
    }

    public static void dfs(ArrayList<ArrayList<Integer>> adjacencyLists, ArrayList<Integer> nextNodeAdjacencyList, int node) {
        // uses dfs and iterates through each node's adjacency list that it passes into
        // checks if node has already been visited
        if (dfsInfo.contains(node)) {
            return;
        }
        // otherwise it adds the node to the set of traversed nodes and sets that node
        // as the new root
        dfsInfo.add(node);
        maxX = Math.max(maxX, cows[node][0]);
        minX = Math.min(minX, cows[node][0]);
        maxY = Math.max(maxY, cows[node][1]);
        minY = Math.min(minY, cows[node][1]);
        for (int i : nextNodeAdjacencyList) {
            dfs(adjacencyLists, adjacencyLists.get(i), i);
        }
    }
}
