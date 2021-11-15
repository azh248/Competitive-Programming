import java.util.*;
import java.io.*;

public class climbingtrees {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        /* Program: */

        st = new StringTokenizer(br.readLine());

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
           arr[i] = Integer.parseInt(st.nextToken()); 
        }
        Arrays.sort(arr);
        long maxHeights = 0;
        long heights = 0;
        for (int i = 0; i < n - 1; i++) {
            heights += arr[i];
            if (arr[i+1] - arr[i] > k) {
                maxHeights = Math.max(maxHeights, heights);
                heights = 0;
            }
        }
        if (arr[n - 1] - arr[n - 2] <= k) {
            heights += arr[n - 1];
        }
        maxHeights = Math.max(maxHeights, heights);
        pw.println(maxHeights);

        pw.close();
    }

}
