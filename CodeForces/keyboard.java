import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class keyboard {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter pw = new PrintWriter(System.out);

        String keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";

        String direction = sc.nextLine();
        String input = sc.nextLine();

        boolean direc;
        if (direction.equals("R")) {
            direc = true;
        } else {
            direc = false;
        }
        String endString = "";

        for (int i = 0; i < input.length(); i++) {
            if (direc == false) {
                if (keyboard.indexOf(Character.toString(input.charAt(i))) + 1 == 0%10) {
                    endString += keyboard.charAt(keyboard.indexOf(Character.toString(input.charAt(i))));
                } else {
                    endString += keyboard.charAt(keyboard.indexOf(Character.toString(input.charAt(i))) + 1);
                }
            } else {
                if (keyboard.indexOf(Character.toString(input.charAt(i))) == 0%10) {
                    endString += keyboard.charAt(keyboard.indexOf(Character.toString(input.charAt(i))));
                } else {
                    endString += keyboard.charAt(keyboard.indexOf(Character.toString(input.charAt(i))) - 1);
                }
            }
        }
        pw.println(endString);

        pw.close();
        sc.close();
    }

}
