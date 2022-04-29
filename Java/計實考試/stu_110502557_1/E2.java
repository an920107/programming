package stu_110502557_1;

import java.util.Scanner;

public class E2 {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int heigh;
        String str;
        while (true) {
            heigh = scanner.nextInt();
            if (heigh < 3) break;
            str = scanner.next();
            for (int i = 0; i < heigh; i ++) {
                for (int j = 0; j < i; j ++) {
                    System.out.print(" ");
                }
                for (int j = (heigh - i) * 2; j > 0; j --) {
                    System.out.print(str.charAt((i % 2 == 0) ? 0 : 1));
                }
                System.out.println();
            }
        }
    }
}
