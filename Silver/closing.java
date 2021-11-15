/*
ID: azh248
LANG: JAVA
TASK: closing
*/

import java.util.*;
import java.io.*;

public class closing {

    static HashSet<Integer> closedFarms = new HashSet<>();
    static HashSet<Integer> dfsInfo = new HashSet<>();
    static ArrayList<Integer> visitFarms = new ArrayList<>();
    static ArrayList<ArrayList<Integer>> adjacencyLists = new ArrayList<>();
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("closing.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("closing.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());


        /* Program: whenever you close a farm, add that farm to a hashset of closed farms and remove it 
        from the arraylist of the farms that we need to visit. Then, we dfs and at each point check if
        the farm that we're visiting is in the hashset. after that we just check if we visited all farms that we need to visit. */

        for (int i = 0; i < n; i++) {
            ArrayList<Integer> add = new ArrayList<>();
            adjacencyLists.add(add);
            visitFarms.add(i);
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int firstBarn = Integer.parseInt(st.nextToken()) - 1;
            int secondBarn = Integer.parseInt(st.nextToken()) - 1;
            adjacencyLists.get(firstBarn).add(secondBarn);
            adjacencyLists.get(secondBarn).add(firstBarn);
        }
        if (visitFarms.size() > 0)
            dfs(visitFarms.get(0));
        boolean worked = true;
        for (int j : visitFarms) {
            if (!dfsInfo.contains(j)) {
                worked = false;
                pw.println("NO");
                break;
            }
        }
        if (worked)
            pw.println("YES");
        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int closedFarm = Integer.parseInt(st.nextToken()) - 1;
            visitFarms.remove((Integer) closedFarm);
            closedFarms.add(closedFarm);
            dfsInfo.clear();
            if (visitFarms.size() > 0) dfs(visitFarms.get(0));
            worked = true;
            for (int j : visitFarms) { 
                if (!dfsInfo.contains(j)) {
                    worked = false;
                    pw.println("NO");
                    break;
                }
            }
            if (worked) pw.println("YES");
        }


        /**
         * setting one variable equal to another makes it so that variable changes when
         * the original one does, to get around this use "new" or .clone() with a cast,
         * if it's a list of lists you have to do a deep clone you might have to use
         * larger data types --> for silver and above problems test cases are
         * huge!!!!!!!!!!!!!! check if the loops are in the right order (if each cow has
         * n amounts of milk, going through the amounts of milk first, then the cows
         * would be incorrect) try to break asap when tle, instead of using if (!x) ___,
         * use if (x) break; else ___ try to avoid unnecessary nested loops use treeset
         * --> built in bsearch for floor and ceiling use linkedlist --> O(1) insertion
         * and deletion but O(n) accessing
         */

        br.close();
        pw.close();
    }
    public static void dfs(int node) {
        // uses dfs and iterates through each node's adjacency list that it passes into
        // checks if node has already been visited
        if (dfsInfo.contains(node) || closedFarms.contains(node)) {
            return;
        }
        // otherwise it adds the node to the set of traversed nodes and sets that node as the new root
        dfsInfo.add(node);
        for (int i : adjacencyLists.get(node)) {
            dfs(i); 
        }
    }
}
