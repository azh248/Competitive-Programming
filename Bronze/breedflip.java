/*
ID: azh248
LANG: JAVA
TASK: breedflip
*/

import java.sql.*;
import java.text.*;
import java.util.*;

import javax.swing.text.html.HTMLDocument.HTMLReader.CharacterAction;

import sun.tools.jar.resources.jar_ja;

import java.io.*;

public class breedflip {

    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        public InputReader() throws FileNotFoundException {
            br = new BufferedReader(new FileReader("breedflip.in"));
            st = null;
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) throws IOException {

        InputReader ir = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("breedflip.out"));

        int n = ir.nextInt();

        String stringA = "";
        String stringB = "";

        stringA = ir.next();
        stringB = ir.next();

        ArrayList<Character> stringToArrayListA = new ArrayList<>();
        ArrayList<Character> stringToArrayListB = new ArrayList<>();

        for (int i = 0; i < stringA.length(); i ++) {
            stringToArrayListA.add(stringA.charAt(i));
            stringToArrayListB.add(stringB.charAt(i));
        }

        ArrayList<Boolean> match = new ArrayList<>();

        /* Program: converts the H/G stuff to true/false, true if they match, false otherwise. 
        It then proceeds to find the most worth it part to flip, until all values are true. */

        for (int i = 0; i < stringToArrayListA.size(); i ++) {
            if (stringToArrayListA.get(i) == stringToArrayListB.get(i)) {
                match.add(true);
            }
            else {
                match.add(false);
            }
        }

        System.out.println(match);
        System.out.println();
        while (match.get(0)) {
            match.remove(0);
        }
        while (match.get(match.size() - 1)) {
            match.remove(match.size() - 1);
        }

        int totalMoves = 0;
        totalMoves ++;

        for (int i = 0; i < match.size(); i ++) {
            if (match.get(i) && !match.get(i - 1)) {
                totalMoves ++;
            }
        }

        
        System.out.println(match);
        pw.println(totalMoves);
        pw.close();
    }

}
