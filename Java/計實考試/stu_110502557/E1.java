package stu_110502557;

import java.util.Scanner;

public class E1 {
    
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        String input;
        String[] inputArray;
        Date begin, end;

        while (true) {

            input = scanner.nextLine();
            if (input.equals("0")) break;
            inputArray = input.split(" ");
            begin = new Date(
                Integer.parseInt(inputArray[2]),
                monthStrToInt(inputArray[0]),
                Integer.parseInt(inputArray[1].substring(0, inputArray[2].length() - 2))
            );
            input = scanner.nextLine();
            inputArray = input.split(" ");
            end = new Date(
                Integer.parseInt(inputArray[2]),
                monthStrToInt(inputArray[0]),
                Integer.parseInt(inputArray[1].substring(0, inputArray[2].length() - 2))
            );

            int beginYear = begin.getYear() + (begin.getMonth() > 2 ? 1 : 0);
            int endYear = end.getYear() - (end.getMonth() <= 2 && end.getDay() < 29 ? 1 : 0);
            int count = 0;
            for (int currYear = beginYear; currYear <= endYear; currYear ++) {
                if (isLeap(currYear)) count ++;
            }
            System.out.println(count);
        }
    }

    public static int monthStrToInt(String str) {
        if (str.equals("January")) return 1;
        if (str.equals("February")) return 2;
        if (str.equals("March")) return 3;
        if (str.equals("April")) return 4;
        if (str.equals("May")) return 5;
        if (str.equals("June")) return 6;
        if (str.equals("July")) return 7;
        if (str.equals("August")) return 8;
        if (str.equals("September")) return 9;
        if (str.equals("October")) return 10;
        if (str.equals("November")) return 11;
        if (str.equals("December")) return 12;
        else return -1;
    }

    public static boolean isLeap(int year) {
        if (year % 400 == 0) return true;
        if (year % 100 == 0) return false;
        if (year % 4 == 0) return true;
        return false;
    }
}


class Date {

    private int y;
    private int m;
    private int d;

    public Date(int y, int m, int d) {
        this.y = y;
        this.m = m;
        this.d = d;
    }

    public int getYear() { return y; }
    public int getMonth() { return m; }
    public int getDay() { return d; }
}
