/*
ID: azh248
LANG: JAVA
TASK: moocast
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class moocast {

    static HashSet<Integer> dfsInfo = new HashSet<>();
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("moocast.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("moocast.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        // declare the list of adjacency lists and the stack
        LinkedList<LinkedList<Integer>> adjacencyLists = new LinkedList<LinkedList<Integer>>();
        int[][] cows = new int[n][2];

        /* Program: */

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int[] cow = new int[3];
            cow[0] = Integer.parseInt(st.nextToken());
            cow[1] = Integer.parseInt(st.nextToken());
            cow[2] = Integer.parseInt(st.nextToken());
            cows[i] = cow;
            LinkedList<Integer> temp = new LinkedList<>();
            adjacencyLists.push(temp);
        }
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int cow1X = cows[i][0];
                int cow1Y = cows[i][1];
                int cow1Pow = cows[i][2];
                int cow2X = cows[j][0];
                int cow2Y = cows[j][1];
                int cow2Pow = cows[j][2];
                if (cow1Pow >= Math.sqrt(Math.pow(cow1X - cow2X, 2) + Math.pow(cow1Y - cow2Y, 2))) {
                    adjacencyLists.get(i).push(j);
                } if (cow2Pow >= Math.sqrt(Math.pow(cow1X - cow2X, 2) + Math.pow(cow1Y - cow2Y, 2))) {
                    adjacencyLists.get(j).push(i);
                }
            }
        }
        int max = 0;
        for (LinkedList<Integer> i : adjacencyLists) {
            dfsInfo.add(adjacencyLists.indexOf(i));
            LinkedList<LinkedList<Integer>> cloned = new LinkedList<LinkedList<Integer>>();
            for (LinkedList<Integer> j : adjacencyLists) {
                cloned.add((LinkedList<Integer>) j.clone());
            }
            dfs(cloned, (LinkedList<Integer>) i.clone());
            max = Math.max(max, dfsInfo.size());
            dfsInfo.clear();
        }
        pw.println(max);

        /**
         * What to watch out for: == doesn't work for equality for reference types
         * setting one variable equal to another makes it so that variable changes when
         * the original one does, to get around this use "new" or .clone() with a cast
         * start using ? in an if else statement, put the else directly after the
         * closing bracket you might have to use larger data types --> for silver and
         * above problems test cases are huge check if the loops are in the right order
         * (if each cow has n amounts of milk, going through the amounts of milk first,
         * then the cow would be incorrect) try to break asap when tle, instead of using
         * if (!x) ___, use if (x) break; else ___ try to avoid unnecessary nested loops
         * use more methods
         */

        br.close();
        pw.close();
    }
    public static void dfs(LinkedList<LinkedList<Integer>> adjacencyLists, LinkedList<Integer> nextNodeAdjacencyList) {
        while (!nextNodeAdjacencyList.isEmpty()) {
            int nextNode = nextNodeAdjacencyList.poll();
            if (dfsInfo.contains(nextNode)) {
                continue;
            } else {
                dfsInfo.add(nextNode);
                dfs(adjacencyLists, adjacencyLists.get(nextNode));
            }
        }
    }
}
