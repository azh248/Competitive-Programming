import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class islandPuzzle {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        ArrayList<Integer> islands = new ArrayList<>();
        ArrayList<Integer> desired = new ArrayList<>();

        int zeroIndex = 0;

        /* Program: */

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            islands.add(Integer.parseInt(st.nextToken()));
            if (islands.get(i) == 0) {
                zeroIndex = i;
            }
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            desired.add(Integer.parseInt(st.nextToken()));
        }
        int desired0 = desired.get(0);
        int desired1 = desired.get(1);
        for (int i = 0; i < n; i++) {
            if (zeroIndex > 0) {
                int add = islands.get(zeroIndex - 1);
                islands.remove(zeroIndex - 1);
                islands.add(zeroIndex, add);
                zeroIndex --;
                if (islands.get(0) == desired0 && islands.get(1) == desired1 && islands.equals(desired)) {
                    pw.println("YES");
                    break;
                } 
            } else {
                int add = islands.get(n - 1);
                islands.remove(n - 1);
                islands.remove(0);
                islands.add(0);
                islands.add(0, add);
                zeroIndex = n - 1;
                if (islands.get(0) == desired0 && islands.get(1) == desired1 && islands.equals(desired)) {
                    pw.println("YES");
                    break;
                }
            }
        }
        if (!islands.equals(desired)) {
            pw.println("NO");
        }

        pw.close();
        br.close();
    }

}
