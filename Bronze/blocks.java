/*
ID: azh248
LANG: JAVA
TASK: blocks
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class blocks {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("blocks.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("blocks.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        ArrayList<String> words1 = new ArrayList<>();
        ArrayList<String> words2 = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            words1.add(st.nextToken());
            words2.add(st.nextToken());
        }

        /* for each pair of words, for each letter, see which word has more of that letter. 
        the one with more will have the number of that letter added onto an arraylist of letters. */

        ArrayList<Integer> maxLettersNeeded = new ArrayList<>();

        for (int i = 0; i < 26; i ++) {
            maxLettersNeeded.add(0);
            for (int j = 0; j < N; j ++) {
                int count1 = 0; 
                int count2 = 0;
                char ch = (char)(i + 65);
                for (int a = 0; a < words1.get(j).length(); a ++) {
                    if ((words1.get(j)).charAt(a) == Character.toLowerCase(ch)) {
                        count1 ++;
                    }
                }
                for (int b = 0; b < words2.get(j).length(); b ++) {
                    if ((words2.get(j)).charAt(b) == Character.toLowerCase(ch)) {
                        count2 ++;
                    }
                }
                if (count1 >= count2) {
                    maxLettersNeeded.set(i, maxLettersNeeded.get(i) + count1);
                }
                else {
                    maxLettersNeeded.set(i, maxLettersNeeded.get(i) + count2);
                }
            }
        }
        for (Integer i : maxLettersNeeded) {
            pw.println(i);
        }

        pw.close();
        br.close();
    }

}
