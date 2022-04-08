/**
 * Practice 06
 * Student Number: 110502557
 * Course: 2022-CE1004-A
 */

package P6_110502557;

import java.util.LinkedList;
import java.util.Scanner;

public class P6_110502557 {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        LinkedList<String> bookshelf = new LinkedList<>();
        String cmd;
        String[] cmdParts;
        while (true) {
            cmd = scanner.nextLine();
            if (cmd.equals("exit"))
                break;

            cmdParts = cmd.split(" ");
            if (cmdParts[0].equals("1"))
                bookshelf.add(Integer.parseInt(cmdParts[1]) - 1, cmdParts[2]);
            else bookshelf.remove(Integer.parseInt(cmdParts[1]) - 1);
        }
        System.out.println(bookshelf);
    }
}