/*
ID: azh248
LANG: JAVA
TASK: highcard
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class highcard {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("highcard.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("highcard.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        ArrayList<Integer> elsieCards = new ArrayList<>(); 
        HashSet<Integer> inElsie = new HashSet<>();
        ArrayList<Integer> bessieCards = new ArrayList<>();

        /* Program: always go for the smallest possible card that beats elsie's,
        if there is none, then play the smallest card. Find the smallest possible
        card that beats elsie's by using bsearch. */

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            elsieCards.add(Integer.parseInt(st.nextToken()));
            inElsie.add(elsieCards.get(i));
        }
        for (int i = 1; i <= 2*n; i ++) {
            if (!inElsie.contains(i)) {
                bessieCards.add(i);
            }
        }
        Collections.sort(elsieCards);

        int points = 0;

        for (int i = 0; i < elsieCards.size(); i ++) {
            int elsieCard = elsieCards.get(i);
            int tempPoints = points;
            int last = bessieCards.size() - 1;
            int first = 0;
            int mid = (first + last) / 2;
            if (bessieCards.get(0) > elsieCard) {
                bessieCards.remove(0);
                points ++;
            } else {
                while (first <= last) {
                    if (bessieCards.get(mid) < elsieCard) {
                        first = mid + 1;
                    } else if (bessieCards.get(mid) > elsieCard && bessieCards.get(mid - 1) < elsieCard) {
                        points ++;
                        bessieCards.remove(mid);
                        break;
                    } else {
                        last = mid - 1;
                    }
                    mid = (first + last) / 2;
                }
                if (tempPoints == points) {
                    bessieCards.remove(0);
                }
            }
        }

        pw.println(points);

        /**
         * What to watch out for: == doesn't work for equality for reference types
         * setting one variable equal to another makes it so that variable changes when
         * the original one does, to get around this use "new" start using ? in an if
         * else statement, put the else directly after the closing bracket you might
         * have to use larger data types --> for silver and above problems test cases
         * are huge when needing to find the max in an array, just use max =
         * Math.max(max, nextInt) check if the loops are in the right order (if each cow
         * has 3 amounts of milk, going through the amounts of milk first, then the cow
         * would be incorrect) try to break asap when tle, instead of using if (!x) ___,
         * use if (x) break; else ___ try to avoid unnecessary nested loops when setting
         * arraylists of arrays/arraylists equal to each other, make sure to clone the
         * arrays AT EVERY POINT THEY'RE IN CONTACT
         */

        br.close();
        pw.close();
    }
}
