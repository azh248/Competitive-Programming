import java.util.*;
import java.io.*;

public class rugby {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(st.nextToken());

        /* Program: */

        for (int i = 0; i < t; i++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()); 
            int[][] arr = new int[n][2];
            for (int j = 0; j < n; j++) {
                st = new StringTokenizer(br.readLine());
                arr[j][0] = Integer.parseInt(st.nextToken());
                arr[j][1] = Integer.parseInt(st.nextToken());
            }
            sortByColumn(arr, 0);
            // left most person goes to left most spot, etc.
            int minTotalDistance = 10000000;
            for (int j = -510; j < 510; j++) {
                for (int k = -510; k < 510; k++) {
                    int distance = 0;
                    for (int l = 0; l < n; l++) {
                        distance += Math.abs(arr[l][0] - (j + l));
                        distance += Math.abs(arr[l][1] - k);
                    }
                    minTotalDistance = Math.min(minTotalDistance, distance);
                }
            }
            pw.println("Case #" + Integer.toString(i + 1) + ": " + Integer.toString(minTotalDistance));
        }

        pw.close();
        br.close();
    }
    public static void sortByColumn(int arr[][], int col) {
      Arrays.sort(arr, new Comparator<int[]>() {
        public int compare(final int[] entry1, final int[] entry2) {
          if (entry1[col] > entry2[col])
            return 1;
          else
            return -1;
          }
      }); 
    }
}
