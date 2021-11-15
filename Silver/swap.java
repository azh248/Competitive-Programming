/*
ID: azh248
LANG: JAVA
TASK: swap
*/

import java.util.*;
import java.io.*;

public class swap {

	static int[][] processResults;
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("swap.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("swap.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		/* Program: we find the results of 1 process, then use that to find the results of 2, then 4, then 8, etc. until log base 2 of k. Then,
		we find the binary representation of k and just take the result of each process we need (for example, if k = 7 we'd perform the 1 process 
		on the result of the 2 process on the result of the 4 process) */

		processResults = new int[(int)(Math.log(k)/Math.log(2)) + 2][n + 1];

		int[] firstProcess = new int[n + 1];

		for (int i = 1; i <= n; i++) {
			firstProcess[i] = i;
		}

		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int l = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			for (int j = l; j <= (int) (r + l - 1)/2; j++) {
				int leftNum = firstProcess[j];
				int rightNum = firstProcess[r - j + l];
				firstProcess[j] = rightNum;
				firstProcess[r - j + l] = leftNum;
			}
		}
		processResults[0] = firstProcess;
		createProcessResults((int)(Math.log(k)/Math.log(2)) + 1);

		ArrayList<Integer> power2Composition = powersOf2Sum(k);
		int[] arr = processResults[power2Composition.get(0)];
		for (int i = 1; i < power2Composition.size(); i++) {
			int[] newArr = processResults[power2Composition.get(i)];
			int[] retArr = new int[n + 1];
			for (int j = 1; j < arr.length; j++) {
				retArr[j] = newArr[arr[j]];
			}
			arr = retArr;
		}
		for (int i = 1; i < arr.length; i++) {
			pw.println(arr[i]);
		}

		br.close();
		pw.close();
	}
	public static void createProcessResults(int power2) {
		if (power2 == 0) {
			return;
		}
		if (processResults[power2 - 1][1] == 0) {
			createProcessResults(power2 - 1);
		}
		int[] arr = processResults[power2 - 1];
		int[] newArr = new int[processResults[1].length];
		for (int i = 1; i < processResults[1].length; i++) {
			newArr[i] = arr[arr[i]];
		}
		processResults[power2] = newArr;
	}
	public static ArrayList<Integer> powersOf2Sum(int k) {
		ArrayList<Integer> arr = new ArrayList<>();
		while (k > 0) {
			arr.add((int)k%2);
			k /= 2;
		}
		ArrayList<Integer> ret = new ArrayList<>();
		for (int i = 0; i < arr.size(); i++) {
			if (arr.get(i) == 1) {
				ret.add(i);
			}
		}
		return ret;
	}
}
