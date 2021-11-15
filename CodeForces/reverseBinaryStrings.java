import java.util.*;
import java.io.*;

public class reverseBinaryStrings {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        /* Program: */

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int len = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            String num = st.nextToken();
            char first = num.charAt(0);
            String result = Character.toString(first);
            for (int j = 0; j < len-1; j++) {
                int digit = (int)result.charAt(j);
                result += Integer.toString((digit + 1)%2);
            }
            int switches = 0;
            boolean currentlySwitching = false;
            for (int j = 0; j < len; j++) {
                if (currentlySwitching) {
                    if (result.charAt(j) == num.charAt(j)) {
                        currentlySwitching = false;
                    }
                }
                else if (result.charAt(j) != num.charAt(j)) {
                    currentlySwitching = true;
                    switches++;
                }
            }
            System.out.println(switches);
        }

        pw.close();
        br.close();
    }

}
