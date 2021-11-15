import java.util.*;
import java.io.*;

public class explorers {


    public static ArrayList<Integer> sail (int height, int width) {
        int[][] zheng = new int[height][width];
        int[][] yang = new int[height][width];

        // row 0 is the bottom row

        int zhengValue = 1;
        for (int i = 0 ; i < zheng.length; i++) {
            if ((i + 1) % 2 == 0) {
                // row is even, go left to right
                for (int j = 0; j < zheng[i].length; j++) {
                    zheng[i][j] = zhengValue;
                    zhengValue += 1;
                }
            } else {
                // row is odd, go right to left
                for (int j = zheng[i].length - 1; j >= 0; j--) {
                    zheng[i][j] = zhengValue;
                    zhengValue += 1;
                }
            }
        }
        int yangValue = 1;
        int column = 0; // this is an index
        for (int i = 0 ; i < width; i++) {
            if ((i + 1) % 2 == 0) {
                // column is even, go bottom to top
                for (int j = 0; j < height; j++) {
                    yang[j][column] = yangValue;
                    yangValue += 1;
                }
                column += 1;

            } else {
                // column is odd, go top to bottom
                for (int j = height - 1; j >= 0; j--) {
                    yang[j][column] = yangValue;
                    yangValue += 1;
                }
                column += 1;
            }
            
        }

        ArrayList<Integer> ret = new ArrayList<>();
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (yang[i][j] == zheng[i][j]) ret.add(yang[i][j]);
            }
        }

        return ret;
    }

  public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);

    StringTokenizer st = new StringTokenizer(br.readLine());

    int height = Integer.parseInt(st.nextToken());
    int width = Integer.parseInt(st.nextToken());

    ArrayList<Integer> prints = sail(height, width);

    Collections.sort(prints);

    System.out.println(prints.size());
    for (int i = 0; i < prints.size(); i++) {
        System.out.print(Integer.toString(prints.get(i)) + " ");
    }
    System.out.println();

    pw.close();
  }

}
