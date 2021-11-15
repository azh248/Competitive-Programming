/*
ID: azh248
LANG: JAVA
TASK: cardgame
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class cardgame {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("cardgame.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("cardgame.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        ArrayList<Integer> elsieCards = new ArrayList<>();
        HashSet<Integer> inElsie = new HashSet<>();
        ArrayList<Integer> bessieCards = new ArrayList<>();

        /* Program: divide bessie's cards in half --> the top half will be played in the first half of the round, 
        and the bottom half will be played in the second half. now, just use the silver algorithm on both halves of the round*/

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            elsieCards.add(Integer.parseInt(st.nextToken()));
            inElsie.add(elsieCards.get(i));
        }
        for (int i = 1; i <=2*n; i++) {
            if (!inElsie.contains(i)) {
                bessieCards.add(i);
            }
        }
        ArrayList<Integer> bessieSecondHalf = subArrayList(bessieCards, 0, n / 2);
        ArrayList<Integer> bessieFirstHalf = subArrayList(bessieCards, n / 2, n);
        ArrayList<Integer> elsieFirstHalf = subArrayList(elsieCards, 0, n / 2);
        ArrayList<Integer> elsieSecondHalf = subArrayList(elsieCards, n / 2, n);

        Collections.sort(elsieFirstHalf);
        Collections.sort(elsieSecondHalf);
        int points = 0;

        for (int i = 0; i < elsieFirstHalf.size(); i++) {
            int elsieCard = elsieFirstHalf.get(i);
            int tempPoints = points;
            int last = bessieFirstHalf.size() - 1;
            int first = 0;
            int mid = (first + last) / 2;
            if (bessieFirstHalf.get(0) > elsieCard) {
                bessieFirstHalf.remove(0);
                points++;
            } else {
                while (first <= last) {
                    if (bessieFirstHalf.get(mid) < elsieCard) {
                        first = mid + 1;
                    } else if (bessieFirstHalf.get(mid) > elsieCard && bessieFirstHalf.get(mid - 1) < elsieCard) {
                        points++;
                        bessieFirstHalf.remove(mid);
                        break;
                    } else {
                        last = mid - 1;
                    }
                    mid = (first + last) / 2;
                }
                if (tempPoints == points) {
                    bessieFirstHalf.remove(0);
                }
            }
        }
        for (int i = 0; i < elsieSecondHalf.size(); i++) {
            int elsieCard = elsieSecondHalf.get(i);
            int tempPoints = points;
            int last = bessieSecondHalf.size() - 1;
            int first = 0;
            int mid = (first + last) / 2;
            if (bessieSecondHalf.get(0) < elsieCard) {
                bessieSecondHalf.remove(0);
                points++;
            } else {
                while (first <= last) {
                    if (bessieSecondHalf.get(mid) > elsieCard) {
                        first = mid + 1;
                    } else if (bessieSecondHalf.get(mid) < elsieCard && bessieSecondHalf.get(mid - 1) > elsieCard) {
                        points++;
                        bessieSecondHalf.remove(mid);
                        break;
                    } else {
                        last = mid - 1;
                    }
                    mid = (first + last) / 2;
                }
                if (tempPoints == points) {
                    bessieSecondHalf.remove(bessieSecondHalf.size() - 1);
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
    public static ArrayList<Integer> subArrayList(ArrayList<Integer> arr, int start, int end) {
        ArrayList<Integer> ret = new ArrayList<>();
        for (int i = start; i < end; i ++) {
            ret.add(arr.get(i));
        }
        return ret;
    }
}
