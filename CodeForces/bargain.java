import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class bargain {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        long n = Long.parseLong(st.nextToken());
        long m = n;

        /* Program: */

        ArrayList<Long> set = new ArrayList<>();

        long length = Long.toString(n).length();

        for (long i = 0; i < length; i++) {
            long num = (long) n%10;
            n -= num;
            n /= 10;
            set.add(num);
        }
        long totalSum = 0;
        Collections.reverse(set);

        // subsets

        for (long i = 0; i < (1 << set.size()); i++) {
            ArrayList<Long> sum = new ArrayList<>();
            for (long j = 0; j < set.size(); j++) {
                if ((i & (1 << j)) > 0) {
                    sum.add(set.get((int)j));
                }
            }
            for (long j = 0; j < sum.size(); j++) {
                totalSum += sum.get((int)j) * Math.pow(10, sum.size() - 1 - j);
            }
        }
        pw.println((int)((totalSum - m) % (Math.pow(10, 9) + 7)));

        pw.close();
        br.close();
    }

}
