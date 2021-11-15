import java.util.*;
import java.io.*;

public class coinCombo1 { 

	static long[] results;
	static ArrayList<Integer> coins = new ArrayList<>();
	static HashSet<Integer> coinsContains = new HashSet<>();

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		int x = Integer.parseInt(st.nextToken());

		/* Program: */

		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < n; i++) {
			int coin = Integer.parseInt(st.nextToken());
			if (!coinsContains.contains(coin)) {
				coins.add(coin);
				coinsContains.add(coin);
			}
		}
		results = new long[x + 1];
		for (int i = 0; i < x; i++) {
			results[i] = -1l;
		}
		Collections.sort(coins);
		results[0] = 1;
		numWays(x);

		pw.println(results[x]);

		pw.close();
		br.close();
	}

	public static void numWays(int remainingValue) {
		if (remainingValue <= 0) {
			return;
		}
		long ways = 0l;
		for (int i : coins) {
			if (remainingValue - i < 0) {
				continue;
			}
			if (results[remainingValue - i] == -1) {
				numWays(remainingValue - i);
			}
			ways += results[remainingValue - i];
			ways %= Math.pow(10, 9) + 7;
		}
		results[remainingValue] = ways;
	}
}
