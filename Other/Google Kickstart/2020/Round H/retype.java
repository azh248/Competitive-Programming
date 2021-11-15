import java.util.*;
import java.io.*;

public class retype {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(st.nextToken());

        for (int i = 0; i < t; i++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken()); 
            int time = Math.min(n + 1, (k - s)*2 + n - k + 1);
            System.out.println("Case #" + Integer.toString(i + 1) + ": " + Integer.toString(time + k - 1));
        }

        br.close();
    }
}
