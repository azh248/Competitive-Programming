import java.util.*;
import java.io.*;

public class suffixOperations {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());

		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());

			long[] arr = new long[n];
			long[] prefixSums = new long[n];
			st = new StringTokenizer(br.readLine());
			arr[0] = Long.parseLong(st.nextToken());
			for (int j = 1; j < n; j++) {
				arr[j] = Long.parseLong(st.nextToken());
				prefixSums[j] = arr[j] - arr[j - 1];
			}
			long maxFrom0 = -1;
			long totalSum = 0;
			for (int j = 1; j < n - 1; j++) {
				long next = Math.abs(prefixSums[j + 1]);
				long prev = Math.abs(prefixSums[j]);
				if ((next + prev) - (Math.abs(arr[j + 1] - arr[j - 1])) > maxFrom0) { // math.abs the left hand of inequality?
					maxFrom0 = (next + prev) - (Math.abs(arr[j + 1] - arr[j - 1]));
				}
			}
			if (Math.abs(prefixSums[n - 1]) > maxFrom0) {
				maxFrom0 = Math.abs(prefixSums[n - 1]); 
			} if (Math.abs(prefixSums[1]) > maxFrom0) {
				maxFrom0 = Math.abs(prefixSums[1]);
			}
			for (int j = 1; j < n; j++) {
				totalSum += Math.abs(prefixSums[j]);
			}
			totalSum -= maxFrom0;
			pw.println(totalSum);
		}

		pw.close();
		br.close();
	}
}
