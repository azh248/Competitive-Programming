import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class childAndHomework {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        String a, b, c, d;

        a = br.readLine();
        b = br.readLine();
        c = br.readLine();
        d = br.readLine();

        String[] arr = {a, b, c, d};

        int[] lengths = {a.length() - 2, b.length() - 2, c.length() - 2, d.length() - 2};
        Arrays.sort(lengths);

        int great = 0;
        String maxGreat = "";
        String minGreat = "";
        
        if (lengths[0]*2 <= lengths[1]) {
            great++;
            for (String i : arr) {
                if (i.length() - 2 == lengths[0]) {
                    if (i.equals(a)) {
                        maxGreat = "A";
                    } else if (i.equals(b)) {
                        maxGreat = "B";
                    } else if (i.equals(c)) {
                        maxGreat = "C";
                    } else {
                        maxGreat = "D";
                    }
                }
            }
        } if (lengths[3] >= 2*lengths[2]) {
            great++;
            for (String i : arr) {
                if (i.length() - 2 == lengths[3]) {
                    if (i.equals(a)) {
                        minGreat = "A";
                    } else if (i.equals(b)) {
                        minGreat = "B";
                    } else if (i.equals(c)) {
                        minGreat = "C";
                    } else {
                        minGreat = "D";
                    }
                }
            }
        }

        if (great == 1) {
            if (!maxGreat.equals("")) {
                pw.println(maxGreat);
            } else {
                pw.println(minGreat);
            }
        } else {
            pw.println("C");
        }

        pw.close();
        br.close();
    }

}
