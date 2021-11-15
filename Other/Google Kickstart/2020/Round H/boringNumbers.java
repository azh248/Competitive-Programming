import java.util.*;
import java.io.*;

public class boringNumbers {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        /* Program: */

        ArrayList<Integer> odd = new ArrayList<>();
        odd.add(1);
        odd.add(3);
        odd.add(5);
        odd.add(7);
        odd.add(9);

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            long L = Long.parseLong(st.nextToken());
            long R = Long.parseLong(st.nextToken());
            long boringNums = 0;
            int lLen = Long.toString(L).length();
            int rLen = Long.toString(R).length();
            if (rLen > lLen) {
                for (long j = L; j < Math.pow(10, lLen); j++) {
                    String s = Long.toString(j);
                    boolean boringNum = true;
                    for (int k = 0; k < s.length(); k++) {
                        if (odd.contains(Integer.parseInt(Character.toString(s.charAt(k))))) {
                            if (k % 2 == 1) boringNum = false;
                        } else {
                            if (k % 2 == 0) boringNum = false;
                        }
                    }
                    if (boringNum) boringNums++;
                }
                for (long j = (int)Math.pow(10, rLen - 1); j <= R; j++) {
                    String s = Long.toString(j);
                    boolean boringNum = true;
                    for (int k = 0; k < s.length(); k++) {
                        if (odd.contains(Integer.parseInt(Character.toString(s.charAt(k))))) {
                            if (k % 2 == 1)
                                boringNum = false;
                        } else {
                            if (k % 2 == 0)
                                boringNum = false;
                        }
                    }
                    if (boringNum) boringNums++; 
                }
            } else {
                for (long j = L; j <= R; j++) {
                    String s = Long.toString(j);
                    boolean boringNum = true;
                    for (int k = 0; k < s.length(); k++) {
                        if (odd.contains(Integer.parseInt(Character.toString(s.charAt(k))))) {
                            if (k % 2 == 1)
                                boringNum = false;
                        } else {
                            if (k % 2 == 0)
                                boringNum = false;
                        }
                    }
                    if (boringNum) boringNums++;
                } 
            }
            for (int j = lLen; j < rLen - 1; j++) {
                boringNums += Math.pow(5, j + 1);
            }
            pw.println("Case #" + Integer.toString(i + 1) + ": " + Long.toString(boringNums));
        }

        pw.close();
        br.close();
    }
}
