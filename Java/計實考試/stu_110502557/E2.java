package stu_110502557;

import java.util.Scanner;

public class E2 {

    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        int m, n, k;
        boolean[][] matrix;
        boolean[][] newMatrix;
        
        while (true) {
            m = scanner.nextInt();
            if (m == 0) break;
            n = scanner.nextInt();
            k = scanner.nextInt();

            matrix = new boolean[m + 2][n + 2];
            newMatrix = new boolean[m + 2][n + 2];
            
            for (int i = 0; i < m + 2; i ++)
                for (int j = 0; j < n + 2; j ++)
                    matrix[i][j] = false;
            for (int i = 1; i < m + 1; i ++) {
                String line = scanner.next();
                for (int j = 1; j < n + 1; j ++) {
                    matrix[i][j] = line.charAt(j - 1) == '1';
                }
            }

            for ( ; k > 0; k --) {
                for (int i = 1; i < m + 1; i ++) {
                    for (int j = 1; j < n + 1; j ++) {
                        if (matrix[i][j]) {
                            if (countAround(matrix, i, j) < 2)
                                newMatrix[i][j] = false;
                            else if (countAround(matrix, i, j) > 3)
                                newMatrix[i][j] = false;
                            else newMatrix[i][j] = true;
                        }
                        else if (countAround(matrix, i, j) == 3)
                            newMatrix[i][j] = true;
                        else newMatrix[i][j] = false;
                    }
                }
                for (int i = 1; i < m + 1; i ++)
                    for (int j = 1; j < n + 1; j ++) 
                        matrix[i][j] = newMatrix[i][j];
            }

            for (int i = 1; i < m + 1; i ++) {
                for (int j = 1; j < n + 1; j ++) {
                    System.out.print(matrix[i][j] ? "1" : "0");
                }
                System.out.print("\n");
            }
        }
    }

    public static int countAround(boolean[][] matrix, int centerX, int centerY) {
        int count = 0;
        for (int x = -1; x <= 1; x ++) {
            for (int y = -1; y <= 1; y ++) {
                if (x == 0 && y == 0) continue;
                if (matrix[centerX + x][centerY + y])
                    count ++;
            }
        }
        return count;
    }
}
