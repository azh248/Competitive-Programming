/*
ID: azh248
LANG: JAVA
TASK: wormsort
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class wormsort {

    static HashSet<Integer> dfsInfo = new HashSet<>();
    static HashSet<Integer> wrongPlaceCowsIterated = new HashSet<>();
    static HashSet<Integer> cowNetwork = new HashSet<>();

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("wormsort.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("wormsort.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        /*
         * Program: iterate down the maximum minimum wormhole widths starting from the
         * largest wormhole width, when we find one that allows dfs to all the vertices
         * that are not in the positions they need to be, we can stop and print that
         * maximum minimum wormhole width.
         */

        st = new StringTokenizer(br.readLine());

        int[] desiredArr = new int[n];
        ArrayList<ArrayList<Integer>> cowNetworks = new ArrayList<>(); // the networks of cows that have to be connected
                                                                       // to each other

        // contains adjacency lists of int arrays with index 0 being the other element,
        // index 1 being wormhole width
        ArrayList<ArrayList<int[]>> adjacencyLists = new ArrayList<ArrayList<int[]>>();
        boolean allSame = true;

        for (int i = 0; i < n; i++) {
            desiredArr[i] = Integer.parseInt(st.nextToken()) - 1;
            ArrayList<int[]> x = new ArrayList<>();
            adjacencyLists.add(x);
            if (desiredArr[i] != i) {
                allSame = false;
            }
        }
        if (allSame) {
            pw.println(-1);
            pw.close();
            br.close();
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!wrongPlaceCowsIterated.contains(i)) {
                ArrayList<Integer> network = new ArrayList<>();
                if (desiredArr[i] != i) {
                    getNetworks(desiredArr, i, network);
                    cowNetworks.add(network);
                }
            }
        }

        ArrayList<Integer> wormholeWidths = new ArrayList<>();

        for (int j = 0; j < m; j++) {
            st = new StringTokenizer(br.readLine());
            int[] input = new int[3];
            int[] addA = new int[2];
            int[] addB = new int[2];
            input[0] = Integer.parseInt(st.nextToken()) - 1;
            input[1] = Integer.parseInt(st.nextToken()) - 1;
            input[2] = Integer.parseInt(st.nextToken());
            addA[0] = input[0];
            addA[1] = input[2];
            addB[0] = input[1];
            addB[1] = input[2];
            adjacencyLists.get(input[1]).add(addA);
            adjacencyLists.get(input[0]).add(addB);
            wormholeWidths.add(input[2]);
        }
        Collections.sort(wormholeWidths);
        // iterates through possible wormhole widths going down and stops when it finds
        // one
        int right = wormholeWidths.size() - 1;
        int left = 0;
        while (true) {
            int mid = (right + left) / 2;
            if (checkWormHoleWidths(adjacencyLists, n, wormholeWidths.get(mid), cowNetworks)) {
                if (mid == n - 1) {
                    pw.println(wormholeWidths.get(mid));
                    break;
                } else if (right - left <= 1) {
                    pw.println(wormholeWidths.get(mid));
                    break;
                } else {
                    left = mid;
                } 
            } else {
                right = mid;
            }
        }

        /** 
         * What to watch out for: == doesn't work for equality for reference types
         * setting one variable equal to another makes it so that variable changes when
         * the original one does, to get around this use "new" or .clone() with a cast,
         * if it's a list of lists you have to do a deep clone you might have to use
         * larger data types --> for silver and above problems test cases are
         * huge!!!!!!!!!!!!!! check if the loops are in the right order (if each cow has
         * n amounts of milk, going through the amounts of milk first, then the cows
         * would be incorrect) try to break asap when tle, instead of using if (!x) ___,
         * use if (x) break; else ___ try to avoid unnecessary nested loops use treeset
         * --> built in bsearch for floor and ceiling
         */

        br.close();
        pw.close();
    }

    public static void dfs(ArrayList<ArrayList<int[]>> adjacencyLists, ArrayList<int[]> nextNodeAdjacencyList,
            int node, int nodeWormholeWidth, int wormholeWidth) {
        // uses dfs and iterates through each node's adjacency list that it passes into
        // it adds the node to the set of traversed nodes and sets that node
        // as the new root
        if (dfsInfo.contains(node) || nodeWormholeWidth < wormholeWidth) {
            return;
        }
        dfsInfo.add(node);
        cowNetwork.add(node);
        for (int[] i : nextNodeAdjacencyList) {
            dfs(adjacencyLists, adjacencyLists.get(i[0]), i[0], i[1], wormholeWidth);
        }
    }

    public static void getNetworks(int[] desiredArr, int i, ArrayList<Integer> network) {
        if (!wrongPlaceCowsIterated.contains(i)) {
            wrongPlaceCowsIterated.add(i);
            network.add(i);
            if (desiredArr[i] != i) {
                getNetworks(desiredArr, desiredArr[i], network);
            }
        }
    }
    public static boolean checkWormHoleWidths(ArrayList<ArrayList<int[]>> adjacencyLists, int n, int i, ArrayList<ArrayList<Integer>> cowNetworks) {
        dfsInfo.clear();
        boolean works = true;
        // all cow networks that have been accessed
        ArrayList<HashSet<Integer>> cowNetworksAccessed = new ArrayList<>();
        // makes sure every node that needs to be connected is connected, but too slow
        for (int j = 0; j < n; j++) {
            if (!dfsInfo.contains(j)) {
                cowNetwork.clear();
                dfs(adjacencyLists, adjacencyLists.get(j), j, adjacencyLists.get(j).get(0)[1], i);
                cowNetworksAccessed.add((HashSet<Integer>) cowNetwork.clone());
            }
        }
        // looks at each cow network that we need and see if its one of the ones that we accessed with this wormhole size
        for (ArrayList<Integer> k : cowNetworks) {
            boolean shouldBreak = false;
            for (HashSet<Integer> j : cowNetworksAccessed) {
                boolean notContains = false;
                for (int l : k) {
                    if (!(j.contains(l))) {
                        notContains = true;
                        break;
                    }
                }
                if (!notContains) {
                    break;
                } else if (j.equals(cowNetworksAccessed.get(cowNetworksAccessed.size() - 1))) {
                    shouldBreak = true;
                    works = false;
                    break;
                }
            }
            if (shouldBreak) break;
        }
        return works;
    }
}
