/*
ID: azh248
LANG: JAVA
TASK: where
*/

import java.util.*;
import java.io.*;

public class where {

    static char[][] grid;
    static char[][] localGrid;
    static boolean[][] visited;
    static int n1, m1, switches;
    static ArrayList<int[]> colors = new ArrayList<>();

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("where.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("where.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        /* Program: find all subrectangles of the nxn square, and for each one check if it's a PCL*/

        ArrayList<int[]> subRectangles = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n - i + 1; j++) {
                int[] add = new int[2];
                add[0] = j;
                add[1] = j + i - 1;
                subRectangles.add(add);
            }
        }

        ArrayList<int[][]> workingPairs = new ArrayList<int[][]>();

        grid = new char[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String line = st.nextToken();
            for (int j = 0; j < n; j++) {
                grid[i][j] = line.charAt(j);
            }
        }
        int PCL = 0;

        for (int[] i : subRectangles) {
            for (int[] j : subRectangles) {
                n1 = i[1] - i[0] + 1;
                m1 = j[1] - j[0] + 1;
                switches = 0;
                colors.clear();
                visited = new boolean[n1][m1];
                localGrid = new char[n1][m1];
                for (int a = i[0]; a <= i[1]; a++) {
                    for (int b = j[0]; b <= j[1]; b++) {
                        localGrid[a - i[0]][b - j[0]] = grid[a][b];
                    }
                }
                for (int a = 0; a < i[1] - i[0] + 1; a++) {
                    for (int b = 0; b < j[1] - j[0] + 1; b++) {
                        if (!visited[a][b]) {
                            boolean inColors = true;
                            for (int k = 0; k < colors.size(); k++) {
                                if (k == colors.size() - 1 && (char)(colors.get(k)[0]) != localGrid[a][b]) {
                                    int[] add = {localGrid[a][b], (char) 1};
                                    colors.add(add);
                                    inColors = false;
                                    break;
                                } else if ((char)(colors.get(k)[0]) == localGrid[a][b]) {
                                    break;
                                }
                            }
                            if (colors.size() == 0) {
                                int[] add = { localGrid[a][b], (char) 1 };
                                colors.add(add);
                                inColors = false;
                            }
                            if (inColors) {
                                for (int k = 0; k < colors.size(); k++) {
                                    if ((char)(colors.get(k)[0]) == localGrid[a][b]) {
                                        colors.get(k)[1] = colors.get(k)[1] + 1;
                                        break;
                                    }
                                }
                            }
                            ff(a, b, localGrid[a][b]);
                        }
                    }
                }
                if (colors.size() == 2 && ((colors.get(0)[1] >= 2 && colors.get(1)[1] == 1) || (colors.get(0)[1] == 1 && colors.get(1)[1] >= 2))) {
                    boolean works = true;
                    for (int k = workingPairs.size() - 1; k >= 0; k--) {
                        int[][] workingPair = workingPairs.get(k);
                        if (workingPair[0][0] <= i[0] && workingPair[0][1] >= i[1] && workingPair[1][0] <= j[0] && workingPair[1][1] >= j[1]) {
                            works = false;
                            break;
                        } else if (workingPair[0][0] >= i[0] && workingPair[0][1] <= i[1] && workingPair[1][0] >= j[0] && workingPair[1][1] <= j[1]) {
                            workingPairs.remove(k);
                            PCL--;
                        }
                    }
                    if (works) {
                        PCL++;
                        int[][] add = { i, j };
                        workingPairs.add(add);
                    }
                }
            }
        }
        pw.println(PCL);

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
    
    public static void ff(int y, int x, char color) {
        if (y < 0 || y >= n1 || x < 0 || x >= m1)
            return; // if outside grid
        if (localGrid[y][x] != color) {
            return;
        }
        if (visited[y][x])
            return; // already visited this square
        visited[y][x] = true; // mark current square as visited
        // recursively call floodfill for neighboring squares
        ff(y, x + 1, color);
        ff(y, x - 1, color);
        ff(y - 1, x, color);
        ff(y + 1, x, color);
    }
}
