/**
 * Assignment 02
 * Student Number: 110502557
 * Course: 2022-CE1002
 */

import java.util.Scanner;

public class A2_110502557 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int n = Integer.parseInt(scanner.nextLine());
        String tmpStr = scanner.nextLine();
        final char outChar = tmpStr.charAt(0);
        final char inChar = tmpStr.charAt(1);
        for (int i = 0; i < n - 1; i ++) {
            for (int j = n - i - 1; j > 0; j --) {
                System.out.print(" ");
            }
            System.out.print(outChar);
            for (int j = i * 2; j > 0; j --) {
                System.out.print(inChar);
            }
            System.out.println(outChar);
        }
        for (int i = n * 2; i > 0; i --) {
            System.out.print(outChar);
        }
        System.out.println();
        scanner.close();
    }
}
