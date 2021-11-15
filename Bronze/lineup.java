
/*
ID: azh248
LANG: JAVA
TASK: lineup
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class lineup {

    
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("lineup.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("lineup.out"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        // reads input, cowCondition1 is the list of first cows, cowCondition2 is the list of second cows
        
        int N = Integer.parseInt(st.nextToken());
        ArrayList<String> cowCondition1 = new ArrayList<>();
        ArrayList<String> cowCondition2 = new ArrayList<>();
        
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            cowCondition1.add(st.nextToken());
            st.nextToken();
            st.nextToken();
            st.nextToken();
            st.nextToken();
            cowCondition2.add(st.nextToken());
        }

        /* goes through all possible permutations (8! total) and adds them to a common arraylist of string arraylists. 
        does this by going through 8 loops, and for each loop combination, reset the names1 arraylist to the names array, 
        then remove the index a, b, c, ..... and add the ordering */

        ArrayList<String> names1 = new ArrayList<>();
        ArrayList<ArrayList<String>> allOrderings = new ArrayList<>();
        String[] names = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

        for (int a = 0; a < 8; a ++) {
            for (int b = 0; b < 7; b++) {
                for (int c = 0; c < 6; c++) {
                    for (int d = 0; d < 5; d++) {
                        for (int e = 0; e < 4; e++) {
                            for (int f = 0; f < 3; f++) {
                                for (int g = 0; g < 2; g++) {
                                    for (int h = 0; h < 1; h++) {
                                        names1 = new ArrayList<>();
                                        for (String i : names) {
                                            names1.add(i);
                                        }
                                        ArrayList<String> ordering = new ArrayList<>();
                                        ordering.add(names1.get(a)); 
                                        names1.remove(names1.get(a));
                                        ordering.add(names1.get(b));
                                        names1.remove(names1.get(b));
                                        ordering.add(names1.get(c));
                                        names1.remove(names1.get(c));
                                        ordering.add(names1.get(d));
                                        names1.remove(names1.get(d));
                                        ordering.add(names1.get(e));
                                        names1.remove(names1.get(e));
                                        ordering.add(names1.get(f));
                                        names1.remove(names1.get(f));
                                        ordering.add(names1.get(g));
                                        names1.remove(names1.get(g));
                                        ordering.add(names1.get(h));
                                        names1.remove(names1.get(h));
                                        allOrderings.add(ordering);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        

        /* creates an arraylist of working orderings, iterates through all orderings, 
        and if all of the constraints are met, then the arraylist is added to workingorderings. 
        then, we find the alphabetically least one by using an alphabetically sorted arraylist of 
        the names and going through each index in each working ordering (0 to 7).  if the index of the name
        in the alphabetically sorted arraylist is greater than the smallest index in the working orderings, 
        it is added to a queue to be removed because that means it's alphabetically after the lowest one. 
        the queue is to prevent removing while it's still iterating. at the end of every
        working ordering index (0 to 7), we eliminate all elements in the queue. this leaves us with one
        last arraylist in workingorderings, the alphabetically least one satisfying all constriants. */

        
        ArrayList<ArrayList<String>> workingOrderings = new ArrayList<>();


        for (ArrayList<String> x : allOrderings) {
            boolean add = true;
            for (int i = 0; i < cowCondition1.size(); i++) {
                if (x.indexOf(cowCondition1.get(i)) - x.indexOf(cowCondition2.get(i)) == 1 || x.indexOf(cowCondition2.get(i)) - x.indexOf(cowCondition1.get(i)) == 1) {
                    continue;
                }      
                else {
                    add = false;
                }     
            }
            if (add == true) {
                workingOrderings.add(x);
            }
        } 
        
        String[] arrayToArraylist = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
        ArrayList<String> namesAlphabetically = new ArrayList<>();
        for (String i : arrayToArraylist) {
            namesAlphabetically.add(i);
        }
        int max = 0;
        ArrayList<ArrayList<String>> arrayListsToRemove = new ArrayList<>();

        for (int x = 0; x < 8; x ++) { 
            max = 7;
            for (ArrayList<String> i : workingOrderings) {
                if (namesAlphabetically.indexOf(i.get(x)) < max) {
                    max = namesAlphabetically.indexOf(i.get(x));
                }
            }
            for (ArrayList<String> i : workingOrderings) {
                if (namesAlphabetically.indexOf(i.get(x)) > max) {
                    arrayListsToRemove.add(i);
                }
            }
            for (ArrayList<String> j : arrayListsToRemove) {
                workingOrderings.remove(j);
            }
        }
        
        for (ArrayList<String> i : workingOrderings) {
            for (String j : i) {
                pw.println(j);
            }
        }        


        pw.close();
        br.close();
    }

}
