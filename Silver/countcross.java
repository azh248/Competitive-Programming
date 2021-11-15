/*
ID: azh248
LANG: JAVA
TASK: countcross
*/

import java.util.*;
import java.io.*;

public class countcross {

    static int[][] grid;
    static boolean[][] visited, verticalRoads, horizontalRoads;
    static int n1, m1, currentSize;
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("countcross.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("countcross.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        n1 = n;
        m1 = n;
        visited = new boolean[n][n];
        grid = new int[n][n];
        verticalRoads = new boolean[n][n-1];
        horizontalRoads = new boolean[n-1][n];
        int k = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        /* Program: find each network of cows enclosed by roads (when recursively calling ff, check if theres a road between those 2 fields 
        using a boolean array of if theres a road between those 2 adjacenct fields), add that to an arraylist, gotta find out how
        to know the number of pairs given each network of enclosed cows. if there aren't any cows enclosed return 0 */

        for (int i = 0; i < r; i++) {
            st = new StringTokenizer(br.readLine());
            int r1 = Integer.parseInt(st.nextToken()) - 1;
            int c1 = Integer.parseInt(st.nextToken()) - 1;
            int r2 = Integer.parseInt(st.nextToken()) - 1;
            int c2 = Integer.parseInt(st.nextToken()) - 1;
            if (Math.abs(r1 - r2) == 1) {
                horizontalRoads[Math.min(r1, r2)][c1] = true;
            } else if (Math.abs(c1 - c2) == 1) {
                verticalRoads[r1][Math.min(c1, c2)] = true;
            }
        }
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int row = Integer.parseInt(st.nextToken()) - 1;
            int column = Integer.parseInt(st.nextToken()) - 1;
            grid[row][column] = 1;
        }
        ArrayList<Integer> enclosedNetworks = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    currentSize = 0;
                    ff(i, j, 1);
                    enclosedNetworks.add(currentSize);
                }
            }
        }
        int totalCombinations = 0;
        for (int i = 0; i < enclosedNetworks.size(); i++) {
            for (int j = i + 1; j < enclosedNetworks.size(); j++) {
                totalCombinations += enclosedNetworks.get(i) * enclosedNetworks.get(j);
            }
        }
        pw.println(totalCombinations);

        /**
         * What to watch out for: == doesn't work for equality for reference typeswait
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
    
    public static void ff(int y, int x, int color) {
        if (y < 0 || y >= n1 || x < 0 || x >= m1)
            return; // if outside grid
        if (visited[y][x])
            return; 
        if (grid[y][x] == color) {
            currentSize++;
        }
        visited[y][x] = true; // mark current square as visited
        // recursively call floodfill for neighboring squares
        if (!(x > m1 - 2) && !verticalRoads[y][x]) ff(y, x + 1, color);
        if (!(x - 1 < 0) && !verticalRoads[y][x-1]) ff(y, x - 1, color);
        if (!(y - 1 < 0) && !horizontalRoads[y - 1][x]) ff(y - 1, x, color);
        if (!(y > n1 - 2) && !horizontalRoads[y][x]) ff(y + 1, x, color);
    }
}
