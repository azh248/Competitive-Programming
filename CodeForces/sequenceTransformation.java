import java.util.*;
import java.io.*;

public class sequenceTransformation {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());

		/* Program: remove consecutive of the same number, have array of how many of each number there are, just subtractedges and the # of consecutive*/

		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int[] arr = new int[n];
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				arr[j] = Integer.parseInt(st.nextToken());
			}
			int[] consecutive = new int[n + 2];
			int[] howManyOfEach = new int[n + 2];
			for (int j = 0; j < n - 1; j++) {
				int num = arr[j];
				howManyOfEach[num]++;
				if (arr[j + 1] == num) consecutive[num]++;
			}
			howManyOfEach[arr[n - 1]]++;
			int min = 1000000000;

			for (int j = 0; j < n; j++) {
				int count = 0;
				count += howManyOfEach[arr[j]];
				if (arr[0] == arr[j]) count--;
				if (arr[n - 1] == arr[j]) count--;
				count -= consecutive[arr[j]];
				min = Math.min(count, min);
			}
			pw.println(min + 1);
		}

		pw.close();
		br.close();
	}
}
