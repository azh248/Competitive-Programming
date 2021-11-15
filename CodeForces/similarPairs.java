import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class similarPairs {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter pw = new PrintWriter(System.out);

        int n = sc.nextInt();

        // Greedy: 

        for (int i = 0; i < n; i ++) {
            int m = sc.nextInt();
            ArrayList<Integer> arr = new ArrayList<>();
            int odd = 0;
            int even = 0;
            for (int j = 0; j < m; j++) {
                arr.add(sc.nextInt());
                if (arr.get(j) % 2 == 0) {
                    even++;
                } else {
                    odd++;
                }
            }
            Collections.sort(arr);
            if (odd % 2 == 0 && even % 2 == 0) {
                pw.println("YES");
            } else {
                boolean keepGoing = true;
                while (arr.size() > 2) {
                    if (arr.get(1) - arr.get(0) == 1) {
                        pw.println("YES");
                        keepGoing = false;
                        break;
                    } else {
                        arr.remove(0);
                    }
                }
                if (keepGoing == true) {
                    if (arr.size() == 2) {
                        if (arr.get(1) - arr.get(0) == 1) {
                            pw.println("YES");
                        } else {
                            pw.println("NO");
                        }
                    }
                }
            }

        }

        pw.close();
        sc.close();
    }

}
