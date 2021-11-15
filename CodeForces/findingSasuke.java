import java.util.*;
import java.io.*;

public class findingSasuke {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(st.nextToken());

        /* Program: */

        for (int i = 0; i < t; i++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int[] arr = new int[n];
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[j] = Integer.parseInt(st.nextToken());
            }
            for (int j = 0; j < n/2; j++) {
                int a = arr[j];
                int b = arr[n - j - 1];
                if (a < 0 && b < 0) {
                    a *= -1;
                    b *= -1;
                }
                int lcm = (a > b) ? a : b;
                while (true) {
                    if (lcm % a == 0 && lcm % b == 0) {
                        break;
                    }
                    lcm++;
                }
                arr[j] = -1 * (lcm/a);
                arr[n - j - 1] = lcm/b;
            }
            System.out.print(Integer.toString(arr[0]));
            for (int j = 1; j < n - 1; j++) {
                System.out.print(" " + Integer.toString(arr[j]));
            }
            System.out.print(" " + Integer.toString(arr[n - 1]) + "\n");
        }

        pw.close();
        br.close();
    }

}
