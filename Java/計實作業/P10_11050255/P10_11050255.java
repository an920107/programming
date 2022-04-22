/**
 * Practice 10
 * Student Number: 110502557
 * Course: 2022-CE1004-A
 */

package P10_11050255;

import java.util.ArrayList;
import java.util.Scanner;

public class P10_11050255 {
    
    private static Scanner scanner = new Scanner(System.in);
    private static final Drink[] DRINKS = {
        new Drink("Cola", 30),
        new Drink("Green Tea", 25),
        new Drink("Lemon Tea", 29),
        new Drink("Mineral Water", 20)
    };

    public static void main(String[] args) {
        String inputStr;
        ArrayList<Drink> drinkList = new ArrayList<>();
        
        while (true) {
            System.out.println("(1)choose drinks (2)list (3)pay (4)exit");
            inputStr = scanner.next();
            if (inputStr.equals("1")) {
                chooseDrinks(drinkList);
            } else if (inputStr.equals("2")) {
                listDrinks(drinkList);
            } else if (inputStr.equals("3")) {
                if (payDrinks(drinkList)) {
                    System.out.println("thank you");
                    break;
                }
            } else if (inputStr.equals("4")) {
                System.out.println("exit");
                break;
            } else System.out.println("invalid input");
        }
    }

    private static void chooseDrinks(ArrayList<Drink> drinkList) {
        System.out.println("choose drinks (drinks / amount)\n(1)Cola (2)Green Tea (3)Lemon Tea (4)Mineral Water");
        String drinks = scanner.next();
        String amount = scanner.next();
        int drinksInt, amountInt;
        try {
            drinksInt = Integer.parseInt(drinks);
            if (drinksInt < 1 || drinksInt > 4) {
                System.out.println("invalid input");
                return;
            }
        } catch (Exception e) {
            System.out.println("invalid input");
            return;
        }
        try {
            amountInt = Integer.parseInt(amount);
            if (amountInt < 1 || amountInt > 100)
                return;
        } catch (Exception e) {
            return;
        }
        drinksInt --;
        for (int i = 0; i < drinkList.size(); i ++) {
            if (drinkList.get(i).getName().equals(DRINKS[drinksInt].getName())) {
                drinkList.get(i).addAmount(amountInt);
                return;
            }
        }
        drinkList.add(DRINKS[drinksInt]);
        drinkList.get(drinkList.size() - 1).addAmount(amountInt);
    }

    private static void listDrinks(ArrayList<Drink> drinkList) {
        if (drinkList.isEmpty()) {
            System.out.println("Empty");
            return;
        }
        for (Drink drink : drinkList) {
            System.out.printf("%s %d\n", drink.getName(), drink.getAmount());
        }
    }

    private static boolean payDrinks(ArrayList<Drink> drinkList) {
        int sum = 0, payInt;
        for (Drink drink : drinkList) {
            sum += drink.getAmount() * drink.getPrice();
        }
        System.out.printf("total cost: %d\n", sum);
        System.out.print("please pay: ");
        String pay = scanner.next();
        try {
            payInt = Integer.parseInt(pay);
        } catch (Exception e) {
            return false;
        }
        if (payInt < sum) {
            System.out.println("money not enough");
            return false;
        }
        System.out.printf("money change: %d\n", payInt - sum);
        return true;
    }
}

class Drink {

    private String name;
    private int price;
    private int amount;

    public Drink(String name, int price) {
        this.name = name;
        this.price = price;
        amount = 0;
    }

    public String getName() { return name; }
    public int getPrice() { return price; }
    public int getAmount() { return amount; }
    public void addAmount() { amount ++; }
    public void addAmount(int adding) { amount += adding; }
}
