import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class sisBuilding {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        /* Program: */

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int ta = Integer.parseInt(st.nextToken());
            int fa = Integer.parseInt(st.nextToken());
            int tb = Integer.parseInt(st.nextToken());
            int fb = Integer.parseInt(st.nextToken());
            int travelToTowerB = 0;
            int floorTravel = 0;

            if (ta == tb) {
                pw.println(Math.abs(fa - fb));
                continue;
            }
            if (fa > b) {
                travelToTowerB = fa - b + Math.abs(ta - tb);
                floorTravel = b;
            } else if (fa < a) {
                travelToTowerB = a - fa + Math.abs(ta - tb);
                floorTravel = a;
            } else {
                travelToTowerB = Math.abs(ta - tb);
                floorTravel = fa;
            }
            pw.println(travelToTowerB + Math.abs(fb - floorTravel));
        }

        pw.close();
        br.close();
    }

}
