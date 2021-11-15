import java.util.*;
import java.io.*;

public class numberIntoSequence {

	static long[] primeCount = new long[100000];
	static long maxPrime = 0;
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());

		/* Program: find maximum prime, have the sequence just be that prime except the last term is that prime * the rest of the stuff */

		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			primeCount = new long[100000];
			long n = Long.parseLong(st.nextToken());
			factorize(n);
			long maxPrimeCount = -1l;
			long maxPrimeCountIndex = -1l;
			for (int j = 0; j < maxPrime + 2; j++) {
				if (primeCount[j] > maxPrimeCount) {
					maxPrimeCount = primeCount[j];
					maxPrimeCountIndex = j;
				}
			}
			pw.println(Math.max(1, maxPrimeCount));
			for (long j = 0; j < maxPrimeCount - 1; j++) {
				pw.print(Long.toString(maxPrimeCountIndex) + " ");
			}
			if (maxPrimeCount > 1) pw.println((long)(n/(Math.pow(maxPrimeCountIndex, maxPrimeCount - 1))));
			else pw.println(n);
		}

		pw.close();
		br.close();
	}
	public static void factorize(long n) {
        for (long i = 2; i * i <= n; i++) {
            while (n % i == 0) {
				primeCount[(int)i]++;
				if (i > maxPrime) maxPrime = i;
                n /= i;
            }
        }
    }
}
