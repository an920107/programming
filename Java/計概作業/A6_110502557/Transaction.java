package A6_110502557;

public class Transaction {
    private String name = null;
    private int income = 0;
    private int pay = 0;

    public Transaction(String name, int income, int pay) {
        this.name = name;
        this.income = income;
        this.pay = pay;
    }
    
    public String getName() { return name; }
    public int getIncome() { return income; }
    public int getPay() { return pay; }
}
