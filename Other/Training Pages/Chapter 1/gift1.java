/*
ID: azh248
LANG: JAVA
TASK: gift1
*/

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class gift1 {

  public static void main(String[] args) throws IOException {

    Scanner br = new Scanner(new FileReader("gift1.in"));
    PrintWriter pw = new PrintWriter(new FileWriter("gift1.out"));

    int numberOfPeople = br.nextInt();
    br.nextLine();
    System.out.println(numberOfPeople);
    ArrayList<String> people = new ArrayList<>();
    for (int i = 0; i < numberOfPeople; i ++) {
      people.add(br.nextLine());
    }
    ArrayList<Integer> balances = new ArrayList<>();
    for (String n : people) {
      balances.add((Integer)0);
    }
    System.out.println(people);
    for (int i = 0; i < numberOfPeople; i++) {
      String name = br.nextLine();
      int index = people.indexOf(name);
      int money = br.nextInt();
      int numberOfSplits = br.nextInt();
      br.nextLine();
      if (numberOfSplits == 0) {
      }
      else {
      Integer splitMoneyPerPerson = (money - money%numberOfSplits)/numberOfSplits;
      balances.set(index, balances.get(index)-1*numberOfSplits*splitMoneyPerPerson);
      System.out.println(money);
      System.out.println(balances);

      for (int x = 0; x < numberOfSplits; x ++) {
        String receiver =  br.nextLine();
        Integer totalReceivedMoney = balances.get(people.indexOf(receiver)) + splitMoneyPerPerson;
        balances.set(people.indexOf(receiver), totalReceivedMoney);


      }
    }
    }
    for (String person : people) {
      pw.println(person + " " + balances.get(people.indexOf(person)));
    }



    pw.close();
  }

}
