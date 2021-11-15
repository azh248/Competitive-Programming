import java.util.*;
import java.io.*;

public class atmQueue {

  public static void main(String[] args) throws IOException {

    BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);

    StringTokenizer st = new StringTokenizer(sc.readLine());

    int t = Integer.parseInt(st.nextToken());

    for (int i = 0; i < t; i++) {
        st = new StringTokenizer(sc.readLine());
        pw.print("Case #" + (i + 1) + ": ");
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        Queue<Integer> atmQueue = new LinkedList<Integer>();
        Queue<Integer> atmPeople = new LinkedList<Integer>();
        st = new StringTokenizer(sc.readLine());
        int min = 1000000001;
        int queueSize = 0;
        for (int j = 0; j < n; j++) {
            int num = Integer.parseInt(st.nextToken());
            if (num > x) {
                atmPeople.add(j);
                atmQueue.add(num);
                if (num < min) {
                    min = num;
                }
                queueSize ++;
            } else {
                pw.print((j + 1) + " ");
            }
        }
        if (atmQueue.isEmpty()) {
            pw.println();
            continue;
        } else {
            if (min > x) {
                int subtract = (int)(((double)min - min%x)/((double)x));
                for (int w = 0; w < queueSize; w ++) {
                    int person = atmQueue.poll();
                    int add = person - (subtract*x);
                    atmQueue.add(add);
                }
            }
            while (!atmQueue.isEmpty()) {
                int nextPerson = atmQueue.poll();
                int nextPersonNumber = atmPeople.poll();
                if (nextPerson <= x) {
                    if (!atmQueue.isEmpty()) {
                        pw.print((nextPersonNumber + 1) + " ");
                    } else {
                        pw.print((nextPersonNumber + 1));
                        pw.println();
                    }
                } else {
                    if (!atmQueue.isEmpty()) {
                        atmQueue.add(nextPerson - x);
                        atmPeople.add(nextPersonNumber);
                    } else {
                        pw.print(nextPersonNumber + 1);
                        pw.println();
                    }
                }
            }
        }
    }
    pw.close();
    sc.close();
  }
}
