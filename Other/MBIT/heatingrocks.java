import java.util.*;
import java.io.*;

public class heatingrocks {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        /* Program: */

        long time = 0;
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        pw.println(timeUsed(arr, n, k));

        pw.close();
    }
    public static int timeUsed(int[] arr, int n, int k) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return Math.max(0, k - arr[0]);
        } else if (n == 2) {
            return Math.max(0, k - Math.min(arr[0], arr[1]));
        } else {
            return -1;
        }
    }
}
