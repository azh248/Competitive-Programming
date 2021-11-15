/*
ID: azh248
LANG: JAVA
TASK: transform
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class transform {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("transform.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("transform.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        /* 
        create a method to rotate, arraylist with 6 booleans for #1-6, use if statements to determine which transformation(s) were applied.
        go through transformations and see which one is the answer, print it
        */
        int N = Integer.parseInt(st.nextToken());
        char[][] originalPattern = new char[N][N];
        char[][] finalPattern = new char[N][N];
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            char[] array = line.toCharArray();
            for (int y = 0; y < N; y ++) {
                originalPattern[i][y] = array[y];
            }
        }
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            char[] array = line.toCharArray();
            for (int y = 0; y < N; y++) {
                finalPattern[i][y] = array[y];
            }
        }


        ArrayList<Boolean> transformationsApplied = new ArrayList<>();
        for (int i = 0; i < 7; i ++) {
            transformationsApplied.add(false);
        }
        if (arraysEquals(rotateArray(originalPattern), finalPattern)) {
            transformationsApplied.set(0, true);
        }
        if (arraysEquals(rotateArray2(originalPattern), finalPattern)) {
            transformationsApplied.set(1, true);
        }
        if (arraysEquals(rotateArray3(originalPattern), finalPattern)) {
            transformationsApplied.set(2, true);
        }
        if (arraysEquals(reflectArray(originalPattern), finalPattern)) {
            transformationsApplied.set(3, true);
        }
        if (arraysEquals(rotateArray(reflectArray(originalPattern)), finalPattern) || arraysEquals(rotateArray2(reflectArray(originalPattern)), finalPattern) || arraysEquals(rotateArray3(reflectArray(originalPattern)), finalPattern)) {
            transformationsApplied.set(4, true);
        }
        if (arraysEquals(originalPattern, finalPattern)) {
            transformationsApplied.set(5, true);
        }
        else {
            transformationsApplied.set(6, true);
        }

        for (int i = 1; i <= 7; i ++) {
            if (transformationsApplied.get(i - 1)) {
                pw.println(i);
                break;
            }
        }
        
        System.out.println(Arrays.deepToString(rotateArray2(originalPattern)));
        System.out.println(Arrays.deepToString(finalPattern));

        pw.close();
        br.close();
    }


    public static char[][] rotateArray(char[][] array) {
        int size = array.length;
        char[][] ret = new char[size][size];

        for (int i = 0; i < size; i ++)
            for (int j = 0; j < size; j ++)
                ret[i][j] = array[size - j - 1][i];
        
        return ret;
    }
    
    public static char[][] rotateArray2(char[][] array) {
        int size = array.length;
        char[][] ret = new char[size][size];

        for (int i = size - 1; i >= 0; i--)
            for (int j = size - 1; j >= 0; j--)
                ret[i][j] = array[size - i - 1][size - j - 1];

        return ret;
    }
    
    public static char[][] rotateArray3(char[][] array) {
        int size = array.length;
        char[][] ret = new char[size][size];

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                ret[i][j] = array[j][size - i - 1];

        return ret;
    }


    public static char[][] reflectArray(char[][] array) {
        int size = array.length;
        char[][] ret = new char[size][size];

        for (int i = 0; i < size; i ++) {
            for (int j = 0; j < size; j ++) {
                ret[i][j] = array[i][size - j - 1];
            }
        }
        return ret;
    }
    
    public static boolean arraysEquals(char[][] array1, char[][] array2) {
        int size = array1.length;
        boolean isEqual = true;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (array1[i][j] != array2[i][j]) {
                    isEqual = false;
                }
            }
        }
        return isEqual;
    }
}
