/*
ID: azh248
LANG: JAVA
TASK: perimeter
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class perimeter {

    static int[][] grid;
    static boolean[][] visited;
    static int n1, m1, currentSize, currentPerimeter;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("perimeter.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("perimeter.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        /* Program: */
        grid = new int[n][n];
        visited = new boolean[n][n];
        n1 = n;
        m1 = n;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            for (int j = 0; j < n; j++) {
                char ch = str.charAt(j);
                if (ch == '#') {
                    grid[i][j] = 1;
                } else {
                    grid[i][j] = 0;
                }
            }
        }
        int maxNetwork = 0;
        int maxNetworkMinimumPerimeter = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    currentSize = 0;
                    currentPerimeter = 4;
                    ff(i, j, 1);
                    if (currentSize > maxNetwork) {
                        maxNetwork = currentSize;
                        maxNetworkMinimumPerimeter = currentPerimeter;
                    } else if (currentSize == maxNetwork) {
                        if (currentPerimeter < maxNetworkMinimumPerimeter) {
                            maxNetworkMinimumPerimeter = currentPerimeter;
                        }
                    }
                 }
            }
        }
        pw.println(Integer.toString(maxNetwork) + " " + Integer.toString(maxNetworkMinimumPerimeter));


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
         * --> built in bsearch for floor and ceiling use linkedlist --> O(1) insertion
         * and deletion but O(n) accessing
         */

        br.close();
        pw.close();
    }
    public static void ff(int y, int x, int color) {
        if (y < 0 || y >= n1 || x < 0 || x >= m1)
            return; // if outside grid
        if (grid[y][x] != color)
            return; // wrong color
        if (visited[y][x])
            return; // already visited this square
        visited[y][x] = true; // mark current square as visited
        currentSize++; // increment the size for each square we visit
        if (y == 0 && x == 0) {
            if (visited[1][0]) {
                if (visited[0][1]) {
                } else {
                    currentPerimeter += 2;
                }
            } else if (visited[0][1]) {
                currentPerimeter += 2;
            }
        } else if (y == 0 && x == n1 - 1) {
            if (visited[1][n1 - 1]) {
                if (visited[0][n1 - 2]) {
                } else {
                    currentPerimeter += 2;
                }
            } else if (visited[0][n1 - 2]) {
                currentPerimeter += 2;
            }
        } else if (y == m1 - 1 && x == 0) {
            if (visited[m1 - 1][1]) {
                if (visited[m1 - 2][0]) {
                } else {
                    currentPerimeter += 2;
                }
            } else if (visited[m1 - 2][0]){
                currentPerimeter += 2;
            }
        } else if (y == m1 - 1 && x == n1 - 1) {
            if (visited[m1 - 2][n1 - 1]) {
                if (visited[m1 - 1][n1 - 2]) {
                } else {
                    currentPerimeter += 2;
                }
            } else if (visited[m1 - 1][n1 - 2]) {
                currentPerimeter += 2;
            }
        } else if (y == 0) {
            int neighbors = 0;
            if (visited[0][x + 1]) {
                neighbors++;
            } if (visited[0][x - 1]) {
                neighbors++;
            } if (visited[1][x]) {
                neighbors++;
            } if (neighbors == 3) {
                currentPerimeter -= 2;
            } else if (neighbors == 2) {

            } else if (neighbors == 1) {
                currentPerimeter += 2;
            }
        } else if (y == m1 - 1) {
            int neighbors = 0;
            if (visited[m1 - 1][x + 1]) {
                neighbors++;
            } if (visited[m1 - 1][x - 1]) {
                neighbors++;
            } if (visited[m1 - 2][x]) {
                neighbors++;
            } if (neighbors == 3) {
                currentPerimeter -= 2;
            } else if (neighbors == 2) {

            } else if (neighbors == 1) {
                currentPerimeter += 2;
            }
        } else if (x == 0) {
            int neighbors = 0;
            if (visited[y + 1][0]) {
                neighbors++;
            } if (visited[y - 1][0]) {
                neighbors++;
            } if (visited[y][1]) {
                neighbors++;
            } if (neighbors == 3) {
                currentPerimeter -= 2;
            } else if (neighbors == 2) {

            } else if (neighbors == 1) {
                currentPerimeter += 2;
            }
        } else if (x == n1 - 1) {
            int neighbors = 0;
            if (visited[y + 1][n1 - 1]) {
                neighbors++;
            } if (visited[y - 1][n1 - 1]) {
                neighbors++;
            } if (visited[y][n1 - 2]) {
                neighbors++;
            } if (neighbors == 3) {
                currentPerimeter -= 2;
            } else if (neighbors == 2) {

            } else if (neighbors == 1) {
                currentPerimeter += 2;
            }
        } else {
            int neighbors = 0;
            if (visited[y - 1][x]) {
                neighbors++;
            } if (visited[y + 1][x]) {
                neighbors++;
            } if (visited[y][x - 1]) {
                neighbors++;
            } if (visited[y][x + 1]) {
                neighbors++;
            } if (neighbors == 4) {
                currentPerimeter -= 4;
            } else if (neighbors == 3) {
                currentPerimeter -= 2;
            } else if (neighbors == 2) {

            } else if (neighbors == 1) {
                currentPerimeter += 2;
            }
        }
        // recursively call floodfill for neighboring squares
        ff(y, x + 1, color);
        ff(y, x - 1, color);
        ff(y - 1, x, color);
        ff(y + 1, x, color);
    }
}
