import java.util.*;
import java.io.*;

public class minimizingcoins {

	static int[] results;
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
		results = new int[x + 1];
		for (int i = 0; i < x; i++) {
			results[i] = -1;
		}
		Collections.sort(coins);
		results[0] = 0;
		minCoins(x);

		if (results[x] == 1000000000) {
			pw.println(-1);
		} else {
			pw.println(results[x]);
		}

		pw.close();
		br.close();
	}
	public static void minCoins(int remainingValue) {
		if (remainingValue == 0) {
			return;
		}
		int minNumCoins = 1000000000;
		for (int i : coins) {
			if (remainingValue - i < 0) {
				continue;
			}
			if (results[remainingValue - i] == -1) {
				minCoins(remainingValue - i);
			}
			if (results[remainingValue - i] < minNumCoins) {
				minNumCoins = results[remainingValue - i];
			}
		}
		if (minNumCoins != 1000000000) results[remainingValue] = minNumCoins + 1;
		else results[remainingValue] = minNumCoins;
	}
}
