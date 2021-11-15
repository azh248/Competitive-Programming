import java.util.*;
import java.io.*;

public class weights {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        /* Program: */

        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        long[] prefixSums = new long[n];
        prefixSums[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefixSums[i] = prefixSums[i - 1] + arr[i];
        }
        double maxDistance = 0;
        for (int i = 0; i < n - 1; i++) {
            double centerOfMass1 = (double)(prefixSums[i])/(double)(i + 1);
            double centerOfMass2 = (double)(prefixSums[n - 1] - prefixSums[i])/(double)(n - i - 1);
            maxDistance = Math.max(maxDistance, Math.abs(centerOfMass2 - centerOfMass1));
        }
        System.out.printf("%f\n", maxDistance);

        pw.close();
    }
}
