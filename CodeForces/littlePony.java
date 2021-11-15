import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class littlePony {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        ArrayList<Integer> arr = new ArrayList<>();
        ArrayList<Integer> desiredArr = new ArrayList<>();

        /* Program: */
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            int token = Integer.parseInt(st.nextToken());
            arr.add(token);
            desiredArr.add(token);
        }
        int count = 0;

        Collections.sort(desiredArr);

        if (arr.equals(desiredArr)) {
            pw.println(0);
        } else {
            int index = arr.indexOf(desiredArr.get(0));
            int whileLooped = 0;
            while (arr.get(n - 1) != desiredArr.get((n - index - 1) % n) && whileLooped < n) {
                index = (index + 1) % n;
                whileLooped ++;
            }
            if (whileLooped == n - 1) {
                pw.println(-1);
                pw.close();
                return;
            }
            for (int i = 0; i < n; i++) {
                if (!(desiredArr.get(i) == arr.get((i + index) % n))) {
                    count++;
                }
            }
            if (count > 1) {
                pw.println(-1);
            } else {
                pw.println(n - index);
            }
        }

        pw.close();
        br.close();
    }

}
