import java.util.*;
import java.io.*;

public class twoBrackets {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());

		/* Program: */

		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			LinkedList<Character> s = new LinkedList<>();
			int n = str.length();
			int leftBrackets = 0;
			int rightBrackets = 0;
			int leftParentheses = 0;
			int rightParentheses = 0;
			for (int j = 0; j < n; j++) {
				if (str.charAt(j) == '[') 
					leftBrackets++;
				if (str.charAt(j) == ']')
					rightBrackets++;
				if (str.charAt(j) == '(')
					leftParentheses++;
				if (str.charAt(j) == ')')
					rightParentheses++;
				s.add(str.charAt(j));
			}
			int pairs = 0;
			int leftBracket = 0;
			for (Character word : s) {
				if (word == '[') {
					leftBracket++;
				}
				else if (word == ']') {
					if (leftBracket > 0) {
						pairs++;
						leftBracket--;
					}
				}
			}
			int leftParenthese = 0;
			for (Character word : s) {
				if (word == '(') {
					leftParenthese++;
				}
				else if (word == ')') {
					if (leftParenthese > 0) {
						pairs++;
						leftParenthese--;
					}
				}
			}
			pw.println(pairs);

		}

		pw.close();
		br.close();
	}
}
