import java.util.*;
import java.io.*;

public class exponentiation {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        /* Program: */

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            long result = modpower(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), 1000000007);
            pw.println(result);
        }

        pw.close();
        br.close();
    }
    
    public static long modpower(int x, int n, int m) {
        if (n == 0)
            return 1 % m;
        long u = modpower(x, n / 2, m);
        u = (u * u) % m;
        if (n % 2 == 1)
            u = (u * x) % m;
        return u;
    }
}