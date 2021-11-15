import java.util.*;
import java.io.*;

public class banquet {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        /* Program: have a queue of the tables that need to be filled up */

        long totalTime = 0;
        Queue<Integer> plateStacks = new LinkedList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int times = Integer.parseInt(st.nextToken());
            for (int j = 0; j < times; j++) {
                plateStacks.offer(i);
            }
        }
        for (int i = 0; i < n; i++) {
            int plateNeeded = plateStacks.poll();
            totalTime += Math.abs(plateNeeded - i);
        }
        pw.println(totalTime);

        pw.close();
    }
}
