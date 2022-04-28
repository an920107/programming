/**
 * Assignment 10-1
 * Student Number: 110502557
 * Course: 2022-CE1004-A
 */

package A10_110502557_1;

import java.util.Scanner;

public class A10_1105025577_1 {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        while (true) {
            System.out.println("請輸入整數：");
            String strA = scanner.next();
            String strB = scanner.next();
            double res;
            try {
                res = div(strA, strB);
            }
            catch (ArithmeticException exception) {
                System.out.println(exception.getMessage());
                continue;
            }
            System.out.println(res);
            break;
        }
    }

    private static double div(String strA, String strB) {
        int intA, intB;
        try {
            intA = Integer.parseInt(strA);
            intB = Integer.parseInt(strB);
        }
        catch (Exception exception) {
            throw new ArithmeticException("輸入為非整數");
        }
        if (intA < 0 || intB < 0)
            throw new ArithmeticException("分子或分母為負數了！");
        if (intB == 0)
            throw new ArithmeticException("分母不能為 0");
        return (double)intA / (double)intB;
    }
}
