/*
ID: azh248
LANG: JAVA
TASK: mootube 
*/

import java.util.*;
import java.io.*;

public class mootube {

	static int cowsAccessed;
	static HashSet<Integer> dfsInfo = new HashSet<>();
	static ArrayList<ArrayList<Integer>> adjLists;
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("mootube.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("mootube.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        adjLists = new ArrayList<>();


        /* Program: */

        for (int i = 0; i < n; i++) {
			ArrayList<Integer> arr = new ArrayList<>();
			adjLists.add(arr);
		}
        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			int c = Integer.parseInt(st.nextToken());

			adjLists.get(a).add(b);
			adjLists.get(a).add(c);
			adjLists.get(b).add(a);
			adjLists.get(b).add(c);
		}
		System.out.println(adjLists);
		for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken()) - 1;
			cowsAccessed = 0;
			dfsInfo.clear();
			dfs(v, k);
			pw.println(cowsAccessed - 1);
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
	public static void dfs(int node, int k) {
        // uses dfs and iterates through each node's adjacency list that it passes into
        // checks if node has already been visited
        if (dfsInfo.contains(node)) {
            return;
		}
		cowsAccessed++;
        // otherwise it adds the node to the set of traversed nodes and sets that node as the new root
        dfsInfo.add(node);
        for (int i = 0; i < adjLists.get(node).size(); i += 2) {
            if (adjLists.get(node).get(i+1) >= k) {
				dfs(adjLists.get(node).get(i), k); // WARNING: MIGHT GET STACK OVERFLOW ERROR
			}
        }
    }
}
