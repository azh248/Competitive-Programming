/*
ID: azh248
LANG: JAVA
TASK: cownomics
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class cownomics {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("cownomics.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("cownomics.out"));

        ArrayList<String> spottyGenomes = new ArrayList<>();
        ArrayList<String> plainGenomes = new ArrayList<>();

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        /*
         * Go through all mC3 possible combinations of the positions, and for each one,
         * look at each cow. If none of the spotty cows share the same combination of 3
         * traits with any of the plain cows, this combination works.
         */


        for (int i = 0; i < n; i++) {
            String genomeString = br.readLine();
            spottyGenomes.add(genomeString);
        }

        for (int i = 0; i < n; i++) {
            String genomeString = br.readLine();
            plainGenomes.add(genomeString);
        }

        int totalCount = 0;
        int workingSets = 0;

        for (int i = 0; i < m; i ++) {
            for (int j = i + 1; j < m; j ++) {
                for (int k = j + 1; k < m; k ++) {
                    totalCount = 0;
                    HashSet<String> genomeCompare = new HashSet<>();
                    for (String spottyGenome : spottyGenomes) {
                        genomeCompare.add(Character.toString(spottyGenome.charAt(i)) + Character.toString(spottyGenome.charAt(j)) + Character.toString(spottyGenome.charAt(k)));
                    }
                    for (String plainGenome : plainGenomes) {
                        if (genomeCompare.contains(Character.toString(plainGenome.charAt(i)) + Character.toString(plainGenome.charAt(j)) + Character.toString(plainGenome.charAt(k)))) {
                            break;
                        } else {
                            totalCount ++;
                        }
                    }
                    if (totalCount == n) {
                        workingSets++;
                    }
                }
            }
        }

        pw.println(workingSets);



        /**
         * What to watch out for: == doesn't work for equality for reference types
         * setting one variable equal to another makes it so that variable changes when
         * the original one does, to get around this use "new" start using ? in an if
         * else statement, put the else directly after the closing bracket if using pw
         * before a return, make sure to close pw when printing a line, otherwise the
         * line won't print. you might have to use larger data types --> for silver and
         * above problems test cases are huge
         */

        br.close();
        pw.close();
    }

}
