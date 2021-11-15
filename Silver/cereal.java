/*
ID: azh248
LANG: JAVA
TASK: cereal
*/

import java.util.*;
import java.io.*;

public class cereal {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new FileReader("cereal.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("cereal.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		int[][] cereals = new int[n + 1][2];
		int[] originalTaker = new int[m + 1]; 

		/* start with the last cow only --> there is 1 box total received in this case. then, slowly add 
		cows to the front of the line. for each cow, find the original recepient of its cereal box. If there
		is none, add 1 to the total boxes and repeat. Otherwise, look at the original recipient's 
		second choice (find the original recipient of that second choice --> if it's before this original recipient 
		in this line, then this recipient won't be able to get his box of cereal and the total # of boxes will stay
		the same. Otherwise, do the same thing for the new original recipient's second choice) */

		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			cereals[i][0] = Integer.parseInt(st.nextToken());
			cereals[i][1] = Integer.parseInt(st.nextToken());
		}
		originalTaker[cereals[n][0]] = n;
		ArrayList<Integer> allBoxesReceived = new ArrayList<>();
		int totalBoxesReceived = 1;
		allBoxesReceived.add(totalBoxesReceived);
		for (int i = n - 1; i >= 1; i--) {
			int newCereal = cereals[i][0];
			if (originalTaker[newCereal] == 0) {
				totalBoxesReceived++;
			} else {
				int origTaker = originalTaker[newCereal];
				while (true) {
					int originalsSecondChoice = cereals[origTaker][1]; // we added a cereal box that someone later in the line wanted, so now we want to try using their second choice
					if (originalsSecondChoice == newCereal) { // if the new cereal was already the original cow's second choice, and therefore they can't get anything because both their first and second choices are taken
						break;
					}
					// if their second choice also has a person who wanted it later in the line, we just repeat this
					if (originalTaker[originalsSecondChoice] == 0) {
						originalTaker[originalsSecondChoice] = origTaker;
						totalBoxesReceived++;
						break;
					} else {
						if (originalTaker[originalsSecondChoice] < origTaker) {
							// the cow who originally wanted this had higher priority so this new cow doesn't get it
							break;
						} else {
							int previousOrigTaker = origTaker;
							origTaker = originalTaker[originalsSecondChoice];
							originalTaker[originalsSecondChoice] = previousOrigTaker;
							newCereal = originalsSecondChoice;
						}
					}
				}
			}
			originalTaker[cereals[i][0]] = i;
			allBoxesReceived.add(totalBoxesReceived);
		}
		Collections.reverse(allBoxesReceived);
		for (int i : allBoxesReceived) {
			pw.println(i);
		}


		br.close();
		pw.close();
	}
}
