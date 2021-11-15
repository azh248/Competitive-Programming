import java.util.*;
import java.io.*;

public class coinCombo2 {

	static int[][] results; 
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

		results = new int[n + 1][x + 1]; // results[i][j] is the # of ways we can make a sum of j using the first i coins

		for (int i = 0; i < n; i++) {
			int coin = Integer.parseInt(st.nextToken());
			if (!coinsContains.contains(coin)) {
				coins.add(coin);
				coinsContains.add(coin);
			}
		}
		Collections.sort(coins);
		if (coins.get(0) > x) {
			pw.println(0);
			pw.close();
			br.close();
			return;
		}
		for (int i = 0; i < n; i++) {
			int coin = coins.get(i);
			results[i + 1][coin]++;
			results[i + 1][0]++;
		}
		results[0][0]++;
		int sum = 0;
		for (int i = 1; i <= coins.size(); i++) {
			numWays(x, i);
		}
		sum += results[coins.size()][x];
		sum %= (Math.pow(10, 9) + 7);

		pw.println(sum);

		pw.close();
		br.close();
	}

	public static void numWays(int remainingValue, int maxCoin) {
		if (remainingValue <= 0 || maxCoin <= 0) {
			return;
		}
		if (results[maxCoin - 1][remainingValue] == 0) {
			numWays(remainingValue, maxCoin - 1);
		}
		results[maxCoin][remainingValue] += results[maxCoin - 1][remainingValue];
		int coin = coins.get(maxCoin - 1);
		if (remainingValue - coin <= 0) {
			return;
		}
		if (results[maxCoin][remainingValue - coin] == 0 || (coinsContains.contains(remainingValue - coin)) && results[maxCoin][remainingValue - coin] == 1) {
			numWays(remainingValue - coin, maxCoin);
		}
		results[maxCoin][remainingValue] += results[maxCoin][remainingValue - coin];
	}
}
