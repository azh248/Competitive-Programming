import java.util.*;
import java.io.*;

public class newTechnique {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(st.nextToken());

        /* Program: */

        for (int i = 0; i < t; i++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int[][] arr1 = new int[n][m];
            int[][] arr2 = new int[m][n];
            for (int j = 0; j < n; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < m; k++) {
                    arr1[j][k] = Integer.parseInt(st.nextToken());
                }
            }
            for (int j = 0; j < m; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < n; k++) {
                    arr2[j][k] = Integer.parseInt(st.nextToken());
                }
            }
            for (int j = 0; j < n; j++) {
                int column = ArraySearch(arr1, arr2[0][j], n, m);
                sortByColumn(arr1, column);
                int[] arr1D = new int[n];
                for (int k = 0; k < n; k++) {
                    arr1D[k] = arr1[k][column];
                }
                int index = Arrays.binarySearch(arr1D, arr2[0][j]);
                String str = Arrays.toString(arr1[(index + 200*n)%n]);
                str = str.substring(1, str.length() - 1);
                str = str.replace(",", "");
                System.out.println(str);
            }
        }

        pw.close();
        br.close();
    }
    public static void sortByColumn(int arr[][], int col) {
        Arrays.sort(arr, new Comparator<int[]>() {
            public int compare(final int[] entry1, final int[] entry2) {
                if (entry1[col] > entry2[col])
                    return 1;
                else
                    return -1;
            }
        }
        );
    }
    public static int ArraySearch(int[][] arr, int entry, int n, int m) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (arr[j][k] == entry) {
                    return k;
                }
            }
        }
        return -1;
    }
}
