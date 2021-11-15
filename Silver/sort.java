/*
ID: azh248
LANG: JAVA
TASK: sort
*/

import java.util.*;
import java.io.*;

public class sort {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("sort.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("sort.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		int[] sortedArr = new int[n];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			sortedArr[i] = Integer.parseInt(st.nextToken());
		}
		arr = (int[]) sortedArr.clone();
		Arrays.sort(sortedArr);

		HashSet<Integer> used = new HashSet<>();
		
		for (int i = 0; i < arr.length; i++) {
			int index = Arrays.binarySearch(sortedArr, arr[i]);
			while (index != 0 && sortedArr[index - 1] == sortedArr[index]) {
				index--;
			}
			while (used.contains(index)) {
				index++;
			}
			used.add(index);
			arr[i] = index;
		}
		int maxDistance = 0; // find the max distance between an element and the place it's supposed to go
		for (int i = 0; i < arr.length; i++) {
			maxDistance = Math.max(maxDistance, Math.abs(i - arr[i]));
		}
		pw.println(maxDistance + 1);

		br.close();
		pw.close();
	}
}
