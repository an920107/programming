package stu_110502557;

import java.util.Scanner;

public class E1 {
    private static Scanner scanner = new Scanner(System.in);
    
    public static void main(String[] args) {
        String command, name;
        int amount, price, id;
        Good[] goodsCart = new Good[9];
        while (true) {
            System.out.println("選擇一指令：");
            System.out.println("[add]\t添加商品");
            System.out.println("[query]\t查詢購物車商品");
            System.out.println("[update]修改商品數量");
            System.out.println("[pay]\t結算金額");
            System.out.println("[exit]\t離開");
            command = scanner.next();
            if (command.equals("add")) {
                System.out.println("請輸入商品編號：");
                id = scanner.nextInt();
                System.out.println("請輸入商品名稱：");
                name = scanner.next();
                System.out.println("請輸入商品價格：");
                price = scanner.nextInt();
                System.out.println("請輸入商品數量：");
                amount = scanner.nextInt();
                goodsCart[id - 1] = new Good(name, price, amount);
                System.out.println("您的商品 " + name + "已添加到購物車");
            }
            else if (command.equals("query"))
                query(goodsCart);
            else if (command.equals("update")) {
                System.out.println("請輸入需要修改的商品編號：");
                id = scanner.nextInt();
                if (goodsCart[id - 1] == null) {
                    System.out.println("無此商品");
                    continue;
                }
                System.out.println("請輸入商品 " + goodsCart[id - 1].getName() + " 的修改數量：");
                amount = scanner.nextInt();
                goodsCart[id - 1].setAmount(amount);
                System.out.println("修改完成");
            }
            else if (command.equals("pay"))
                System.out.println("訂單總金額 " + query(goodsCart));
            else if (command.equals("exit"))
                break;
            else System.out.println("沒有該功能：");
        }
    }

    private static int query(Good[] cart) {
        int sum = 0;
        System.out.println("==============購物車內容如下==============");
        System.out.printf("%-6s%-10s%-6s%-6s\n", "編號", "名稱", "價格", "數量");
        for (int i = 0; i < 9; i ++) {
            if (cart[i] == null) continue;
            System.out.printf("%-8d%-12s%-8d%-8d\n", i + 1, cart[i].getName(), cart[i].getPrice(), cart[i].getAmount());
            sum += cart[i].getPrice() * cart[i].getAmount();
        }
        return sum;
    }
}

class Good {
    
    private String name;
    private int price;
    private int amount;

    public Good(String name, int price, int amount) {
        this.name = name;
        this.price = price;
        this.amount = amount;
    }
    
    public String getName() { return name; }
    public int getPrice() { return price; }
    public int getAmount() { return amount; }
    public void setAmount(int amount) { this.amount = amount; }
    
}