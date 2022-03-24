/**
 * Assignment 06
 * Student Number: 110502557
 * Course: 2022-CE1002
 */

package A6_110502557;

import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);
    
    public static void main(String[] args) {
        boolean end = false;
        int command;
        Transactions transactions = new Transactions();
        do {
            command = scanner.nextInt();
            switch (command) {
                case 1:
                    transactions.addLast(new Transaction(scanner.next()));
                    transactions.setLastIncome(scanner.nextInt());
                    break;
                case 2:
                    transactions.addLast(new Transaction(scanner.next()));
                    transactions.setLastPay(scanner.nextInt());
                    break;
                case 3:
                    int total = 0;
                    String format = "%-" + transactions.getMaxNameLength() + "s  %-" + transactions.getMaxIncomeLength() + "d  %d\n";
                    for (Transaction obj : transactions) {
                        total += obj.getIncome() - obj.getPay();
                        System.out.printf(format, obj.getName(), obj.getIncome(), obj.getPay());
                    }
                    System.out.printf("Total: %d\n", total);
                    break;
                case 4:
                    end = true;
                    break;
                default:
                    System.out.println("Invalid Operation");
                    break;
            }
        } while (!end);
    }
}
